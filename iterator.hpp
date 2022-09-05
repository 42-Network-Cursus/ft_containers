#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	//2 iterator_traits template specialization, 1 for each

   template <class T>
    struct iterator_traits {
        typedef typename T::value_type            value_type;
        typedef typename T::difference_type       difference_type;
        typedef typename T::iterator_category     iterator_category;
        typedef typename T::pointer               pointer;
        typedef typename T::reference             reference;

//my_function() for bidirectional iterators
 template <typename BidectionalIterator>
 void my_function (BidectionalIterator begin, BidirectionalIterator end,
                   std::bidirectional_iterator_tag)
 {
       //Bidirectional Iterator specific code is here
 }

//my_function() for random access iterators
 template <typename RandomIterator>
 void  my_function(RandomIterator begin, RandomIterator end,
                   std::random_access_iterator_tag)
 {

            // Random access Iterator specific code is here
 }


 //User always calls this method, general method for distance()

// User needs to satisfy the following 2 criteria: 
// For random access iterator, second iterator position must come 
// after first iterator position/
// For all other kind of iterator, second iterator must be reachable from first iterator
// Both of the iterator must refer to the same container, otherwise result is undefined
    template <typename Iterator>
    typename std::iterator_traits<Iterator>::difference_type
    distance (Iterator pos1, Iterator pos2)
    {
        return distance (pos1, pos2,
                         std::iterator_traits<Iterator>
                            ::iterator_category()); 
    }
 
    //Core implementation ..... distance() for random access iterators
    template <typename RandomAccessIterator>
    typename std::iterator_traits<RandomAccessIterator>::difference_type
    // Note the return type above, it solely depends on Iterators declared typedefs,
    // no so called INT/SHORT here
    distance (RandomAccessIterator first_position, RandomAccessIterator second_position,
               std::random_access_iterator_tag) 
    {
        return second_position - first_position; 
    }


    //distance() for input, forward, and bidirectional iterators
    // Keep in mind that here we are using only Input iterator tags, so
    // forward and bidirectional iterator will also be in this bucket, because we
    // used Inheritance while declare forward and bidirectional iterator tags.

    template <typename InputIterator>
    typename std::iterator_traits<lnputIterator>::difference_type
    // Note the return type here, truly generic
    distance (Inputlterator first_position, InputIterator second_position,
              std::input_iterator_tag) 
    {
        // note the type of the temp variable here, truly generic 
        typename std::iterator_traits<lnputIterator>::difference_type diff;
        for (diff=0; first_position != second_position; ++first_position, ++diff) {
             ;
        }
        return diff; 
    }  



	template<	typename Category,
				typename T,
				typename Distance=ptrdiff_t,
				typename Pointer=T*,
				typename Reference=T&,
			>
	class iterator {
		private:

		public:

	};
}

#endif