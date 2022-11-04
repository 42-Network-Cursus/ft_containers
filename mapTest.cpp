#include <map>
#include "map.hpp"
#include <iostream>

template<typename map>
void	showData(map v) {
	typename map::iterator it = v.begin();
	typename map::iterator ite = v.end();
	
	while (it != ite) {
		std::cout << it->first;
		it++;
		if (it != ite)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	std::map<int, char> map;

	map.insert(std::make_pair(5, 'a'));
	map.insert(std::make_pair(4, 'b'));
	map.insert(std::make_pair(8, 'c'));
	map.insert(std::make_pair(7, 'd'));
	map.insert(std::make_pair(15, 'e'));

	std::map<int, char>::iterator it = map.begin();

	it++;
	std::cout << it->first << std::endl;

	showData(map);

	// ft::map<int, char>	map;

	// std::cout << "EMPTY: " << map.empty() << std::endl;
	// std::cout << "SIZE: " << map.size() << std::endl;
	// std::cout << "MAX_SIZE: " << map.max_size() << std::endl;
	
	// std::allocator< ft::pair<int, char> > alloc = map.get_allocator();
	// std::cout << "GET_ALLOCATOR: " << alloc.max_size() << std::endl; 

	// ft::pair<ft::Random_access_iterator<ft::pair<const int, char> >, bool > pair = map.insert(ft::make_pair<int, char>(5, 'c'));
	// std::cout << *(pair.first) << std::endl;
}