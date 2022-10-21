#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream> // needed?

# include <memory>
# include <stdexcept>

# include "utils/iterators/Random_access_iterator.hpp"
# include "utils/iterators/reverse_iterator.hpp"
# include "utils/exceptions.hpp"
# include "utils/enable_if.hpp"

namespace ft {	

	template<	typename T,
				typename Alloc = std::allocator<T>
			>  
	class vector {
	
		public:

			// First template parameter
			typedef T 																				value_type;

			// Second template parameter
			typedef Alloc																			allocator_type;

			// (const) Reference to value_type
			typedef typename Alloc::reference														reference;
			typedef	typename Alloc::const_reference													const_reference;

			// (const) Pointer to value_type
			typedef	typename Alloc::pointer															pointer;
			typedef	typename Alloc::const_pointer													const_pointer;

			// Iterators
			typedef ft::Random_access_iterator<value_type>											iterator;
			typedef ft::Random_access_iterator<const value_type>									const_iterator;
		
			// Reverse iterators
			typedef ft::reverse_iterator<ft::iterator< ft::random_access_iterator_tag, T > > 		reverse_iterator;
			typedef ft::reverse_iterator<ft::iterator< ft::random_access_iterator_tag, const T > >	const_reverse_iterator;

			typedef ptrdiff_t																		difference_type;
			typedef	size_t																			size_type;

			// 			CONSTRUCTORS
explicit	vector(const allocator_type& alloc = allocator_type())
			: _data(NULL), _allocator(alloc), _capacity(0), _size(0)  {}
			
explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _data(NULL), _allocator(alloc), _capacity(n), _size(0) {
				resize(n, val);
			}
			
			template <typename InputIterator>
			vector (InputIterator first, 
					typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, 
					const allocator_type& alloc = allocator_type() ) 
			: _data(NULL), _allocator(alloc), _capacity(0), _size(0) {
				reserve(ft::distance(first, last));
				for (int i = 0 ; first != last; first++, i++)
					_data[i] = *first;
			}
			
			vector (const vector& rhs)
			: _data(rhs._data), _allocator(rhs._allocator), _capacity(rhs._capacity), _size(rhs._size) {}
			// -------------------------------------------------------------------------------------------------------------

			// 		DESTRUCTOR
			~vector() {
				clear();
				_allocator.deallocate(_data, capacity() + 1);
			}
			
			// 		Assignment operator
			vector&	operator=(const vector& rhs) {
				if (this != &rhs) {
					this->clear();
					// this->_allocator.deallocate(_data, capacity() + 1);
					// this->_data = NULL;
					this->_allocator = rhs._allocator; // needed?
				}
				this->assign(rhs.begin(), rhs.end());
  				return (*this);
			}


			// **********ITERATORS*******************
     		iterator				begin() {
				iterator it(_data);
				return (it);
			}

			const_iterator			begin() const {
				const_iterator c_it(_data);
				return (c_it);
			}

			iterator 				end() {
				iterator it(_data);
				it += size();
				return (it);
			}

			const_iterator			end() const {
				const_iterator c_it(_data);
				c_it += size();
				return (c_it);
			}
			
			reverse_iterator		rbegin() {
				reverse_iterator rev_it(begin());
				return (rev_it);
			}
			
			// const_reverse_iterator	rbegin() const {
			// 	const_reverse_iterator c_rev_it(begin());
			// 	return (c_rev_it);
			// }

			// reverse_iterator		rend() {

			// }
			
			// const_reverse_iterator	rend() const {

			// }
			//--------------------------------------------------
			

			/**
			 * @returns number of elements
			 * ! not equal to storage capacity
			 */
			size_type	size() const {
				return (_size);
			}
			
			// @returns max number of elements the vector could hold given OS specs
			size_type	max_size() const { 
				return ( _allocator.max_size() ); 
			}

			void		resize(size_type n, value_type val = value_type()) {
				if (n < _size) {
					while (_size > n)
						pop_back();
				}
				else {
					if (n >= capacity()) {
						_data = _allocator.allocate(n + 1, _data);
						_capacity = n;
					}
					for ( ; _size < n; _size++)
						_allocator.construct(_data + _size, val);
				}
			}

			size_type	capacity() const {
				return (_capacity);
			}

			bool		empty() const {
				if ( this->size() != 0 )
					return ( false );
				return ( true );
			}

			void		reserve( size_type n ) {
				if (n > max_size() )
					throw std::length_error("Size too big");
				if (n > capacity() )
					resize(n);
			}

			// ELEMENT ACCESS
			reference 		operator[] (size_type n) {
				return ( _data[n] );
			}

			const_reference operator[] (size_type n) const {
				return ( _data[n] );
			}

			reference 		at ( size_type n ) {
				if (n >= _size)
					throw OUTOFRANGE();
				return ( _data[n] );
			}

