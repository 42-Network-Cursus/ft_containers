#ifndef SET_HPP
# define SET_HPP

namespace ft 
{
	template<	typename T,
				typename Compare = std::less<T>
				typename Alloc = std::allocator<T>
			>
	class set
	{
		public:
		// CONSTRUCTORS
			explicit set (const key_compare& comp = key_compare(),              const allocator_type& alloc = allocator_type());
			
			template <class InputIterator>  
			set (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type());
			
			set (const set& x);
		// -------------------------------------------------------------------
		// DESTRUCTOR --------------------------------------------------------
			~set();
		// ASSIGMNEMT OPERATOR
			set& operator= (const set& x);

		// ITERATORS
			iterator begin();
			const_iterator begin() const;
			
			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			
			reverse_iterator rend();
			const_reverse_iterator rend() const;



		// METHODS
			bool empty() const;
			size_type max_size() const;
			size_type size() const;

			void clear();
			size_type count (const value_type& val) const;

			pair<iterator,iterator> equal_range (const value_type& val) const;

			void erase (iterator position);
			size_type erase (const value_type& val);
			void erase (iterator first, iterator last);
			
			iterator find (const value_type& val) const;

			allocator_type get_allocator() const;

			pair<iterator,bool> insert (const value_type& val);
			iterator insert (iterator position, const value_type& val);

			template <class InputIterator>  
			void insert (InputIterator first, InputIterator last);

			key_compare key_comp() const;
			value_compare value_comp() const;


			iterator lower_bound (const value_type& val) const;
			iterator upper_bound (const value_type& val) const;


			void swap (set& x);

		// NON MEMBER RELATIONAL OPERATORS
			template <class T, class Compare, class Alloc>  
			friend bool operator== ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

			template <class T, class Compare, class Alloc>  
			friend bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

			template <class T, class Compare, class Alloc>  
			friend bool operator<  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

			template <class T, class Compare, class Alloc>  
			friend bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

			template <class T, class Compare, class Alloc>  
			friend bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

			template <class T, class Compare, class Alloc>  
			friend bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
		// -----------------------------------------------------------------------------------------------

		private:
	}; // END class set

	template <class T, class Compare, class Alloc>  
	bool operator== ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

	template <class T, class Compare, class Alloc>  
	bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

	template <class T, class Compare, class Alloc>  
	bool operator<  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

	template <class T, class Compare, class Alloc>  
	bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

	template <class T, class Compare, class Alloc>  
	bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

	template <class T, class Compare, class Alloc>  
	bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
// -------------------------------------------------------------------------------------------
	
	template <class T, class Compare, class Alloc>  
	void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y);

} // END namespace ft

#endif // SET_HPP