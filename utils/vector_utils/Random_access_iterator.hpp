#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream> // Testing, delete later

# include "iterator.hpp"
# include "Random_access_iterator_utils.hpp"

// CONST ITERATOR WORKS ???????????????????

namespace ft 
{
	template <typename T>
	class Random_access_iterator : public virtual ft::iterator <ft::random_access_iterator_tag, T> 
	{

		public:
			typedef T 								value_type;
			typedef ft::random_access_iterator_tag	iterator_category;
			typedef ptrdiff_t						difference_type;
			
			typedef T*								pointer;
			typedef T&								reference;
			typedef const T&						const_reference;

		// CONSTRUCTORS
			Random_access_iterator (pointer data = NULL) : _data(data) {}
			Random_access_iterator (const Random_access_iterator& rhs) { _data = rhs._data; }
		// DESTRUCTOR
			~Random_access_iterator () {}
		// ASSIGMNEMT OPERATOR
			Random_access_iterator& operator= (const Random_access_iterator& rhs) 
			{
				_data = rhs._data;
				return (*this);
			}
		// ------------------------------------------------------------------------------------------------

		// INCREMENT && DECREMENT
			Random_access_iterator& operator++ () 
			{
				++_data;
				return *this;
			}

			Random_access_iterator operator++ (int) 
			{
				Random_access_iterator<value_type> tmp(*this);
				++(*this);
				return tmp;
			}

			Random_access_iterator& operator-- () 
			{
				--_data;
				return *this;
			}

			Random_access_iterator operator-- (int) 
			{
				Random_access_iterator<value_type> tmp(*this);
				--(*this);
				return tmp;
			}
		// ------------------------------------------------------------------------------------------------

		// ADDING && SUBSTRACTING
			Random_access_iterator& operator+= (difference_type n) 
			{
				_data += n; // Works??
				// difference_type m = n; //cppreference
				// if (m >= 0) while (m--) ++r;
				// else while (m++) --r;
				// return r;
				return *this;
			}

			Random_access_iterator& operator-= (difference_type n) 
			{
				_data -= n; // Works??
				// return r += -n; cppreference
				return *this;
			}

			Random_access_iterator operator+ (difference_type n)
			{
				Random_access_iterator<value_type> tmp(*this);
				tmp._data += n;
				return tmp;
			}
			
			Random_access_iterator operator- (difference_type n)
			{
				Random_access_iterator<value_type> tmp(*this);
				// tmp._data -= n;
				// return tmp;
				return (tmp -= n);
			}

			// Difference between two iterators
			difference_type operator- (Random_access_iterator const &rhs) const 
			{
				return (_data - rhs._data);
			}
		// ------------------------------------------------------------------------------------------------

		// COMPARING OPERATORS
			bool operator<	(const Random_access_iterator& rhs)	{ return (_data < rhs._data); }
			bool operator>	(const Random_access_iterator& rhs)	{ return (_data > rhs._data); }
			bool operator<=	(const Random_access_iterator& rhs)	{ return (_data <= rhs._data); }
			bool operator>=	(const Random_access_iterator& rhs)	{ return (_data >= rhs._data); }
			bool operator==	(const Random_access_iterator& rhs)	{ return (_data == rhs._data); }
			bool operator!=	(const Random_access_iterator& rhs)	{ return (_data != rhs._data); }
		// ------------------------------------------------------------------------------------------------

		// ACCESS OPERATORS
			reference 	operator[] (int n)	{return (*(_data + n) ); }

			// const_reference operator[](int n) const {
			// 	return (*(_data + n));
			// }

			reference	operator* ()	const 	{ return (*_data); }
			pointer		operator-> ()	const 	{ return (&(operator*() )); }
			//-------------------------------------------------------
		
		private:
			pointer	_data;
	
	}; // END class Random_access_iterator

//Specialized for "n + iterator"
	template <typename T>
	ft::Random_access_iterator<T> operator+ (typename ft::Random_access_iterator<T>::difference_type n, ft::Random_access_iterator<T> &rhs) 
	{
		ft::Random_access_iterator<T> tmp(rhs);
		return (tmp += n);
	}

} // END namespace ft

#endif // RANDOM_ACCESS_ITERATOR_HPP