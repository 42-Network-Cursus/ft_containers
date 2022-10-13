#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {

	template < typename Iterator > 
	class reverse_iterator {

		public:
			
			typedef Iterator													iterator_type;

			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;

			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;

			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;

			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			// CONSTRUCTORS
			reverse_iterator() {}

			explicit reverse_iterator (iterator_type it) {}
	
			template < class Iter >  
			reverse_iterator (const reverse_iterator<Iter>& rev_it) {}


			iterator_type base() const;
			reference operator*() const;
			reverse_iterator operator+ (difference_type n) const;
			reverse_iterator& operator++();
			reverse_iterator  operator++(int);
			reverse_iterator& operator+= (difference_type n);
			reverse_iterator operator- (difference_type n) const;
			reverse_iterator& operator--();
			reverse_iterator  operator--(int);
			reverse_iterator& operator-= (difference_type n);
			pointer operator->() const;
			reference operator[] (difference_type n) const;


			template <class Iteratorx>  
			friend bool operator== (const reverse_iterator<Iteratorx>& lhs, const reverse_iterator<Iteratorx>& rhs);
			
			template <class Iteratorx>  
			friend bool operator!= (const reverse_iterator<Iteratorx>& lhs, const reverse_iterator<Iteratorx>& rhs);
			
			template <class Iteratorx>  
			friend bool operator<  (const reverse_iterator<Iteratorx>& lhs, const reverse_iterator<Iteratorx>& rhs);
			
			template <class Iteratorx>  
			friend bool operator<= (const reverse_iterator<Iteratorx>& lhs, const reverse_iterator<Iteratorx>& rhs);
			
			template <class Iteratorx>  
			friend bool operator>  (const reverse_iterator<Iteratorx>& lhs, const reverse_iterator<Iteratorx>& rhs);
			
			template <class Iteratorx>  
			friend bool operator>= (const reverse_iterator<Iteratorx>& lhs, const reverse_iterator<Iteratorx>& rhs);
	

	};

	// Non-member RELATIONAL OPERATORS
	template <class Iterator>  
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {

	}
	
	template <class Iterator>  
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {

	}
	
	template <class Iterator>  
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {

	}
	
	template <class Iterator>  
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {

	}
	
	template <class Iterator>  
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {

	}
	
	template <class Iterator>  
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {

	}



} // END namespace ft

#endif // REVERSE_ITERATOR_HPP