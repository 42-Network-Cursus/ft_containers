#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "Node.hpp"
# include "../iterators/Random_access_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"

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
			
			typedef ft::Random_access_iterator<value_type>			iterator;
			typedef ft::Random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			
			typedef Node<Key, T>									node_type;
		
		// CONSTRUCTORS
			Red_black_tree (const allocator_type& alloc = allocator_type()) 
			: _valueAlloc(alloc), _size(0), _capacity(0) 
			{ _header = allocNode(); }
		// DESTRUCTOR
			~Red_black_tree () { deallocyNode(_header); }
		// -----------------------------

			bool 			empty()		const	{ return (_size == 0); } 
			size_type 		size()		const	{ return (_size); }
			size_type 		max_size()	const	{ return (_nodeAlloc.max_size() ); }
			allocator_type 	get_allocator() const { return (_valueAlloc ); }
			
			pointer	insert (const value_type& val) 
			{
				// if (_capacity <= _size)
				
				if (_root == NULL)
					_root = newNode(val);	
				return (&(_root->data) );
			}

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
				node_type	*tmp = newNode();
				_valueAlloc.construct(tmp->value, val);
				return tmp;
			}

			node_type	*cloneNode (node_type *node)
			{
				node_type	*tmp = createNode(node->value);
				
				tmp->colour = node->colour;
				tmp->l_child = NULL;
				tmp->r_child = NULL;
				return tmp;
			}

			void	destroyNode (node_type	*node)
			{
				_valueAlloc.destroy(&(node->value) );
				deallocNode(node);
			}

		protected:
			node_type*& getHeaderParent ()	const 
				{ return _header->parent; }
			
			node_type*& getHeaderLeft () const 
				{ return _header->l_child; }
			
			node_type*& getHeaderRight () const 
				{ return _header->r_child; }

			node_type*& getLeftChild (node_type *node)
				{return node->l_child; }
			
			node_type*& getRightChild (node_type *node)
				{return node->r_child; }
			
			node_type*& getParent (node_type *node)
				{return node->parent; }
			
			reference getValue (node_type *node)
				{return node->value; }
			
			// const _Key*& _S_key(node_type *node)
			// 	{return _KeyOfValue()(_S_value(*node));}
			
			NodeColour& getColor(node_type *node)
				{return node->colour; }

			// node_type	* getMinimum(node_type	*node) 
			// 	{ return Node::getMin(node); }

			// node_type	* getMaximum(node_type	*node)
			// 	{ return Node::getMax(node); }
		
		private:
			node_type				*_header;
		
			key_compare				_comp;
			
			allocator_type			_valueAlloc;
			std::allocator<node>	_nodeAlloc;

			size_type				_size;
			size_type				_capacity;

	}; // END class Red_black_tree

} // END namespace ft

#endif // RED_BLACK_TREE_HPP