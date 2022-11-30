#ifndef UTILITY_FUNCTIONS_HPP
# define UTILITY_FUNCTIONS_HPP

# include <typeinfo>
# include "../iterator/iterator.hpp"

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

	template <typename InputIterator1, typename InputIterator2>
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

	template<typename InputIterator>  
	typename ft::iterator_traits<InputIterator>::difference_type    distance (InputIterator first, InputIterator last) 
	{
		typename ft::iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last)
		{
			n++;
			first++;
		}
		return (n);
	}

	// template<typename It1, typename It2>  
	// typename ft::iterator_traits<It1>::difference_type    distance (It1 first, It2 last) 
	// {
	// 	return (last - first);
	// }

} // END namespace ft

#endif // UTILITY_FUNCTIONS_HPP