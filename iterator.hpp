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

			typedef Random_access_iterator RA_Iterator;
		private:
			pointer	_data;
		public:
			RA_Iterator() : _data(NULL) {
				std::cout << "Constructor\n";
			}

			RA_Iterator(const RA_Iterator & rhs) {
				std::cout << "Copy\n";
				_data = rhs._data;
			}

			~RA_Iterator() {
				std::cout << "Destructor\n";
			}

			RA_Iterator& operator=(const RA_Iterator & rhs) {
				_data = rhs._data;
			}

		// iterator operator++(int); //postfix increment
		// value_type operator*() const;
		// pointer operator->() const;
		// friend bool operator==(const iterator&, const iterator&);
		// friend bool operator!=(const iterator&, const iterator&); 
	};

}

#endif