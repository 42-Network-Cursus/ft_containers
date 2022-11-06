#ifndef RANDOM_ACCESS_ITERATOR_UTILS_HPP
# define RANDOM_ACCESS_ITERATOR_UTILS_HPP

# include "iterator.hpp"

namespace ft 
{
	template <typename InputIterator1, typename InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) 
	{
		while ( first1 != last1 ) 
		{
			if ( !(*first1 == *first2) )
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (	InputIterator1 first1, InputIterator1 last1,
                                	InputIterator2 first2, InputIterator2 last2 ) 
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) 
				return false;
			else if (*first1 < *first2) 
				return true;
			++first1; 
			++first2;
		}
		return (first2 != last2);
	}

	template<class InputIterator>  
	typename ft::iterator_traits<InputIterator>::difference_type    distance (InputIterator first, InputIterator last) 
	{
		return (last - first);
	}

} // END namespace ft

#endif // RANDOM_ACCESS_ITERATOR_UTILS_HPP