#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream> // Testing, delete later

# include "utils/iterator_tags.hpp"

namespace ft {

	// Base class template, used to derive iterator classes.
	// Provides member types needed for iterator_traits class template
	template <	typename Category,
				typename T,
				typename Distance = ptrdiff_t,
          		typename Pointer = T*,
				typename Reference = T&
			>
	class Iterator {

		public:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
	};

	template < typename T >
	class Random_access_iterator : public virtual ft::Iterator<ft::random_access_iterator_tag, T> {

		public:

			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::value_type 		value_type;

			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;

			typedef T*	pointer;

			typedef T&	reference;

		private:

			pointer	_data;

		public:

			//TODEL
			void	toData(T value, int i) {
				_data[i] = value;
			}
			//------

			Random_access_iterator() : _data(NULL) { //ok
				_data = new value_type[10];
				*_data = 10;
				std::cout << "Constructor\n";
			}

			Random_access_iterator(const Random_access_iterator & rhs) { //ok
				std::cout << "Copy\n";
				_data = rhs._data;
			}

			~Random_access_iterator() {
				std::cout << "Destructor\n";
			}

			Random_access_iterator& operator=(const Random_access_iterator & rhs) { //ok
				std::cout << "Operator=\n";
				_data = rhs._data;
				return (*this);
			}

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

			Random_access_iterator operator+(difference_type n) //ok
			{
				Random_access_iterator<value_type> tmp(*this);
				tmp._data += n;
				return tmp;
			}
			
			Random_access_iterator operator-(difference_type n) //ok
			{
				Random_access_iterator<value_type> tmp(*this);
				tmp._data -= n;
				return tmp;
			}

			Random_access_iterator &operator+=(difference_type n) { //ok	
				_data += n; // Works??
				return *this;
			}

			Random_access_iterator &operator-=(difference_type n) {	//ok	
				_data -= n; // Works??
				return *this;
			}

			bool operator<(const Random_access_iterator &rhs) {
				if (*_data < *(rhs._data))
					return (true);
				return (false);
			}
			
			bool operator>(const Random_access_iterator &rhs) {
				if (*_data > *(rhs._data))
					return (true);
				return (false);
			}

			bool operator<=(const Random_access_iterator &rhs) {
				if (*_data <= *(rhs._data))
					return (true);
				return (false);
			}

			bool operator>=(const Random_access_iterator &rhs) {
				if (*_data >= *(rhs._data))
					return (true);
				return (false);
			}
			
			value_type operator[](int n) {
				return (*(_data + n));
			}

			reference operator*() const {
				return (*_data);
			}

			// HOW TO USE ???????
			pointer operator->() const {
				return (&(operator*()));
			}

			// value_type operator=(value_type &value) {
			// 	return (value);
			// }

			bool operator==(const Random_access_iterator &rhs) {
				if (*_data == *(rhs._data))
					return (true);
				return (false);
			}

			bool operator!=(const Random_access_iterator &rhs) {
				if (*_data != *(rhs._data))
					return (true);
				return (false);
			}

			//DIFF BETWEEN 2 ITERATORS

	}; // END class Random_access_iterator

	//Specialized for N + iterator
	template <typename T>
	ft::Random_access_iterator<T> operator+(typename ft::Random_access_iterator<T>::difference_type n, ft::Random_access_iterator<T> &rhs) {
		ft::Random_access_iterator<T> tmp(rhs);
		return (tmp + n);
	}

	// Const specialization ?
	// Ref specialization ?

} // END FT

#endif // END ITERATOR_HPP