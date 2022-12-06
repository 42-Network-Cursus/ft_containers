#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "Node.hpp"
# include "../iterator/Bidirectional_iterator.hpp"
# include "../iterator/reverse_iterator.hpp"

# include <iostream>

namespace ft
{
	template<	typename Key,
				typename Value,
				typename Compare,
				typename Alloc
			>
	class Red_black_tree
	{
		public:
			typedef Key												key_type;
			typedef Value											value_type;

			typedef	Compare											key_compare;
			typedef Alloc											allocator_type;
			
			typedef size_t 											size_type;
			typedef ptrdiff_t difference_type;
			
			typedef	typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			
			typedef ft::Bidirectional_iterator<Key, Value>				iterator;
			typedef ft::Bidirectional_iterator<Key, Value, true>		const_iterator;
			typedef ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			
			typedef Node<Key, Value>									node_type;

		// CONSTRUCTOR -------------------------------------------------------------------------------------------------------
		public:
			Red_black_tree (const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) 
			: _comp(comp), _valueAlloc(alloc), _size(0), _capacity(0) 
			{
				_header = allocNode();
				_header->colour = RED;
				_header->parent = NULL;
				_header->l_child = _header;
				_header->r_child = _header;
			}
		// DESTRUCTOR --------------------------------------------------------------------------------------------------------
		public:
			~Red_black_tree () {}
		// -------------------------------------------------------------------------------------------------------------------
		// NODE ALLOCATION ---------------------------------------------------------------------------------------------------
		private:
			node_type	*allocNode()	{ return _nodeAlloc.allocate(1); }

			void	deallocNode(node_type	*node)	
			{
				_nodeAlloc.deallocate(node, 1); 
			}

			node_type	*createNode (const value_type& val)
			{
				node_type	*tmp = allocNode();
				_valueAlloc.construct(&(tmp->value), val);
				return tmp;
			}

			void	destroyNode (node_type	*node)
			{
				_valueAlloc.destroy(&(node->value) );
				deallocNode(node);
			}
		// -------------------------------------------------------------------------------------------------------------------
		// CAPACITY
		public:
			bool 			empty()			const	{ return (_size == 0); } 
			size_type 		size()			const	{ return (_size); }
			size_type 		max_size()		const	{ return (_nodeAlloc.max_size() ); }
			allocator_type 	get_allocator() const 	{ return (_valueAlloc ); }
		// -------------------------------------------------------------------------------------------------------------------
		// MODIFIERS ---------------------------------------------------------------------------------------------------------
		private:
			void	rotateLeft (node_type *node, node_type *root)
			{
				node_type *tmp = node->r_child;

				node->r_child = tmp->l_child;
				if (tmp->l_child)
					tmp->l_child->parent = node;
				tmp->parent = node->parent;
				if (node == root)
				{
					root = tmp;
					_header->parent = root;
				}
				else if (node == node->parent->l_child)
					node->parent->l_child = tmp;
				else
					node->parent->r_child = tmp;
				tmp->l_child = node;
				node->parent = tmp;
			}

			void	rotateRight (node_type *node, node_type *root)
			{
				node_type *tmp = node->l_child;

				node->l_child = tmp->r_child;
				if (tmp->r_child)
					tmp->r_child->parent = node;
				tmp->parent = node->parent;

				if (node == root)
				{
					root = tmp;
					_header->parent = root;
				}
				else if (node == node->parent->r_child)
					node->parent->r_child = tmp;
				else
					node->parent->l_child = tmp;
				tmp->r_child = node;
				node->parent = tmp;
			}
		// -------------------------------------------------------------------------------------------------------------------
		// ---------- INSERTION ----------------------------------------------------------------------------------------------
		//--------------------- MAP VARIATION --------------------------------------------------------------------------------
		public:
			ft::pair<iterator, bool>	insert (const value_type& val)
			{
				node_type	*tmp = getRoot();
				node_type	*tmp_parent = _header;
				bool		compareResult = true;
				
				while (tmp)
				{
					tmp_parent = tmp;
					compareResult = _comp(val.first, getKeyOf(tmp) );
					if (compareResult)
						tmp = getLeftChildOf(tmp);					
					else
						tmp = getRightChildOf(tmp);
				}

				iterator it = iterator(tmp_parent);
				if (compareResult)
				{
					if (it == begin() )
						return (ft::pair<iterator, bool>(insertNode(tmp, tmp_parent, val), true));
					else
						--it;
				}
				if (_comp(it.getKey(), val.first) )
					return (ft::pair<iterator, bool>(insertNode(tmp, tmp_parent, val), true) );
				return (ft::pair<iterator, bool>(it, false) );
				
			}

