#ifndef VECTOR_HPP
# define VECTOR_HPP

// # include <iostream> // needed?
# include <memory>
# include <stdexcept>

# include "utils/iterators/lexicographical_compare.hpp"
# include "utils/iterators/Random_access_iterator.hpp"
# include "utils/iterators/reverse_iterator.hpp"
# include "utils/iterators/equal.hpp"
# include "utils/exceptions.hpp"
# include "utils/enable_if.hpp"

namespace ft 
{	
	template<	typename T,
				typename Alloc = std::allocator<T>
			>  
	class vector 
	{
		public:
			typedef T 												value_type;
			typedef Alloc											allocator_type;
		// (const) Reference to value_type
			typedef typename Alloc::reference						reference;
			typedef	typename Alloc::const_reference					const_reference;
		// (const) Pointer to value_type
			typedef	typename Alloc::pointer							pointer;
			typedef	typename Alloc::const_pointer					const_pointer;

			typedef	size_t											size_type;
			typedef ptrdiff_t										difference_type;
			
			typedef ft::Random_access_iterator<value_type>			iterator;
			typedef ft::Random_access_iterator<const value_type>	const_iterator;
			
			typedef ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;	

		// CONSTRUCTORS
explicit	vector (const allocator_type& alloc = allocator_type())
			: _data(NULL), _alloc(alloc), _capacity(0), _size(0) {}
			
explicit	vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _data(NULL), _alloc(alloc), _capacity(0), _size(0) { resize(n, val); }
			
			template <typename Iterator>
			vector (Iterator first, 
					typename enable_if<!is_integral<Iterator>::value, Iterator>::type last, 
					const allocator_type& alloc = allocator_type() ) 
			: _data(NULL), _alloc(alloc), _capacity(0), _size(0) 
			{
				reserve(ft::distance(first, last));
				// _size = ft::distance(first, last) + 1; line fucked if size = 0 or 1
				for (int i = 0 ; first != last; first++, i++)
					_data[i] = *first;
			}
			
			vector (const vector& rhs)
			: _data(rhs._data), _alloc(rhs._alloc), _capacity(rhs._capacity), _size(rhs._size) {}
		
		// DESTRUCTOR
			~vector() 
			{
				clear();
				_alloc.deallocate(_data, _capacity);
			}
			
		// ASSIGMENT OPERATOR
			vector&	operator= (const vector& rhs) 
			{
				if (this != &rhs) {
					clear();
					_capacity = rhs.capacity();
					assign(rhs.begin(), rhs.end());
				}
  				return (*this);
			}
		// -----------------------------------------------------------------------------------------------------------

		// ITERATORS
     		iterator				begin ()			{ return ( iterator(_data) ); }
			const_iterator			begin ()	const	{ return ( const_iterator(_data) ); }

			iterator 				end ()				{ return ( iterator(&_data[ _size ]) ); }
			const_iterator			end ()		const	{ return ( const_iterator(&_data[ _size ]) ); }
			
			reverse_iterator		rbegin ()			{ return ( reverse_iterator( end() ) ); }
			const_reverse_iterator	rbegin ()	const	{ return ( const_reverse_iterator( end() ) ); }

			reverse_iterator		rend ()				{ return ( reverse_iterator( begin() ) ); }
			const_reverse_iterator	rend ()		const	{ return ( const_reverse_iterator( begin() ) ); }
		// -----------------------------------------------------------------------------------------------------------

		// METHODS
			// Returns number of elements (!! != capacity !!)
			size_type		size ()		const	{ return (_size); }

			// Returns max number of elements the vector could hold given OS specs
			size_type		max_size ()	const	{ return (_alloc.max_size() ); }

			// Allocated space for sizeof(value_type) elements
			size_type		capacity ()	const	{ return (_capacity); }
			allocator_type	get_alloc ()	const	{ return (_alloc); }
			bool			empty ()		const	{ return (_size == 0); }

