#include "vector.hpp"
#include <iostream>
#include <vector>

template<typename Vector>
void	showData(Vector &v) 
{
	typename Vector::iterator it = v.begin();
	typename Vector::iterator ite = v.end();
	
	std::cout << "size: " << v.size() << ", cap: " << v.capacity() << std::endl;

	while (it != ite) {
		std::cout << *it;
		it++;
		if (it != ite)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	ft::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	ft::vector<int>::iterator it = v1.begin();
	ft::vector<int>::iterator ite = v1.end();

	v1.insert(it, it, ite);

	showData(v1);


}