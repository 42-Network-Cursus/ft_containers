#ifndef MAP_HPP
# define MAP_HPP

//https://github.com/electronicarts/EASTL/blob/master/source/red_black_tree.cpp
// uses bidirectional iterator
namespace ft {
	template<	typename Key, 
				typename T, 
				typename Compare = less<Key>, 
				typename Alloc = allocator< ft::pair<const Key, T> > 
			>
	class map {

		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;
			typedef	Compare											key_compare;
			//														value_compare
			typedef Alloc											allocator_type;

			typedef	allocator_type::reference						reference;
			typedef allocator_type::const_reference					const_reference;
			typedef allocator_type::pointer							pointer;
			typedef allocator_type::const_pointer					const_pointer;
			
			typedef ft::Random_access_iterator<value_type>			iterator;
			typedef ft::Random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;	
			typedef iterator_traits<iterator>::difference_type		difference_type;
			typedef size_t 											size_type;
			
			
			
			map();
			~map();
			operator=();

			// ITERATORS
			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;
			
			

			// CAPACITY
			// bool empty() const;
			// size_type size() const;
			// size_type max_size() const;

			//ELEMENT ACCESS
			// mapped_type& operator[] (const key_type& k);
		

			// MODIFIERS
			// insert..
			// erase...
			// void swap (map& x);
			// void clear();
			

			// OBSERVERS
			// key_compare key_comp() const;
			// value_compare value_comp() const;

			// OPERATIONS
			// iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;
			// size_type count (const key_type& k) const;
			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;
			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;
			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator>             equal_range (const key_type& k);

			// GET ALLOCATOR
			// allocator_type get_allocator() const;
	};
}
#endif