#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream> // Testing, delete later

# include "../iterator_utils/iterator.hpp"
#include "enable_if.hpp"
//# include "Random_access_iterator_utils.hpp"

// CONST ITERATOR WORKS ???????????????????

namespace ft 
{
	template <typename T, bool IsConst = false>
	class Random_access_iterator : public virtual ft::iterator <ft::random_access_iterator_tag, T> 
	{

		public:
			typedef T 																value_type;
			typedef ft::random_access_iterator_tag									iterator_category;
			typedef ptrdiff_t														difference_type;
			typedef	size_t															size_type;
			
			typedef typename ft::verify_const_property<IsConst, T*, const T*>::type	pointer;
			typedef typename ft::verify_const_property<IsConst, T&, const T&>::type	reference;

		// CONSTRUCTORS
			Random_access_iterator (pointer data = 0) : _data(data) {}

			Random_access_iterator (const Random_access_iterator<T>& rhs) : _data(rhs.getData() ) {} // _data = rhs._data;
			
		// DESTRUCTOR
			~Random_access_iterator () {}
		// ASSIGMNEMT OPERATOR
			Random_access_iterator& operator= (const Random_access_iterator& rhs) 
			{
				if (this != &rhs)
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
				Random_access_iterator tmp(*this);
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
				Random_access_iterator tmp(*this);
				--(*this);
				return tmp;
			}
		// ------------------------------------------------------------------------------------------------

		// ADDING && SUBSTRACTING
			Random_access_iterator& operator+= (difference_type n) 
			{
				// _data += n; // Works??
				// difference_type m = n; //cppreference
				if (n >= 0) 
				{
					while (n--) 
						++(*this);
				}
				else 
				{
					while (n++) 
						--(*this);
				}
				return *this;
			}

			Random_access_iterator& operator-= (difference_type n) 
			{
				_data -= n; // Works??
				// return r += -n; cppreference
				return *this;
			}

			Random_access_iterator operator+ (difference_type n) const
			{
				return Random_access_iterator(_data + n);
				// Random_access_iterator tmp(*this);
				// tmp._data += n;
				// return tmp;
			}

			friend Random_access_iterator operator+ (difference_type n, Random_access_iterator &rhs) // typename  ft::Random_access_iterator<T>::difference_type
			{
				return Random_access_iterator(rhs._data + n);
				// return (tmp += n);
			}

			// const Random_access_iterator operator+ (difference_type n)
			// {
			// 	Random_access_iterator<value_type> tmp(*this);
			// 	tmp._data += n;
			// 	return tmp;
			// }
			
			Random_access_iterator operator- (difference_type n) const
			{
				// Random_access_iterator tmp(*this);
				// // tmp._data -= n;
				// // return tmp;
				// return (tmp -= n);
				return Random_access_iterator(_data - n);
			}

			//Difference between two iterators
			// difference_type operator- (Random_access_iterator const &rhs) const 
			// {
			// 	return (_data - rhs._data);
			// }

			friend difference_type	operator- ( Random_access_iterator lhs, Random_access_iterator rhs )
			{
				return (lhs._data - rhs._data);
			}  
		// ------------------------------------------------------------------------------------------------

		// COMPARING OPERATORS
			friend bool operator<	(const Random_access_iterator& lhs, const Random_access_iterator& rhs)	{ return (lhs._data < rhs._data); }
			friend bool operator>	(const Random_access_iterator& lhs, const Random_access_iterator& rhs)	{ return (lhs._data > rhs._data); }
			friend bool operator<=	(const Random_access_iterator& lhs, const Random_access_iterator& rhs)	{ return (lhs._data <= rhs._data); }
			friend bool operator>=	(const Random_access_iterator& lhs, const Random_access_iterator& rhs)	{ return (lhs._data >= rhs._data); }
			friend bool operator==	(const Random_access_iterator& lhs, const Random_access_iterator& rhs)	{ return (lhs._data == rhs._data); }
			friend bool operator!=	(const Random_access_iterator& lhs, const Random_access_iterator& rhs)	{ return (lhs._data != rhs._data); }
		// ------------------------------------------------------------------------------------------------

		// ACCESS OPERATORS
			reference 	operator[] (int n)	{return (*(_data + n) ); }

			// const_reference operator[](int n) const {
			// 	return (*(_data + n));
			// }

			reference	operator* ()	const 	{ return (*_data); }
			pointer		operator-> ()	const 	{ return (&(operator*() )); }
			//-------------------------------------------------------
		
			pointer	getData() const { return _data; }
		private:
			pointer	_data;
	
	}; // END class Random_access_iterator

//Specialized for "n + iterator"
	template <typename T>
	ft::Random_access_iterator<T> operator+ (int n, ft::Random_access_iterator<T> &rhs) // typename  ft::Random_access_iterator<T>::difference_type
	{
		ft::Random_access_iterator<T> tmp(rhs);
		return (tmp += n);
	}

} // END namespace ft

#endif // RANDOM_ACCESS_ITERATOR_HPP