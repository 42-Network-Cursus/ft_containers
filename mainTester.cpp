#include <iostream>

#include "iterator.hpp"
#include <typeinfo> // typeid



int main() {

	// Iterator_traits
	// {
	// 	typedef ft::iterator_traits<const int*> traits;
	// 	if (typeid(traits::iterator_category)==typeid(ft::random_access_iterator_tag))
	// 	std::cout << "cosnt int* is a random-access iterator";
	// }
	// {
	// 	typedef ft::iterator_traits<int*> traits;
	// 	if (typeid(traits::iterator_category)==typeid(ft::random_access_iterator_tag))
	// 	std::cout << "int* is a random-access iterator";
	// }
	//--------

	// Iterator types
	ft::input_iterator<int>	it();
	ft::input_iterator<int>	itx(it);

	ft::input_iterator<int>	ite = it;
	return 0;
}