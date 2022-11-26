#include "map.hpp"
#include <map>
#include <utility>
typedef  ft::map<int, char>::reverse_iterator IT_IC;

int main()
{
	ft::map<int, char> map;

	for (int i = 0; i < 10; i++)
		map.insert(ft::make_pair<int, char>(i, i));
	
	ft::map<int, char>::iterator pos = map.end();
	map.insert(pos, ft::make_pair<int, char>(15, 'h'));
	
	ft::map<int, char>::iterator it = map.begin();
	ft::map<int, char>::iterator ite = map.end();

	for (; it != ite; it++)
		std::cout << *it << std::endl;

	ft::map<int, char> const map2(map);

	ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> eqIt;

	eqIt = map2.equal_range(5);
	std::cout << *(eqIt.first) << std::endl;
	std::cout << *(eqIt.second) << std::endl;
	// std::cout << "LB: " << *(map2.upper_bound(-2)) << std::endl;
	return 0;
}