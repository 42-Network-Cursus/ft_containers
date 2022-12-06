#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterator.hpp"
# include "../Rbtree/Node.hpp"

namespace ft 
{
	template <typename Key, typename Value, bool IsConst = false>
	class Bidirectional_iterator : public virtual ft::iterator <ft::bidirectional_iterator_tag, Value> 
	{
		public:
			typedef Key		key_type;
			typedef Value	value_type;

			typedef Node<Key, Value>	node_type;
			
			typedef  ft::bidirectional_iterator_tag		iterator_category;
			typedef  ptrdiff_t							difference_type;
			
			typedef typename ft::verify_const_property<IsConst, value_type*, const value_type*>::type	pointer;
			typedef typename ft::verify_const_property<IsConst, value_type&, const value_type&>::type	reference;

		// CONSTRUCTORS -----------------------------------------------------------------------------------
			Bidirectional_iterator (node_type *node = NULL) : _node(node) {}
			Bidirectional_iterator (const Bidirectional_iterator<Key, Value>& rhs) : _node(rhs.getNode()) {}
		// DESTRUCTOR -------------------------------------------------------------------------------------
			~Bidirectional_iterator () {}
		// ASSIGMNEMT OPERATOR ----------------------------------------------------------------------------
			Bidirectional_iterator& operator= (const Bidirectional_iterator& rhs) 
			{
				_node = rhs._node;
				return (*this);
			}
		// ------------------------------------------------------------------------------------------------
		// INCREMENT && DECREMENT -------------------------------------------------------------------------
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
		// ------------------------------------------------------------------------------------------------
		// ACCESS OPERATORS -------------------------------------------------------------------------------
			reference	operator* ()	const 	{ return (_node->value); }
			pointer		operator-> ()	const 	{ return (&(operator*() )); }
		// ------------------------------------------------------------------------------------------------
		// COMPARING OPERATORS ----------------------------------------------------------------------------
			friend bool operator==	(const Bidirectional_iterator& lhs, const Bidirectional_iterator& rhs)	{ return (lhs._node == rhs._node); }
			friend bool operator!=	(const Bidirectional_iterator& lhs, const Bidirectional_iterator& rhs)	{ return (lhs._node != rhs._node); }
		// ------------------------------------------------------------------------------------------------
		// GETTERS ----------------------------------------------------------------------------------------
			const key_type&	getKey() { return _node->getKey(); }
			const key_type&	getSetKey() { return _node->getSetKey(); }
			node_type	*getNode() const { return _node; }
		// ------------------------------------------------------------------------------------------------
		private:
			node_type	*_node;
	
	}; // END class Bidirectional_iterator

} // END namespace ft

#endif // BIDIRECTIONAL_ITERATOR_HPP