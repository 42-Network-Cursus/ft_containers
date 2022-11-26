#include <iostream>

#include <vector>
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

	
	// ft::Random_access_iterator<int>	it;
	// ft::Random_access_iterator<int>	ite;
	// for (int i = 0; i < 5; i++)
	// 	it.toData((i * 10), i);

	// *it = 50;

	// std::cout << "[] " << it[0] << std::endl;
	// std::cout << *it << std::endl;
	// std::cout << *(it - 1) << std::endl;
	// std::cout << *it  << std::endl;



	// -----------------------------------------
	// std::vector<int> test;

	// for (int i = 1; i < 5; i++)
	// 	test.push_back(i);
	// std::vector<int>::iterator it = test.begin();

	// std::cout << *it << std::endl;
	// std::cout << *(it + 2) << std::endl;
	// std::cout << *it << std::endl;

	// std::vector<int>::iterator ite = test.begin();
	// std::cout << &it << std::endl;
	// std::cout << (it == ite) << std::endl;
	// it++;
	// std::cout << &it << std::endl;
	// std::cout << (it == ite) << std::endl;




	return 0;
}