			iterator insertHint(iterator position, const value_type& val)
			{
				if (position.getNode() == _header)
				{
					if (size() > 0 && _comp(getKeyOf(getRightMost()), val.first))
						return insertNode(NULL, getRightMost(), val);
					else
						return insert(val).first;
				}
				else if (_comp(val.first, getKeyOf(position.getNode())))
				{
					iterator prevPos = position;
					if (position.getNode() == getLeftMost())
						return insertNode(getLeftMost(), getLeftMost(), val);
					else if (_comp(getKeyOf((--prevPos).getNode()), val.first))
					{
						if (getRightChildOf(prevPos.getNode()) == 0)
							return insertNode(0, prevPos.getNode(), val);
						else
							return insertNode(position.getNode(), position.getNode(), val);
					}
					else
						return insert(val).first;
				}
				else if (_comp(getKeyOf(position.getNode()), val.first))
				{
					iterator nextPos = position;
					if (position.getNode() == getRightMost())
						return insertNode(0, getRightMost(), val);
					else if (_comp(val.first, getKeyOf((++nextPos).getNode())))
					{
						if (getRightChildOf(position.getNode()) == 0)
							return insertNode(0, position.getNode(), val);
						else
							return insertNode(nextPos.getNode(), nextPos.getNode(), val);
					}
					else
						return insert(val).first;
				}
				else
					return position;
			}

		private:
			iterator	insertNode (node_type *pos, node_type *pos_parent, const value_type& val)
			{
				node_type	*newNode;
				
				if (pos_parent == _header || pos || _comp(val.first, pos_parent->getKey()) )
				{
					newNode = createNode(val);
					getLeftChildOf(pos_parent) = newNode;
					if (pos_parent == _header)
					{
						getRoot() = newNode;
						getRightMost() = newNode;
					}
					else if (pos_parent == getLeftMost() )
						getLeftMost() = newNode;
				}
				else
				{
					newNode = createNode(val);
					getRightChildOf(pos_parent) = newNode;
					if (pos_parent == getRightMost() )
						getRightMost() = newNode;
				}
				getParentOf(newNode) 		= pos_parent;
				getLeftChildOf(newNode) 	= NULL;
				getRightChildOf(newNode) 	= NULL;
				insertFix(newNode, _header->parent);
				_size++;
				return iterator(newNode);
			}

