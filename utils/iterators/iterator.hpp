#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {

	// Base class template, used to derive iterator classes.
	// Provides member types needed for iterator_traits class template
	template <	typename Category,
				typename T,
				typename Distance = ptrdiff_t,
          		typename Pointer = T*,
				typename Reference = T&
			>
	class iterator {

		public:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
	};
	//-------------------------------------------------------------------
} // END namespace ft

#endif // ITERATOR_HPP