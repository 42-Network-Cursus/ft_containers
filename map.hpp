#ifndef MAP_HPP
# define MAP_HPP


// uses bidirectional iterator
namespace ft {
	template<	typename Key, 
				typename T, 
				typename Compare=less<Key>, 
				typename Alloc=allocator< pair<const Key, T> > 
			>
	class map {

	};
}
#endif