			void	insertFix(node_type *newNode, node_type *root)
			{
				newNode->colour = RED;
				while (newNode != root && newNode->parent->colour == RED)
				{
					if (newNode->parent == newNode->parent->parent->l_child)
					{
						node_type	*newNode_uncle = newNode->parent->parent->r_child;
						if (newNode_uncle && newNode_uncle->colour == RED)
						{
							newNode->parent->colour = BLACK;
							newNode_uncle->colour = BLACK;
							newNode->parent->parent->colour = RED;
							newNode = newNode->parent->parent;
						}
						else
						{
							if (newNode == newNode->parent->r_child)
							{
								newNode = newNode->parent;
								rotateLeft(newNode, root);
							}
							newNode->parent->colour = BLACK;
							newNode->parent->parent->colour = RED;
							rotateRight(newNode->parent->parent, root);
						}
					}
					else
					{
						node_type	*newNode_uncle = newNode->parent->parent->l_child;
						if (newNode_uncle && newNode_uncle->colour == RED)
						{
							newNode->parent->colour = BLACK;
							newNode_uncle->colour = BLACK;
							newNode->parent->parent->colour = RED;
							newNode = newNode->parent->parent;
						}
						else
						{
							if (newNode == newNode->parent->l_child)
							{
								newNode = newNode->parent;
								rotateRight(newNode, root);
							}
							newNode->parent->colour = BLACK;
							newNode->parent->parent->colour = RED;
							rotateLeft(newNode->parent->parent, root);
						}
					}
				}
				getRoot()->colour = BLACK;
			}
		//--------------------- SET VARIATION --------------------------------------------------------------------------------
		public:
			ft::pair<iterator, bool>	set_insert (const value_type& val)
			{
				node_type	*tmp = getRoot();
				node_type	*tmp_parent = _header;
				bool		compareResult = true;
				
				while (tmp)
				{
					tmp_parent = tmp;
					compareResult = _comp(val, getSetKeyOf(tmp) );
					if (compareResult)
						tmp = getLeftChildOf(tmp);					
					else
						tmp = getRightChildOf(tmp);
				}

				iterator it = iterator(tmp_parent);
				if (compareResult)
				{
					if (it == begin() )
						return (ft::pair<iterator, bool>(set_insertNode(tmp, tmp_parent, val), true));
					else
						--it;
				}
				if (_comp(it.getSetKey(), val) )
					return (ft::pair<iterator, bool>(set_insertNode(tmp, tmp_parent, val), true) );
				return (ft::pair<iterator, bool>(it, false) );
				
			}

			iterator set_insertHint(iterator position, const value_type& val)
			{
				if (position.getNode() == _header)
				{
					if (size() > 0 && _comp(getSetKeyOf(getRightMost()), val))
						return set_insertNode(NULL, getRightMost(), val);
					else
						return set_insert(val).first;
				}
				else if (_comp(val, getSetKeyOf(position.getNode())))
				{
					iterator prevPos = position;
					if (position.getNode() == getLeftMost())
						return set_insertNode(getLeftMost(), getLeftMost(), val);
					else if (_comp(getSetKeyOf((--prevPos).getNode()), val))
					{
						if (getRightChildOf(prevPos.getNode()) == 0)
							return set_insertNode(0, prevPos.getNode(), val);
						else
							return set_insertNode(position.getNode(), position.getNode(), val);
					}
					else
						return set_insert(val).first;
				}
				else if (_comp(getSetKeyOf(position.getNode()), val))
				{
					iterator nextPos = position;
					if (position.getNode() == getRightMost())
						return set_insertNode(0, getRightMost(), val);
					else if (_comp(val, getSetKeyOf((++nextPos).getNode())))
					{
						if (getRightChildOf(position.getNode()) == 0)
							return set_insertNode(0, position.getNode(), val);
						else
							return set_insertNode(nextPos.getNode(), nextPos.getNode(), val);
					}
					else
						return set_insert(val).first;
				}
				else
					return position;
			}

		private:
			iterator	set_insertNode (node_type *pos, node_type *pos_parent, const value_type& val)
			{
				node_type	*newNode;
				
				if (pos_parent == _header || pos || _comp(val, pos_parent->getSetKey()) )
				{
					newNode = createNode(val);
					getLeftChildOf(pos_parent) = newNode;
					if (pos_parent == _header)
					{
						getRoot() = newNode;
						getRightMost() = newNode;
					}
					else if (pos_parent == getLeftMost() )
						getLeftMost() = newNode;
				}
				else
				{
					newNode = createNode(val);
					getRightChildOf(pos_parent) = newNode;
					if (pos_parent == getRightMost() )
						getRightMost() = newNode;
				}
				getParentOf(newNode) 		= pos_parent;
				getLeftChildOf(newNode) 	= NULL;
				getRightChildOf(newNode) 	= NULL;
				insertFix(newNode, _header->parent);
				_size++;
				return iterator(newNode);
			}
		// -------------------------------------------------------------------------------------------------------------------
		// ---------- SEARCH -------------------------------------------------------------------------------------------------
		public:
			iterator	find (const key_type& key) const
			{
				node_type *tmp_parent = _header;
				node_type *tmp = getRoot();

				while (tmp)
				{
					if (!_comp(tmp->getKey(), key) )
					{
						tmp_parent = tmp;
						tmp = getLeftChildOf(tmp);
					}
					else
						tmp = getRightChildOf(tmp);
				}

				iterator it = iterator(tmp_parent);
				if (_comp(key, getKeyOf(it.getNode())) ) 
					return end();
				else
					return it;
			}

