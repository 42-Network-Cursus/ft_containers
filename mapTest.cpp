#include <map>
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

	showData(map);
}