#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream> // Testing, delete later

# include "iterator_tags.hpp"
# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft {

	template < typename T >
	class Random_access_iterator : public virtual ft::iterator<ft::random_access_iterator_tag, T> {

		public:

			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type 		value_type;

			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;

			typedef T*			pointer;

			typedef T&			reference;

			typedef const T&	const_reference;

			// Default constructor
			Random_access_iterator() : _data(NULL) {} //ok

			Random_access_iterator(pointer ptr) : _data(ptr) {}

			// Copy constructor
			Random_access_iterator(const Random_access_iterator & rhs) { //ok
				_data = rhs._data;
			}

			// Destructor
			~Random_access_iterator() {
			}

			// Assignment operator
			Random_access_iterator& operator=(const Random_access_iterator & rhs) { //ok
				_data = rhs._data;
				return (*this);
			}

			// 			INCREMENT && DECREMENT
			Random_access_iterator &operator++() { //ok
				++_data;
				return *this;
			}

			Random_access_iterator operator++(int) { //ok
				Random_access_iterator<value_type> tmp(*this);
				++(*this);
				return tmp;
			}

			Random_access_iterator &operator--() { //ok
				--_data;
				return *this;
			}

			Random_access_iterator operator--(int) { //ok
				Random_access_iterator<value_type> tmp(*this);
				--(*this);
				return tmp;
			}
			//-------------------------------------------------------

			//				ADDING && SUBSTRACTING
			Random_access_iterator &operator+=(difference_type n) { //ok	
				_data += n; // Works??
				// difference_type m = n; //cppreference
				// if (m >= 0) while (m--) ++r;
				// else while (m++) --r;
				// return r;
				return *this;
			}

			Random_access_iterator &operator-=(difference_type n) {	//ok	
				_data -= n; // Works??
				// return r += -n; cppreference
				return *this;
			}

			Random_access_iterator operator+(difference_type n) //ok
			{
				Random_access_iterator<value_type> tmp(*this);
				tmp._data += n;
				return tmp;
			}
			
			Random_access_iterator operator-(difference_type n) //ok
			{
				Random_access_iterator<value_type> tmp(*this);
				// tmp._data -= n;
				// return tmp;
				return (tmp -= n);
			}

			// Difference between two iterators
			difference_type operator-(Random_access_iterator const &rhs) const {
				return (_data - rhs._data);
			}
			//-------------------------------------------------------

			//				COMPARING OPERATORS
			bool operator<(const Random_access_iterator &rhs) {
				if (_data < (rhs._data))
					return (true);
				return (false);
			}
			
			bool operator>(const Random_access_iterator &rhs) {
				if (_data > (rhs._data))
					return (true);
				return (false);
			}

			bool operator<=(const Random_access_iterator &rhs) {
				if (_data <= (rhs._data))
					return (true);
				return (false);
			}

			bool operator>=(const Random_access_iterator &rhs) {
				if (_data >= (rhs._data))
					return (true);
				return (false);
			}

			bool operator==(const Random_access_iterator &rhs) {
				if (_data == (rhs._data))
					return (true);
				return (false);
			}

			bool operator!=(const Random_access_iterator &rhs) {
				if (_data != (rhs._data)) // if (*_data != *(rhs._data))
					return (true);
				return (false);
			}
			//-------------------------------------------------------

			//				ACCESS OPERATORS
			reference operator[](int n) {
				return (*(_data + n));
			}

			// const_reference operator[](int n) const {
			// 	return (*(_data + n));
			// }

			reference operator*() const {
				return (*_data);
			}

			// HOW TO USE ???????
			pointer operator->() const {
				return (&(operator*()));
			}
			//-------------------------------------------------------
		
		private: //protected ?

			pointer	_data;
	
	}; // END class Random_access_iterator

	//Specialized for "n + iterator"
	template <typename T>
	ft::Random_access_iterator<T> operator+(typename ft::Random_access_iterator<T>::difference_type n, ft::Random_access_iterator<T> &rhs) {
		ft::Random_access_iterator<T> tmp(rhs);
		return (tmp += n);
	}

	template<class InputIterator>  
	typename ft::iterator_traits<InputIterator>::difference_type    distance (InputIterator first, InputIterator last) {
		return (last - first);
	}

} // END namespace ft

#endif // RANDOM_ACCESS_ITERATOR_HPP