			iterator	set_find (const key_type& key) const
			{
				node_type *tmp_parent = _header;
				node_type *tmp = getRoot();

				while (tmp)
				{
					if (!_comp(tmp->getSetKey(), key) )
					{
						tmp_parent = tmp;
						tmp = getLeftChildOf(tmp);
					}
					else
						tmp = getRightChildOf(tmp);
				}

				iterator it = iterator(tmp_parent);
				if (_comp(key, getSetKeyOf(it.getNode())) )
					return end();
				else
					return it;
			}

			iterator lower_bound (const key_type &k) const
			{
				node_type *tmp = getRoot();
				node_type *tmp_parent = _header;
				
				while (tmp != 0)
				{
					if (!_comp(getKeyOf(tmp), k))
					{
						tmp_parent = tmp,
						tmp = getLeftChildOf(tmp);
					}
					else
						tmp = getRightChildOf(tmp);
				}
				return iterator(tmp_parent);
			}

			iterator upper_bound (const key_type &k) const
			{
				node_type *tmp = getRoot();
				node_type *tmp_parent = _header;

				while (tmp != 0)
				{
					if (_comp(k, getKeyOf(tmp)))
					{
						tmp_parent = tmp;
						tmp = getLeftChildOf(tmp);

					}
					else
						tmp = getRightChildOf(tmp);
				}
				return iterator(tmp_parent);
			}

			iterator set_lower_bound (const key_type &k) const
			{
				node_type *tmp = getRoot();
				node_type *tmp_parent = _header;
				
				while (tmp != 0)
				{
					if (!_comp(getSetKeyOf(tmp), k))
					{
						tmp_parent = tmp,
						tmp = getLeftChildOf(tmp);
					}
					else
						tmp = getRightChildOf(tmp);
				}
				return iterator(tmp_parent);
			}

			iterator set_upper_bound (const key_type &k) const
			{
				node_type *tmp = getRoot();
				node_type *tmp_parent = _header;

				while (tmp != 0)
				{
					if (_comp(k, getSetKeyOf(tmp)))
					{
						tmp_parent = tmp;
						tmp = getLeftChildOf(tmp);

					}
					else
						tmp = getRightChildOf(tmp);
				}
				return iterator(tmp_parent);
			}
		// -------------------------------------------------------------------------------------------------------------------
		// ---------- DELETION -----------------------------------------------------------------------------------------------
		public:
			void	erase(iterator it)
			{
				node_type *nodeToDel = EraseAndRebalance(it.getNode());
				destroyNode(nodeToDel);
				_size--;
			}

