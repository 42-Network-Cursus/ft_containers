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
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			
			typedef T*																			pointer;
			typedef T&																			reference;
			typedef const T&																	const_reference;

		// CONSTRUCTORS
			Bidirectional_iterator () : _data(NULL) {}
			Bidirectional_iterator (pointer ptr) : _data(ptr) {}
			Bidirectional_iterator (const Bidirectional_iterator & rhs) { _data = rhs._data; }
		// DESTRUCTOR
			~Bidirectional_iterator () {}
		// ASSIGMNEMT OPERATOR
			Bidirectional_iterator& operator= (const Bidirectional_iterator & rhs) 
			{
				_data = rhs._data;
				return (*this);
			}
		// ------------------------------------------------------------------------------------------------

		// INCREMENT && DECREMENT
			Bidirectional_iterator& operator++ () 
			{
				++_data;
				return *this;
			}

			Bidirectional_iterator operator++ (int) 
			{
				Bidirectional_iterator<value_type> tmp(*this);
				++(*this);
				return tmp;
			}

			Bidirectional_iterator& operator-- () 
			{
				--_data;
				return *this;
			}

			Bidirectional_iterator operator-- (int) 
			{
				Bidirectional_iterator<value_type> tmp(*this);
				--(*this);
				return tmp;
			}
		// ------------------------------------------------------------------------------------------------

		// ADDING && SUBSTRACTING
			// Bidirectional_iterator& operator+= (difference_type n) 
			// {
			// 	_data += n; // Works??
			// 	// difference_type m = n; //cppreference
			// 	// if (m >= 0) while (m--) ++r;
			// 	// else while (m++) --r;
			// 	// return r;
			// 	return *this;
			// }

			// Bidirectional_iterator& operator-= (difference_type n) 
			// {
			// 	_data -= n; // Works??
			// 	// return r += -n; cppreference
			// 	return *this;
			// }

			// Bidirectional_iterator operator+ (difference_type n)
			// {
			// 	Bidirectional_iterator<value_type> tmp(*this);
			// 	tmp._data += n;
			// 	return tmp;
			// }
			
			// Bidirectional_iterator operator- (difference_type n)
			// {
			// 	Bidirectional_iterator<value_type> tmp(*this);
			// 	// tmp._data -= n;
			// 	// return tmp;
			// 	return (tmp -= n);
			// }

			// // Difference between two iterators
			// difference_type operator- (Bidirectional_iterator const &rhs) const 
			// {
			// 	return (_data - rhs._data);
			// }
		// ------------------------------------------------------------------------------------------------

		// COMPARING OPERATORS
			// bool operator<	(const Bidirectional_iterator& rhs)	{ return (_data < rhs._data); }
			// bool operator>	(const Bidirectional_iterator& rhs)	{ return (_data > rhs._data); }
			// bool operator<=	(const Bidirectional_iterator& rhs)	{ return (_data <= rhs._data); }
			// bool operator>=	(const Bidirectional_iterator& rhs)	{ return (_data >= rhs._data); }
			bool operator==	(const Bidirectional_iterator& rhs)	{ return (_data == rhs._data); }
			bool operator!=	(const Bidirectional_iterator& rhs)	{ return (_data != rhs._data); }
		// ------------------------------------------------------------------------------------------------

		// ACCESS OPERATORS
			// reference 	operator[] (int n)	{return (*(_data + n) ); }

			// const_reference operator[](int n) const {
			// 	return (*(_data + n));
			// }

			reference	operator* ()	const 	{ return (*_data); }
			pointer		operator-> ()	const 	{ return (&(operator*() )); }
			//-------------------------------------------------------
		
		private: //protected ?
			pointer	_data;
	
	}; // END class Bidirectional_iterator

//Specialized for "n + iterator"
	// template <typename T>
	// ft::Bidirectional_iterator<T> operator+ (typename ft::Bidirectional_iterator<T>::difference_type n, ft::Bidirectional_iterator<T> &rhs) 
	// {
	// 	ft::Bidirectional_iterator<T> tmp(rhs);
	// 	return (tmp += n);
	// }

} // END namespace ft

#endif // BIDIRECTIONAL_ITERATOR_HPP