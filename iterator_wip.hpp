https://stackoverflow.com/questions/7758580/writing-your-own-stl-container/7759622#7759622





/*
input_iterator : public virtual iterator {
    iterator operator++(int); //postfix increment
    value_type operator*() const;
    pointer operator->() const;
    friend bool operator==(const iterator&, const iterator&);
    friend bool operator!=(const iterator&, const iterator&); 
};
//once an input iterator has been dereferenced, it is 
//undefined to dereference one before that.

output_iterator : public virtual iterator {
    reference operator*() const;
    iterator operator++(int); //postfix increment
};
//dereferences may only be on the left side of an assignment
//once an output iterator has been dereferenced, it is 
//undefined to dereference one before that.

forward_iterator : input_iterator, output_iterator {
    forward_iterator();
};
//multiple passes allowed

bidirectional_iterator : forward_iterator {
    iterator& operator--(); //prefix decrement
    iterator operator--(int); //postfix decrement
};

random_access_iterator : bidirectional_iterator {
    friend bool operator<(const iterator&, const iterator&);
    friend bool operator>(const iterator&, const iterator&);
    friend bool operator<=(const iterator&, const iterator&);
    friend bool operator>=(const iterator&, const iterator&);

    iterator& operator+=(size_type);
    friend iterator operator+(const iterator&, size_type);
    friend iterator operator+(size_type, const iterator&);
    iterator& operator-=(size_type);  
    friend iterator operator-(const iterator&, size_type);
    friend difference_type operator-(iterator, iterator);

    reference operator[](size_type) const;
};
*/
	ft::iterator<random_access_iterator_tag, T> it;
https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls/8054856
https://github.com/electronicarts/EASTL


	template <class Iterator> 
	class reverse_iterator {
		
	};









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
