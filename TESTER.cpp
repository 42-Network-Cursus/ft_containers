#include <vector>
#include "vector.hpp"
#include <iostream>



int main()
{
	ft::vector<int> vec;
	
	// std.resize(8);
	// std.push_back("5");
	// std::cout << std.capacity() << std::endl;
	// std.clear();
	// std::cout << std.capacity() << std::endl;
	// std::cout << std[20] << std::endl;
	// std::cout << std.capacity() << std::endl;
	// try {
	// 	vec.at(5);
	// }
	// catch(vec::OUTOFRANGE& e) {
	// 	std::cout << "Error: " << e.what() << std::endl;
	// }

	// for (int i = 0; i < 15; i++)
	// 	std::cout << std[i] << std::endl;

	// std::cout << << std::endl;
	
	std::cout << "------- $(NS) TESTS -------"<< std::endl;	
	std::cout << std::boolalpha;

	std::cout << "Max size: " << vec.max_size() << std::endl;
	std::cout << "Empty: " << vec.empty() << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "push_back 4x" << std::endl;
	for (int i = 0; i < 5; i++)
		vec.push_back(i);
	std::cout << "Empty: " << vec.empty() << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "push_back 2x" << std::endl;
	vec.push_back(5);
	vec.push_back(6);
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "operator[5]: " << vec[5] << std::endl;
	std::cout << "At(5): " << vec.at(5) << std::endl;
	std::cout << "Front: " << vec.front() << std::endl;
	std::cout << "Back: " << vec.back() << std::endl;
	std::cout << "\n----------------------"<< std::endl;
	std::cout << "Data, ptr to all elements: ";
	int*	p = vec.data();
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << p[i] << ", ";
	std::cout << std::endl;
	std::cout << "Clear" << std::endl;
	vec.clear();
	std::cout << "Empty: " << vec.empty() << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	// std::cout << << std::endl;
	return 0;
}