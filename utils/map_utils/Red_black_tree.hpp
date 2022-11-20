#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "Node.hpp"
# include "Bidirectional_iterator.hpp"
# include "../iterator_utils/reverse_iterator.hpp"

namespace ft
{
	template<	typename Key,
				typename T,
				typename Compare,
				typename Alloc
			>
	class Red_black_tree
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;
			
			typedef	Compare											key_compare;
			typedef Alloc											allocator_type;
			
			typedef size_t 											size_type;
			typedef ptrdiff_t difference_type;
			
			typedef	typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			
			typedef ft::Bidirectional_iterator<Key, T>				iterator;
			typedef ft::Bidirectional_iterator<const Key, T>		const_iterator;
			typedef ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			
			typedef Node<Key, T>									node_type;
		
		// CONSTRUCTOR
			Red_black_tree (const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) 
			: _comp(comp), _valueAlloc(alloc), _size(0), _capacity(0) 
			{ 
				_header = allocNode();
				_header->colour = RED;
				_header->parent = NULL;
				_header->l_child = _header;
				_header->r_child = _header;
			}
		// DESTRUCTOR
			~Red_black_tree () { deallocNode(_header); } //clear ?
		// -------------------------------------------------------------------------------------------------------------------
		// CAPACITY
			bool 			empty()		const	{ return (_size == 0); } 
			
			size_type 		size()		const	{ return (_size); }
			
			size_type 		max_size()	const	{ return (_nodeAlloc.max_size() ); }

			allocator_type 	get_allocator() const { return (_valueAlloc ); }
		// -------------------------------------------------------------------------------------------------------------------
		// MODIFIERS
			ft::pair<iterator, bool>	insert (const value_type& val, iterator pos = NULL) 
			{
				node_type	*tmp_parent = _header;
				node_type	*tmp = getRoot();
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

			iterator	find (const key_type& key)
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
				if (it == end() || _comp(key, getKeyOf(it._node)) )
					return end();
				else
					return it;
			}

			void clear() {
				if (_size) 
				{
					// _M_erase(_M_root());
					// _M_leftmost() = _M_header;
					// _M_root() = 0;
					// _M_rightmost() = _M_header;
					// _M_node_count = 0;
				}
			}      

		// ACCESSORS ----------------------
 			key_compare 	key_comp() 	const { return _comp; }

  		// ITERATORS
			iterator 		begin() 		{ return getLeftMost(); }
			const_iterator	begin() const 	{ return getLeftMost(); }

			iterator 		end() 			{ return _header; }
  			const_iterator 	end() 	const	{ return _header; }

			// reverse_iterator rbegin() {return reverse_iterator(end());}
  			// const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
  		
			// reverse_iterator rend() {return reverse_iterator(begin());}
  			// const_reverse_iterator rend() const {  return const_reverse_iterator(begin()); } 
		// SWAP
		  	// void swap(_Rb_tree<_Key,_Value,_KeyOfValue,_Compare,_Alloc>& __t) {
			// 	// __STD::swap(_M_header, __t._M_header);
			// 	// __STD::swap(_M_node_count, __t._M_node_count);
			// 	// __STD::swap(_M_key_compare, __t._M_key_compare);
			// }

			node_type*& getRoot ()	const 
				{ return _header->parent; }
		protected: //private ???
			
			node_type*& getLeftMost () const 
				{ return _header->l_child; }
			
			node_type*& getRightMost () const 
				{ return _header->r_child; }

			node_type*& getLeftChildOf (node_type *node)
				{return node->l_child; }
			
			node_type*& getRightChildOf (node_type *node)
				{return node->r_child; }
			
			node_type*& getParentOf (node_type *node)
				{return node->parent; }
			
			reference getValueOf (node_type *node)
				{return node->value; }
			
			const key_type& getKeyOf(node_type *node)
				{return node->getKey(); }
			
			NodeColour& getColourOf(node_type *node)
				{return node->colour; }

			// node_type	* getMinimum(node_type	*node) 
			// 	{ return Node::getMin(node); }

			// node_type	* getMaximum(node_type	*node)
			// 	{ return Node::getMax(node); }
		
		private:
		// UTILITY PRIVATE FUNCTIONS -----------------------------------------------------------------------------------------
			node_type	*allocNode ()
			{
				// node_type	*newNode = _nodeAlloc.allocate(1);

				// _valueAlloc.construct(&newNode->data, val);
				
				// newNode->leftChild	= NULL;
				// newNode->rightChild = NULL;
				// newNode->parent		= NULL;
				// newNode->colour		= RED;
				// return (newNode);
				return _nodeAlloc.allocate(1);
			}

			void	deallocNode (node_type	*node)
			{
				// _valueAlloc.destroy(&node->value);
				_nodeAlloc.deallocate(node, 1);
			}

			node_type	*createNode (const value_type& val)
			{
				node_type	*tmp = allocNode();
				_valueAlloc.construct(&(tmp->value), val);
				return tmp;
			}
			
 			//Needed ?
			// node_type	*cloneNode (node_type *node)
			// {
			// 	node_type	*tmp = createNode(node->value);
				
			// 	tmp->colour = node->colour;
			// 	tmp->l_child = NULL;
			// 	tmp->r_child = NULL;
			// 	return tmp;
			// }

			void	destroyNode (node_type	*node)
			{
				_valueAlloc.destroy(&(node->value) );
				deallocNode(node);
			}

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
				rebalanceTree(newNode, _header->parent);
				_size++;
				return iterator(newNode);
			}

			void	rebalanceTree(node_type *newNode, node_type *root)
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
				root->colour = BLACK;
			}

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
		// PRIVATE MEMBER VARIABLES ------------------------------------------------------------------------------------------
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