		private:
			node_type	*EraseAndRebalance(node_type *node)
			{
				node_type* nodeToDel = node;
				node_type* tmp = 0;
				node_type* tmp_parent = 0;

				if (nodeToDel->l_child == 0)     // node has at most one non-null child.
					tmp = nodeToDel->r_child;     // tmp might be null.
				else
					if (nodeToDel->r_child == 0)  // node has exactly one non-null child.
						tmp = nodeToDel->l_child;    // tmp is not null.
					else 
					{
						// node has two non-null children.  Set nodeToDel to node's successor.  tmp might be null.
						nodeToDel = nodeToDel->r_child;  
						while (nodeToDel->l_child != 0)
							nodeToDel = nodeToDel->l_child;
						tmp = nodeToDel->r_child;
					}
				if (nodeToDel != node) 
				{
					// relink nodeToDel in place of node.  NodeToDel is node's successor
					node->l_child->parent = nodeToDel; 
					nodeToDel->l_child = node->l_child;
					if (nodeToDel != node->r_child) 
					{
						tmp_parent = nodeToDel->parent;
						if (tmp) 
							tmp->parent = nodeToDel->parent;
						nodeToDel->parent->l_child = tmp;
						nodeToDel->r_child = node->r_child;
						node->r_child->parent = nodeToDel;
					}
					else
						tmp_parent = nodeToDel;  
					if (getRoot() == node)
						getRoot() = nodeToDel;
					else if (node->parent->l_child == node)
						node->parent->l_child = nodeToDel;
					else 
						node->parent->r_child = nodeToDel;
					nodeToDel->parent = node->parent;
					std::swap(nodeToDel->colour, node->colour);
					nodeToDel = node;
					// nodeToDel now points to node to be actually deleted
				}
				else 
				{                   
					tmp_parent = nodeToDel->parent;
					if (tmp) 
						tmp->parent = nodeToDel->parent;   
					if (getRoot() == node)
						getRoot() = tmp;
					else 
						if (node->parent->l_child == node)
							node->parent->l_child = tmp;
						else
							node->parent->r_child = tmp;
					if (getLeftMost() == node)
					{
						if (node->r_child == 0)
							getLeftMost() = node->parent;
						else
							getLeftMost() = getMinOf(tmp);
					}
					if (getRightMost() == node)
					{
						if (node->l_child == 0)
							getRightMost() = node->parent;  
						else
							getRightMost() = getMaxOf(tmp);
					}
				}
				if (nodeToDel->colour != RED) 
				{ 
					while (tmp != getRoot() && (tmp == 0 || tmp->colour == BLACK))
					{
						if (tmp == tmp_parent->l_child) 
						{
							node_type* tmpSibling = tmp_parent->r_child;
							if (tmpSibling->colour == RED) 
							{
								tmpSibling->colour = BLACK;
								tmp_parent->colour = RED;
								rotateLeft(tmp_parent, getRoot());
								tmpSibling = tmp_parent->r_child;
							}
							if ((tmpSibling->l_child == 0 || 
								tmpSibling->l_child->colour == BLACK) &&
								(tmpSibling->r_child == 0 || 
								tmpSibling->r_child->colour == BLACK)) 
							{
								tmpSibling->colour = RED;
								tmp = tmp_parent;
								tmp_parent = tmp_parent->parent;
							} 
							else 
							{
								if (tmpSibling->r_child == 0 
									|| tmpSibling->r_child->colour == BLACK) 
								{
									tmpSibling->l_child->colour = BLACK;
									tmpSibling->colour = RED;
									rotateRight(tmpSibling, getRoot());
									tmpSibling = tmp_parent->r_child;
								}
								tmpSibling->colour = tmp_parent->colour;
								tmp_parent->colour = BLACK;
								if (tmpSibling->r_child) 
									tmpSibling->r_child->colour = BLACK;
								rotateLeft(tmp_parent, getRoot());
								break;
							}
						} 
						else 
						{   
							// same as above, with r_child <-> l_child.
							node_type* tmpSibling = tmp_parent->l_child;

							if (tmpSibling->colour == RED) 
							{
								tmpSibling->colour = BLACK;
								tmp_parent->colour = RED;
								rotateRight(tmp_parent, getRoot());
								tmpSibling = tmp_parent->l_child;
							}
							if ((tmpSibling->r_child == 0 || 
								tmpSibling->r_child->colour == BLACK) &&
								(tmpSibling->l_child == 0 || 
								tmpSibling->l_child->colour == BLACK)) 
							{
								tmpSibling->colour = RED;
								tmp = tmp_parent;
								tmp_parent = tmp_parent->parent;
							} 
							else 
							{
								if (tmpSibling->l_child == 0 || tmpSibling->l_child->colour == BLACK) 
								{
									tmpSibling->r_child->colour = BLACK;
									tmpSibling->colour = RED;
									rotateLeft(tmpSibling, getRoot());
									tmpSibling = tmp_parent->l_child;
								}
								tmpSibling->colour = tmp_parent->colour;
								tmp_parent->colour = BLACK;
								if (tmpSibling->l_child) 
									tmpSibling->l_child->colour = BLACK;
								rotateRight(tmp_parent, getRoot());
								break;
							}
						}
						if (tmp) 
							tmp->colour = BLACK;
					}
				}
				return nodeToDel;
			}
		// -------------------------------------------------------------------------------------------------------------------
		public:
			void clear() 
			{
				iterator it = begin();
				iterator tmp = it;

				while (it != end())
				{	

					it++;
					erase(tmp);
					tmp = it;
				}
				_size = 0;
				getLeftMost() = _header;
				getRightMost() = _header;
				getRoot() = NULL;
			}      

