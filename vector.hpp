#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream> // needed?

# include <memory>
# include <stdexcept>
# include "Random_access_iterator.hpp"

/************************************/
/*									*/
/*									*/
/*									*/
/************************************/

namespace ft {	

	template<	typename T,
				typename Alloc = std::allocator<T>
			>  
	class vector {
	
		public:

			// First template parameter
			typedef T 												value_type;

			// Second template parameter
			typedef Alloc											allocator_type;

			// (const) Reference to value_type
			typedef typename Alloc::reference						reference;
			typedef	typename Alloc::const_reference					const_reference;

			// (const) Pointer to value_type
			typedef	typename Alloc::pointer							pointer;
			typedef	typename Alloc::const_pointer					const_pointer;

			// Iterators
			typedef ft::Random_access_iterator<value_type>			iterator;
			typedef ft::Random_access_iterator<const value_type>	const_iterator;
		
			//TO IMPLEMENT
			std::reverse_iterator<std::iterator< std::random_access_iterator_tag, T > > reverse_iterator;
			std::reverse_iterator<std::iterator< std::random_access_iterator_tag, const T > > const_reverse_iterator;
			//-------------

			typedef ptrdiff_t										difference_type;
			typedef	size_t											size_type;

			// 		CONSTRUCTORS
			explicit vector (const allocator_type& alloc = allocator_type()) {}
			
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {}
			
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {}
			
			vector (const vector& rhs) {}
			
			// 		DESTRUCTOR
			~vector() {}
			
			// 		Assignment operator
			vector& operator=(const vector& rhs) {}


			// ITERATORS
     		// iterator begin();
			// const_iterator begin() const;
			// end();
			// rbegin();
			// rend();
			
			// cbegin(); C++11
			// cend();   C++11
			
			// crbegin(); C++11
			// crend(); C++11


			/************************************/
			/*									*/
			/*			   CAPACITY				*/
			/*									*/
			/************************************/

			/**
			 * @returns number of elements
			 * ! not equal to storage capacity
			 */
			size_type	size() const {
				size_type	i = 0;

				while ( _data[i] )
					i++;
				return ( i );
			}

			// @returns max number of elements the vector can hold
			size_type	max_size() const { 
				return ( _allocator.max_size() ); 
			}

			void		resize(size_type n, value_type val = value_type()) {
				// if (n < this->size())
				// 	//reduce content to first n elements, delete the rest
				// else
				// {
				// 	if (n > this->capacity())
				// 		//reallocate
				// 	//expand up to n elements, initialized as copies of val
				// }
			}

			size_type	capacity() const {
				//use private member to count ?
				return 0;
			}

			bool		empty() const {
				if ( this->size() != 0 )
					return ( false );
				return ( true );
			}

			void		reserve( size_type n ) {
				// if (n > this->capacity() )
					//reallocate
			}

			// void		shrink_to_fit() {     C++11
			// 	// if (this->capacity() > this->size() )
			// 		//deallocate
			// }

			// ELEMENT ACCESS
			reference 		operator[] (size_type n) {
				return ( _data[n] );
			}

			const_reference operator[] (size_type n) const {
				return ( _data[n] );
			}

			reference 		at ( size_type n ) {
				if ( n >= this->size() )
					throw OUTOFRANGE();
				return ( _data[n] );
			}

			const_reference at ( size_type n ) const {
				if ( n >= this->size() )
					throw OUTOFRANGE();
				return ( _data[n] );
			}

			reference 		front() {
				return ( _data[0] );
			}

			const_reference	front() const {
				// const T& ret = _data[ this->size() - 1]; DELETE IF CONST IMPLICIT CAST IS OK
				return ( _data[0] );
			}

			reference		back() {
				return ( _data[ this->size() - 1] );
			}

			const_reference back() const {
				return ( _data[ this->size() - 1] );
			}
			
			// value_type* 		data() { C++11
			// 	return ( _data );
			// }

			// const value_type*	data() const { C++11
			// 	return ( _data );
			// }

			// MODIFIERS
			// assign();
			void		push_back( const value_type& val ) {
				// if (//size too small)
					//allocate
				_data[this->size()] = val;
			}
			// pop_back();
			// insert();
			// erase();
			void		clear() {
				for (size_type i = 0; i < this->size(); i++)
					_data[i] = 0;
			}

			// emplace();  C++11
			// emplace_back(); C++11

			// ALLOCATOR
			// get_allocator();

			void swap (vector& rhs) {

			}

			// NON-MEMBER FUNCTION OPERATOR OVERLOADS
			template <class Tx, class Allocx>  
			friend bool operator== (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			template <class Tx, class Allocx> 
			friend bool operator!= (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			template <class Tx, class Allocx>  
			friend bool operator<  (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			template <class Tx, class Allocx>  
			friend bool operator<= (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);
			
			template <class Tx, class Allocx>  
			friend bool operator>  (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);
			
			template <class Tx, class Allocx>  
			friend bool operator>= (const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

		private:

			// Array used to store data. Grows dynamically depending on needs.
			value_type*		_data;

			// Allocator used to dynamically grow memory needs for _data.
			allocator_type	_allocator;

	}; // END class vector
	

	// RELATIONAL OPERATORS
	template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}

	template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}

	template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}

	template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}
	
	template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}
	
	template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}

	//swap
	template <class T, class Alloc>  
	void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs) {

	}


} // END namespace ft

#endif // VECTOR_HPP