#ifndef MAP_HPP
# define MAP_HPP

//https://github.com/electronicarts/EASTL/blob/master/source/red_black_tree.cpp
// uses bidirectional iterator
namespace ft {
	template<	typename Key, 
				typename T, 
				typename Compare=less<Key>, 
				typename Alloc=allocator< pair<const Key, T> > 
			>
	class map {
		public:
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