			void	reserve (size_type n) 
			{
				if (n > max_size() )
					throw std::length_error("ft::vector reserve()");
				
				if (n > _capacity) {
					// pointer prev_data = _data;
					// size_type prev_capacity = _capacity; //2
					
					// if (_size)
					// 	std::cout << "prev data " << *prev_data << std::endl;
					// _data = _alloc.allocate(n);
					// if (_size)
					// 	std::cout << "prev data " << *prev_data << std::endl;
					// for (size_type i = 0; i < _size; i++)
					// 	_alloc.construct(_data + i, prev_data[i]);
					// _capacity = n;
					// _alloc.deallocate(prev_data, prev_capacity);
					//----------

			// if (this->_capacity < size)
			// 		{
					// allocated_size = closest_power_of_two(size);
					
					pointer	new_data;
					new_data = _alloc.allocate(n * 2);

					// if (_data != new_data) {
						for (size_type i = 0; i < _size; i++) {
							_alloc.construct(new_data + i, *(_data + i) );
							_alloc.destroy(_data + i);
						}
					// }
					// copyObjects(new_data, this->_data, this->_size);
					// if (_capacity)
					// try {

					// 	_alloc.deallocate(_data, _capacity);
					// }
					// catch(std::exception &e) 
					// {

					// }
					std::cout << "STOP HERE\n";
					_data = new_data;
					_capacity = n;
				}
		//-----
				
					// if (_size)
					// 	std::cout << "data " << *_data << std::endl;
					// pointer		newData = _alloc.allocate(n);
					// if (_size)
					// 	std::cout << "data " << *_data << std::endl;
					// iterator it = begin();
					// iterator ite = end();

					// for (int i = 0; it != ite; it++, i++)
					// 	_alloc.construct(newData + i, *it);
					// for (size_type i = 0; i < _size; i++)
					// 	_alloc.destroy(_data + i);
					// _alloc.deallocate(_data, _capacity);
					// _data = newData;
					// _capacity = n;
			}

			void	resize (size_type n, value_type val = value_type()) 
			{
				if (n < _size) {
					while (n < _size)
						pop_back();
				}
				else if (n > _size) {
                    if (n > _capacity)
                		reserve(n);
                    size_type prev_size = _size; 
                    _size = n;
                    for(size_type  i = prev_size; i < n; i++) {
                        _alloc.construct(_data + i, val);
                    }
                }
			}
		// -----------------------------------------------------------------------------------------------------------

		// ELEMENT ACCESS
			reference 			operator[] (size_type n)			{ return ( _data[n] ); }
			const_reference		operator[] (size_type n)	const	{ return ( _data[n] ); }

			reference 			front ()							{ return ( _data[0] ); }
			const_reference		front ()	const					{ return ( _data[0] ); }

			reference			back ()								{ return ( _data[ _size - 1] ); }
			const_reference 	back ()		const					{ return ( _data[ _size - 1] ); }
			
			reference 			at ( size_type n ) 
			{
				if ( n >= _size )
					throw OUTOFRANGE();
				return ( _data[n] );
			}

			const_reference 	at ( size_type n ) const 
			{
				if ( n >= _size )
					throw OUTOFRANGE();
				return ( _data[n] );
			}
		// -----------------------------------------------------------------------------------------------------------

		// MODIFIERS 
			template <class InputIterator>  
			void		assign (InputIterator first, 
								typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) 
			{
				clear();
				for (size_type i = 0; first != last; first++, i++, _size++)
					_data[i] = *first;
			}
			
			void		assign (size_type n, const value_type& val) 
			{
				while (_size)
						pop_back();
				resize(n, val);
			}

			void		push_back ( const value_type& val ) 
			{
				if ( _capacity <= _size ) {
					if (_size == 0)
						reserve(1);
					else
						reserve(_size * 2);
				}
				_data[_size] = val;
				_size++;
			}

			void		pop_back () 
			{
				_alloc.destroy( &(_data[_size - 1]) );
				_size--;
			}

			iterator	insert (iterator position, const value_type& val) 
			{
				if (_size == 0) {
					resize(1, val);
					return (iterator(_data));
				}

				size_type	pos	= distance(begin(), position);
				std::cout << "pos: " << pos << std::endl;
				size_type	prev_size = _size;
				std::cout << "size: " << _size << std::endl;
				std::cout << "cap: " << _capacity << std::endl;

				if (_capacity < _size + 1) {
					std::cout << "Reserve in insert\n";
					// std::cout << "data " << *_data << std::endl;
					reserve(_size * 2);
					std::cout << "size: " << _size << std::endl;
					std::cout << "cap: " << _capacity << std::endl;
				}
				for (; prev_size > pos; prev_size--)
					_data[prev_size + 1] = _data[prev_size];
				_data[prev_size + 1] = val;
				for (; prev_size != 0; --prev_size)
					_data[prev_size + 1] = _data[prev_size];
				_size += 1;
				return (iterator(_data));
			}

