#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef> // defines ptrdiff_t

namespace ft 
{

// Empty classes to identify the category of an iterator
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
//---------------------------------------------------------------------------

// Base class template, used to derive iterator classes.
// Provides member types needed for iterator_traits class template
	template <	typename Category,
				typename T,
				typename Distance = ptrdiff_t,
          		typename Pointer = T*,
				typename Reference = T&
			>
	class iterator 
	{
		public:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
	};
//---------------------------------------------------------------------------

// defines properties of iterators
	template <typename Iterator> 
	class iterator_traits 
	{
		public:
			typedef typename Iterator::value_type            value_type;
			typedef typename Iterator::difference_type       difference_type;
			typedef typename Iterator::iterator_category     iterator_category;
			typedef typename Iterator::pointer               pointer;
			typedef typename Iterator::reference             reference;
	};

// pointer specialization
// 	template <typename T> 
// 	class iterator_traits <T*> 
// 	{
// 		public:
// 			typedef  T          							value_type;
// 			typedef  ptrdiff_t      						difference_type;
// 			typedef  random_access_iterator_tag				iterator_category;
// 			typedef  T*              						pointer;
// 			typedef  T&            							reference;
// 	};

// // const pointer specialization
// 	template <typename T> 
// 	class iterator_traits <const T*> 
// 	{
// 		public:
// 			typedef  T          							value_type;
// 			typedef  ptrdiff_t      						difference_type;
// 			typedef  random_access_iterator_tag				iterator_category;
// 			typedef  const T*              					pointer;
// 			typedef  const T&            					reference;
// 	};
//---------------------------------------------------------------------------

// Used to define type given to iterator as const or non const
	template <bool IsConst, typename NonConst, typename Const>
    struct verify_const_property {};

    template <typename NonConst, typename Const>
    struct verify_const_property <false, NonConst, Const>
    {
        typedef NonConst type;
    };

    template <typename NonConst, typename Const>
    struct verify_const_property <true, NonConst, Const>
    {
        typedef Const type;
    };
//---------------------------------------------------------------------------

} // END namespace ft

#endif // ITERATOR_HPP