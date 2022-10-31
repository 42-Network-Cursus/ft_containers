#include <iostream>
#include <utility>

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

#include "stack.hpp"
#include "vector.hpp"

#include <typeinfo>     // typeid


int main() {

	// std::pair<int, char> pr(5, 'c');
	// assert(1 > 2);
	// std::cout << pr.first << std::endl;


	ft::vector<int> s1;
	ft::vector<int> s2;

	s1.push_back(5);
	s2.push_back(5);
	
	s1.push_back(4);
	s2.push_back(4);

	ft::vector<int>::iterator it = s1.begin();

	if (typeid(ft::iterator_traits<int*>::iterator_category) == typeid(ft::random_access_iterator_tag))
		std::cout << "OK\n";

	// iterator
}