#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef> // defines ptrdiff_t

namespace ft {

	// defines properties of iterators
	template <typename Iterator> 
	class iterator_traits {
		public:
			typedef typename Iterator::value_type            value_type;
			typedef typename Iterator::difference_type       difference_type;
			typedef typename Iterator::iterator_category     iterator_category;
			typedef typename Iterator::pointer               pointer;
			typedef typename Iterator::reference             reference;
	};

	// pointer specialization
	template <typename T> 
	class iterator_traits<T*> {
		public:
			typedef  T          				value_type;
			typedef  ptrdiff_t      			difference_type;
			typedef  random_access_iterator_tag	iterator_category;
			typedef  T*              			pointer;
			typedef  T&            				reference;
	};

	// const pointer specialization
	template <typename T> 
	class iterator_traits<const T*> {
		public:
			typedef  T          				value_type;
			typedef  ptrdiff_t      			difference_type;
			typedef  random_access_iterator_tag	iterator_category;
			typedef  const T*              		pointer;
			typedef  const T&            		reference;
	};
	
} // END namespace ft

#endif // ITERATOR_TRAITS_HPP