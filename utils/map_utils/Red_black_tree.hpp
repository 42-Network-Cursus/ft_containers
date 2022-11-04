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

			typedef	typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			
			typedef ft::Random_access_iterator<value_type>			iterator;
			typedef ft::Random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			
			typedef Node<Key, T>									node;
		
		// CONSTRUCTORS
			Red_black_tree (const allocator_type& alloc = allocator_type()) : _dataAlloc(alloc), _size(0), _capacity(0) {}
		// -----------------------------

			bool 		empty()		const	{ return (_size == 0); } 
			size_type 	size()		const	{ return (_size); }
			size_type 	max_size()	const	{ return (_nodeAlloc.max_size() ); }

			pointer	insert (const value_type& val) 
			{
				// if (_capacity <= _size)
				
				if (_root == NULL)
					_root = newNode(val);	
				return (&(_root->data) );
			}

			node	*newNode (const value_type &val)
			{
				node	*newNode = _nodeAlloc.allocate(1);

				_dataAlloc.construct(&newNode->data, val);
				
				newNode->leftChild	= NULL;
				newNode->rightChild = NULL;
				newNode->parent		= NULL;
				newNode->colour		= RED;
				return (newNode);
			}
		
		private:
			node					*_root;
			key_compare				_comp;
			
			allocator_type			_dataAlloc;
			std::allocator<node>	_nodeAlloc;

			size_type				_size;
			size_type				_capacity;

	}; // END class Red_black_tree

} // END namespace ft

#endif // RED_BLACK_TREE_HPP