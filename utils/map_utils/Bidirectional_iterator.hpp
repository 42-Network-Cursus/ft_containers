#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iostream> // Testing, delete later

# include "iterator.hpp"
# include "Bidirectional_iterator_utils.hpp"

namespace ft 
{
	template <typename Key, typename T>
	class Bidirectional_iterator : public virtual ft::iterator <ft::bidirectional_iterator_tag, T> 
	{
		public:
			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef ft::pair<const Key, T>														value_type;

			typedef  ft::bidirectional_iterator_tag		iterator_category;
			typedef  ptrdiff_t							difference_type;
			
			typedef value_type*																			pointer;
		//weird
			// typedef typename ft::select_const_type<IsConst, value_type*, const value_type*>::type	pointer;
			// typedef typename ft::select_const_type<IsConst, value_type&, const value_type&>::type	reference;
			typedef value_type&																			reference;
			typedef const value_type&																	const_reference;

			typedef Node<Key, T>																node_type;

		// CONSTRUCTORS
			Bidirectional_iterator (node_type *value = NULL) : _node(value) {}
			Bidirectional_iterator (const Bidirectional_iterator& rhs) : _node(rhs._node) {}
		// DESTRUCTOR
			~Bidirectional_iterator () {}
		// ASSIGMNEMT OPERATOR
			Bidirectional_iterator& operator= (const Bidirectional_iterator& rhs) 
			{
				_node = rhs._node;
				return (*this);
			}
		// ------------------------------------------------------------------------------------------------

		// INCREMENT && DECREMENT
			Bidirectional_iterator& operator++ () 
			{
				return (_node->next() );
			}

			Bidirectional_iterator operator++ (int) 
			{
				Bidirectional_iterator tmp(*this);
				++(*this);
				return tmp;
			}

			Bidirectional_iterator& operator-- () 
			
				return (_node->prev());
			}

			Bidirectional_iterator operator-- (int) 
			{
				Bidirectional_iterator tmp(*this);
				--(*this);
				return tmp;
			}
		// ---------------------------------------------------------------------
		// ACCESS OPERATORS
			reference	operator* ()	const 	{ return (_node->value); }
			pointer		operator-> ()	const 	{ return (&(operator*() )); }
		//----------------------------------------------------------------------
		// COMPARING OPERATORS
			bool operator==	(const Bidirectional_iterator& rhs)	
			{
				// if (_is_end != rhs._is_end)
				// 	return false;
				// else if (_is_end == true)
				// 	return true;
				// else
				// 	return node == rhs.node;
			}
			
			bool operator!=	(const Bidirectional_iterator& rhs)	
			{ 
				// if (lhs._is_end != rhs._is_end)
				// 	return true;
				// else if (lhs._is_end == true)
				// 	return false;
				// else
				// 	return lhs._node != rhs._node;
			}
		// ------------------------------------------------------------------------------------------------

		
		private:
			node_type	*_node;
	
	}; // END class Bidirectional_iterator



} // END namespace ft

#endif // BIDIRECTIONAL_ITERATOR_HPP