		// ACCESSORS ----------------------
 			key_compare 	key_comp() 	const { return _comp; }

  		// ITERATORS
			iterator 		begin() const		
			{ 
				if (_header)
					return iterator(getLeftMost());
				else
					return (end());
			}

			iterator 		end() 	const	{ return iterator(_header); }
		// -------------------------------------------------------------------------------------------------------------------
		// SWAP --------------------------------------------------------------------------------------------------------------
			void	swap(Red_black_tree &rhsTree)
			{
				if (getRoot() == 0)
				{
					if (rhsTree.getRoot() != 0)
					{
						getRoot() = rhsTree.getRoot();
						getLeftMost() = rhsTree.getLeftMost();
						getRightMost() = rhsTree.getRightMost();
						getRoot()->parent = _header;
						
						rhsTree.getRoot() = 0;
						rhsTree.getLeftMost() = rhsTree._header;
						rhsTree.getRightMost() = rhsTree._header;
					}
				}
				else if (rhsTree.getRoot() == 0)
				{
					rhsTree.getRoot() = getRoot();
					rhsTree.getLeftMost() = getLeftMost();
					rhsTree.getRightMost() = getRightMost();
					rhsTree.getRoot()->parent = rhsTree._header;

					getRoot() = 0;
					getLeftMost() = _header;
					getRightMost() = _header;
				}
				else
				{		
					std::swap(getRoot(),rhsTree.getRoot());
       				std::swap(getLeftMost(),rhsTree.getLeftMost());
     				std::swap(getRightMost(),rhsTree.getRightMost());

					getRoot()->parent = _header;
					rhsTree.getRoot()->parent = rhsTree._header;
				}
				std::swap(_size, rhsTree._size);
				std::swap(_comp, rhsTree._comp);
			}
		// -------------------------------------------------------------------------------------------------------------------
		// GETTERS -----------------------------------------------------------------------------------------------------------
		protected:
			node_type		*&getRoot()			const 			{ return _header->parent; }
			node_type		*&getLeftMost() 	const 			{ return _header->l_child; }			
			node_type		*&getRightMost()	const 			{ return _header->r_child; }

			node_type		*&getLeftChildOf(node_type *node) const	{ return node->l_child; }			
			node_type		*&getRightChildOf(node_type *node) const	{ return node->r_child; }			
			node_type		*&getParentOf(node_type *node)		{ return node->parent; }			
			
			node_type		*getMinOf(node_type	*node) 			{ return node->getMin(); }
			node_type		*getMaxOf(node_type	*node)			{ return node->getMax(); }		
			
			reference		getValueOf(node_type *node)			{ return node->value; }			
			const key_type	&getKeyOf(node_type *node)	 const	{ return node->getKey(); }
			const key_type	&getSetKeyOf(node_type *node)	const	{ return node->getSetKey(); }
			NodeColour		&getColourOf(node_type *node)		{ return node->colour; }
		// -------------------------------------------------------------------------------------------------------------------	
		// MEMBER VARIABLES --------------------------------------------------------------------------------------------------
		private:
			node_type					*_header;
		
			key_compare					_comp;
			
			allocator_type				_valueAlloc;
			std::allocator<node_type>	_nodeAlloc;

			size_type					_size;
			size_type					_capacity;
		// -------------------------------------------------------------------------------------------------------------------

	}; // END class Red_black_tree
} // END namespace ft

#endif // RED_BLACK_TREE_HPP