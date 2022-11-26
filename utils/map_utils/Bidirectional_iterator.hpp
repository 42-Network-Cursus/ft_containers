#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iostream> // Testing, delete later

# include "../iterator_utils/iterator.hpp"

namespace ft 
{
	template <typename Key, typename T, bool IsConst = false>
	class Bidirectional_iterator : public virtual ft::iterator <ft::bidirectional_iterator_tag, T> 
	{
		public:
			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef ft::pair<const Key, T>														value_type;

			typedef  ft::bidirectional_iterator_tag		iterator_category;
			typedef  ptrdiff_t							difference_type;
			
			// typedef value_type*																			pointer;
		//weird
			typedef typename ft::verify_const_property<IsConst, value_type*, const value_type*>::type	pointer;
			typedef typename ft::verify_const_property<IsConst, value_type&, const value_type&>::type	reference;
			// typedef value_type&																			reference;
			// typedef const value_type&																	const_reference;

			typedef Node<Key, T>																node_type;

		// CONSTRUCTORS
			Bidirectional_iterator (node_type *node = NULL) : _node(node) {}
			Bidirectional_iterator (const Bidirectional_iterator<Key, T>& rhs) : _node(rhs.getNode()) {}

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
				Bidirectional_iterator tmp(_node->next());
				*this = tmp;
				return (*this);
			}

			Bidirectional_iterator operator++ (int) 
			{
				Bidirectional_iterator tmp(*this);
				++(*this);
				return tmp;
			}

			Bidirectional_iterator& operator-- ()
			{
				Bidirectional_iterator tmp(_node->prev());
				*this = tmp;
				return (*this);
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
			friend bool operator==	(const Bidirectional_iterator& lhs, const Bidirectional_iterator& rhs)	{ return (lhs._node == rhs._node); }
			friend bool operator!=	(const Bidirectional_iterator& lhs, const Bidirectional_iterator& rhs)	{ return (lhs._node != rhs._node); }
		// ------------------------------------------------------------------------------------------------
			const key_type&	getKey() { return _node->getKey(); }
			node_type	*getNode() const { return _node; }
		
		private:
			node_type	*_node;
	
	}; // END class Bidirectional_iterator

} // END namespace ft

#endif // BIDIRECTIONAL_ITERATOR_HPP