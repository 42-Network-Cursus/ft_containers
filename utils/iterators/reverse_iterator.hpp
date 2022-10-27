#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

	template < typename Iterator > 
	class reverse_iterator {

		public:
			
			typedef  Iterator													iterator_type;

			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;

			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;

			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;

			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			// CONSTRUCTORS
			reverse_iterator() : _data() {}

			explicit reverse_iterator (iterator_type it) : _data(it) {}
	
			template < class Iter >  
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _data(rev_it.base()) {}

			iterator_type base() const {
				return (_data);
			}

			//		ADDING && SUBSTRACTING
			reverse_iterator operator- (difference_type n) const {
				return (reverse_iterator(_data + n));
			}

			reverse_iterator& operator--() {
				++_data;
				return (*this);
			}

			reverse_iterator  operator--(int) {
				reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			reverse_iterator& operator-= (difference_type n) {
				_data += n;
				return (*this);
			}

			reverse_iterator operator+ (difference_type n) const {
				return (reverse_iterator(_data - n));
			}

			reverse_iterator& operator++() {
				--_data;
				return (*this);
			}

			reverse_iterator  operator++(int) {
				reverse_iterator tmp = *this;
				--(*this);
				return tmp;
			}
			
			reverse_iterator& operator+= (difference_type n) {
				_data -= n;
				return (*this);
			}
			// ----------------------------------------------------

			//		ACCESS OPERATORS
			reference operator*() const {
				iterator_type	tmp = _data;
				return (*(--tmp));
			}

			pointer operator->() const {
				return &(operator*());
			}

			reference operator[] (difference_type n) const {
				return (base()[ -n - 1 ]);
			}
			// ----------------------------------------------------

			// 				FRIENDS
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
		
			template <class Iteratorx>  
			friend reverse_iterator<Iteratorx> operator+ (typename reverse_iterator<Iteratorx>::difference_type n, const reverse_iterator<Iteratorx>& rhs);
		
			template <class Iteratorx>  
			friend typename reverse_iterator<Iteratorx>::difference_type operator-(const reverse_iterator<Iteratorx>& lhs, const reverse_iterator<Iteratorx>& rhs);
			// ----------------------------------------------------------------------------------------------------------------------------------------------------

		private:

			iterator_type	_data;

	};

	// Non-member RELATIONAL OPERATORS
	template <class Iterator>  
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		if (lhs._data == rhs._data)
			return (true);
		return (false);
	}
	
	template <class Iterator>  
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		if (lhs._data != rhs._data)
			return (true);
		return (false);
	}
	
	template <class Iterator>  
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		if (lhs._data < rhs._data)
			return (true);
		return (false);
	}
	
	template <class Iterator>  
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		if (lhs._data <= rhs._data)
			return (true);
		return (false);
	}
	
	template <class Iterator>  
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		if (lhs._data > rhs._data)
			return (true);
		return (false);
	}
	
	template <class Iterator>  
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		if (lhs._data >= rhs._data)
			return (true);
		return (false);
	}

	template <class Iterator>  
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() - rhs.base());
	}

	template <class Iterator>  
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rhs) {
		return (rhs._data -= n);
	}

} // END namespace ft

#endif // REVERSE_ITERATOR_HPP