			const_reference at ( size_type n ) const {
				if ( n >= _size )
					throw OUTOFRANGE();
				return ( _data[n] );
			}

			reference 		front() {
				return ( _data[0] );
			}

			const_reference	front() const {
				return ( _data[0] );
			}

			reference		back() {
				return ( _data[ this->size() - 1] );
			}

			const_reference back() const {
				// const T& ret = _data[ this->size() - 1]; DELETE IF CONST IMPLICIT CAST IS OK
				return ( _data[ this->size() - 1] );
			}

			// MODIFIERS
		
			template <class InputIterator>  
			void			assign (InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
				clear();
				for (size_type i = 0; first != last; first++, i++, _size++)
					_data[i] = *first;
			}
			
			void	assign (size_type n, const value_type& val) {
				while (_size > 0)
						pop_back();
				resize(n, val);
			}

			void		push_back( const value_type& val ) {
				if (capacity() <= size()) {
					reserve(size() * 3);
				}
				_data[size()] = val;
				_size++;
			}

			void	pop_back() {
				_allocator.destroy(&(_data[_size - 1]));
				_size--;
			}

			iterator insert (iterator position, const value_type& val) {
				if (capacity() <= size() + 1)
					reserve(size() * 3);
				
				iterator			pos = position;
				iterator			end = end();
				vector<value_type>	tmp(position, end);
				
				*pos = val;
				_size++;
				for (; tmp != end; pos++, tmp++)
					*pos = *tmp;
			}

			void insert (iterator position, size_type n, const value_type& val) {
				if (capacity() <= size() + n)
					reserve(size() * 3);
				
				iterator			pos = position;
				iterator			end = end();
				vector<value_type>	tmp(position, end);
				
				for (size_type i = 0; i < n; i++, pos++, _size++)
					*pos = val;
				for (; tmp != end; pos++, tmp++)
					*pos = *tmp;
			}

			template <class InputIterator>    
			void	insert (iterator position, 
							InputIterator first, 
							typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
				if (capacity() <= size() + distance(first, last))
					reserve((size() + distance(first, last)) * 3);
				
				iterator			pos = position;
				vector<value_type>	tmp(position, end());
				
				for ( ; first != last; first++, pos++, _size++)
					*pos = *first;
				for (; tmp != tmp.end(); pos++, tmp++)
					*pos = *tmp;
				//PROBABLY FUCKED
			}

			iterator erase (iterator position) {
				iterator pos = position;
				iterator begin = ++position; // if pos == end() ??

				_allocator.destroy(&(*position));
				_size--;
				for ( ; begin != end(); pos++, begin++)
					*pos = begin;
			}
			iterator erase (iterator first, iterator last) {
				iterator pos = first;

				for ( ; first != last; first++, _size--)
					_allocator.destroy(&(*first));
				for ( ; last != end(); pos++, last++)
					*pos = last;
			}

			void		clear() {
				for (size_type i = 0; i < size(); i++)
					_allocator.destroy(&(_data[i]));
				_size = 0;
			}

			// ALLOCATOR
			allocator_type get_allocator() const {
				return (_allocator);
			}

			void swap (vector& rhs) {
				//Works ?? Nope, values of data not correct
				vector<value_type> tmp(rhs);

				rhs = *this;
				rhs._data = this->_data;

				*this = tmp;
				this->_data = tmp._data;
			}

			/****************************** RELATIONAL OPERATORS ******************************/
			// template <class Tx, class Allocx>  
			// friend bool operator== (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			// template <class Tx, class Allocx> 
			// friend bool operator!= (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			// template <class Tx, class Allocx>  
			// friend bool operator<  (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			// template <class Tx, class Allocx>  
			// friend bool operator<= (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);
			
			// template <class Tx, class Allocx>  
			// friend bool operator>  (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);
			
			// template <class Tx, class Allocx>  
			// friend bool operator>= (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);
			// ---------------------------------------------------------------------------------

		private: // protected ?

			// Array used to store data. Grows dynamically depending on needs.
			value_type*		_data;

			// Allocator used to dynamically grow memory needs for _data.
			allocator_type	_allocator;

			// Allocated space in memory
			size_type		_capacity;

			// Number of elements
			size_type		_size;

	}; // END class vector
	

	// RELATIONAL OPERATORS
	// template <class T, class Alloc>  
	// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	// }

	// template <class T, class Alloc>  
	// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	// }

	// template <class T, class Alloc>  
	// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	// }

	// template <class T, class Alloc>  
	// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	// }
	
	// template <class T, class Alloc>  
	// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	// }
	
	// template <class T, class Alloc>  
	// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	// }

	//swap
	template <class T, class Alloc>  
	void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs) {

	}


} // END namespace ft

#endif // VECTOR_HPP