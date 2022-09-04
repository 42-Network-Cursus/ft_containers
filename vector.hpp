#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream> // needed?

# include <memory>
# include <stdexcept>

namespace ft {	

	template<	typename T, 
				typename Alloc = std::allocator<T> 
			>  
	class vector
	{
		private:

			// Array used to store data. Grows dynamically depending on needs.
			T*		_data;

			// Allocator used to dynamically grow memory needs for _data.
			Alloc	_allocator;

		protected:

		public:

			// First template parameter
			typedef T 								value_type;

			// Second template parameter
			typedef typename Alloc::value_type		allocator_type;

			// (const) Reference to value_type
			typedef typename Alloc::reference		reference;
			typedef	typename Alloc::const_reference	const_reference;

			// (const) Pointer to value_type
			typedef	typename Alloc::pointer			pointer;
			typedef	typename Alloc::const_pointer	const_pointer;

			//TODO
			//iterators ! Probably need to implement them
			std::iterator< std::random_access_iterator_tag, T > iterator;
			std::iterator< std::random_access_iterator_tag, const T > const_iterator;
			std::reverse_iterator<std::iterator< std::random_access_iterator_tag, T > > reverse_iterator;
			std::reverse_iterator<std::iterator< std::random_access_iterator_tag, const T > > const_reverse_iterator;
			// typedef	iterator<T>						iterator;
			// typedef iterator<const T>				const_iterator;
			//ENDTODO

			typedef ptrdiff_t						difference_type;
			typedef	size_t							size_type;

			//MAYBE TODO
			// class iterator : public std::iterator< std::random_access_iterator_tag, T >
			// {
				
			// };

			// class reverse_iterator : public std::reverse_iterator<iterator>
			// {

			// };
			//ENDTODO

			vector(): _data( new T[10] ) {}
			// ~vector();
			//copy constr.
			// operator=();


			// ITERATORS
     		// iterator begin();
			// const_iterator begin() const;
			// end();
			// rbegin();
			// rend();
			// cbegin();
			// cend();
			// crbegin();
			// crend();

			// CAPACITY

			
			size_type	size() const {
				size_type	i = 0;

				while ( _data[i] )
					i++;
				return ( i );
			}

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

			void		shrink_to_fit() {
				// if (this->capacity() > this->size() )
					//deallocate
			}

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
			
			value_type* 		data() {
				return ( _data );
			}

			const value_type*	data() const {
				return ( _data );
			}

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
			// swap();
			void		clear() {
				for (size_type i = 0; i < this->size(); i++)
					_data[i] = 0;
			}

			// emplace();
			// emplace_back();

			// ALLOCATOR
			// get_allocator();

			// NON-MEMBER FUNCTION OVERLOADS
			// relational operators... (keyword friend)
			// swap();

	};
}

#endif