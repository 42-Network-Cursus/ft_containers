#include "map.hpp"
#include <map>
#include <utility>
typedef  ft::map<int, char>::reverse_iterator IT_IC;

int main()
{
// 	ft::map<int, char> mapTest;
// 	ft::pair<int, char> p = ft::make_pair(5, 'a');
	
// 	mapTest.insert(p);
// 	mapTest.insert(ft::make_pair(7, 'b') );
// 	mapTest.insert(ft::make_pair(2, 'c') );
// 	mapTest.insert(ft::make_pair(20, 'd') );
// 	mapTest.insert(ft::make_pair(6, 'e') );
// 	mapTest.insert(ft::make_pair(-1, 'e') );


// 	// mapTest.printMap();
// 	IT_IC it = mapTest.rbegin();
// 	IT_IC ite = mapTest.rend();
// 	std::cout << mapTest.size() << std::endl;
// 	std::cout << mapTest[0] << std::endl;
// 	std::cout << mapTest.size() << std::endl;
// 	// for (IT_IC itFor = mapTest.begin(); itFor != mapTest.end(); itFor++)
// 	// {
// 	// 	std::cout << *itFor << std::endl;
// 	// }

// std::cout << "---------------------\n";

	// ft::map<int, char> mapIns(mapTest);
	
	// mapIns.insert(it, ite);
	
	// mapIns.insert(*it);
	// it++;
	// mapIns.insert(*it);
	// it++;
	// mapIns.insert(*it);
	// it++;
	// mapIns.insert(*it);
	// it++;
	// mapIns.insert(*it);
	// for (IT_IC itFor = mapIns.rbegin(); itFor != mapIns.rend(); itFor++)
	// {
	// 	std::cout << *itFor << std::endl;
	// }
	


	// if (root->parent->value.first)
	// 	std::cout << root->parent->value << std::endl;
	// if (root->l_child)
	// 	std::cout << "L: " << root->l_child->value << std::endl;
	// if (root->r_child)
	// 	std::cout << "R: " << root->r_child->value << std::endl;
	// root = root->r_child;
	// if (root->l_child)
	// 	std::cout << "L: " << root->l_child->value << std::endl;
	// if (root->r_child)
	// 	std::cout << "R: " << root->r_child->value << std::endl;

	// for (IT_IC itFor = mapIns.begin(); itFor != mapIns.end(); itFor++)
	// {
	// 	std::cout << *itFor << std::endl;
	// }

	ft::map<int, char> map;

	int i;

	std::map<int, char> mapstd;

	mapstd.erase();

	for (i = 0;i < 10; i++)
		map.insert(ft::make_pair<int, char>(i, i));

	ft::map<int, char>::iterator it = map.begin();
	ft::map<int, char>::iterator ite = map.end();

	ft::map<int, char>::iterator er = map.begin();
	er++;
	er++;
	er++;
	map.erase(er);
	for (; it != ite; it++)
		std::cout << (*it).first << std::endl;
	return 0;
}