			void 		insert (iterator position, size_type n, const value_type& val) 
			{
				if (_capacity < _size + n) {
					pointer		prev_data = _data;
					size_type	prev_size = _size;
					
					pointer		newData = _alloc.allocate(_size + n);
					_capacity = _size + n;

					iterator	it = begin();
					iterator	ite = end();
					int 		i = 0;
					
					for ( ; it != position; i++, it++) {
						newData[i] = *_data;
						_alloc.destroy(_data++);
					}
					for (size_type j = 0; j < n; i++, j++)
						newData[i] = val;
					// for (; it != ite; i++, it++) {
					// 	newData[i] = *_data;
					// 	_alloc.destroy(_data++);
					// }
					_alloc.deallocate(prev_data, prev_size);
					_data = newData;
					_size = prev_size + n;
				}
				else if (_size == 0)
					resize(n, val);
			}

			template <class InputIterator>    
			void		insert (iterator position, 
							InputIterator first, 
							typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) 
			{
				if ( _capacity <= _size + distance(first, last) )
					reserve( ( _size + distance(first, last) ) );
				
				iterator			pos = position;
				vector<value_type>	tmp(position, end());
				
				for ( ; first != last; first++, pos++, _size++)
					*pos = *first;
				for (; tmp != tmp.end(); pos++, tmp++)
					*pos = *tmp;
				//PROBABLY FUCKED
			}

			iterator	 erase (iterator position) 
			{
				iterator pos = position;
				iterator begin = ++position; // if pos == end() ??

				_alloc.destroy(&(*position));
				_size--;
				for ( ; begin != end(); pos++, begin++)
					*pos = begin;
			}

			iterator	 erase (iterator first, iterator last) 
			{
				iterator pos = first;

				for ( ; first != last; first++, _size--)
					_alloc.destroy(&(*first));
				for ( ; last != end(); pos++, last++)
					*pos = last;
			}

			void		clear () 
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&(_data[i]));
				_size = 0;
			}
		// -----------------------------------------------------------------------------------------------------------

			void 			swap (vector& rhs) 
			{
				//Works ?? Nope, values of data not correct
				vector<value_type> tmp(rhs);

				rhs = *this;
				rhs._data = this->_data;

				*this = tmp;
				this->_data = tmp._data;
			}

		// RELATIONAL OPERATORS 
			template <class Tx, class Allocx>  
			friend bool operator==	(const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			template <class Tx, class Allocx> 
			friend bool operator!=	(const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			template <class Tx, class Allocx>  
			friend bool operator<	(const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);

			template <class Tx, class Allocx>  
			friend bool operator<=	(const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);
			
			template <class Tx, class Allocx>  
			friend bool operator>	(const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);
			
			template <class Tx, class Allocx>  
			friend bool operator>=	(const vector<Tx,Allocx>& lhs, const vector<Tx,Allocx>& rhs);
		// -----------------------------------------------------------------------------------------------------------

		private: // protected ?

			// Array used to store data. Grows dynamically depending on needs.
			pointer			_data;

			// Allocator used to dynamically grow memory needs for _data.
			allocator_type	_alloc;

			// Allocated space in memory
			size_type		_capacity;

			// Number of elements
			size_type		_size;

	}; // END class vector
	
// Non-member RELATIONAL OPERATORS
	template <class T, class Alloc>  
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) 
	{
		if (lhs.size() == rhs.size())
			return (equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class T, class Alloc>  
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }

	template <class T, class Alloc>  
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) 
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>  
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }
	
	template <class T, class Alloc>  
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }
	
	template <class T, class Alloc>  
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
// Non-member RELATIONAL OPERATORS
	
	template <class T, class Alloc>  
	void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs) 
	{

	}

} // END namespace ft

#endif // VECTOR_HPP