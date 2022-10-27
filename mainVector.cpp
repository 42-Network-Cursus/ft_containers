#include "vector.hpp"
#include <vector>
#include <algorithm>

template<typename Vector>
void	showData(Vector v) {
	typename Vector::iterator it = v.begin();
	typename Vector::iterator ite = v.end();
	
	while (it != ite) {
		std::cout << *it;
		it++;
		if (it != ite)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "VECTOR" << std::endl;
	std::cout << "CONSTRUCTORS\n" << std::endl;
	

	ft::vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	// v1.push_back(2);
	// v1.push_back(3);
	// v1.push_back(4);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	// v1.push_back(5);
	
	ft::vector<int>::iterator it = v1.begin();
	// ft::vector<int>::iterator ite = v1.end();
	std::cout << "size: " << v1.size() << " cap: " << v1.capacity() << std::endl;
	showData(v1);
	// it++;
	v1.insert(it, 500);
	std::cout << "size: " << v1.size() << " cap: " << v1.capacity() << std::endl;
	showData(v1);

	return 0;
}