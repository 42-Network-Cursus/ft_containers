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
	// {
	// 	std::cout << "Default, no parameters constructor:\n";
	// 	std::vector<int>			std_int;
	// 	ft::vector<int>				ft_int;
	// 	std::vector<std::string>	std_string;
	// 	ft::vector<std::string>		ft_string;

	// 	std::cout << "std int : ";
	// 	std::cout << "Capacity: " << std_int.capacity() << ", ";
	// 	std::cout << "Size: " << std_int.size() << std::endl;
	// 	std::cout << "ft int : ";
	// 	std::cout << "Capacity: " << ft_int.capacity() << ", ";
	// 	std::cout << "Size: " << ft_int.size() << std::endl;
	// 	std::cout << std::endl;
	// 	std::cout << "std string : ";
	// 	std::cout << "Capacity: " << std_string.capacity() << ", ";
	// 	std::cout << "Size: " << std_string.size() << std::endl;
	// 	std::cout << "ft string : ";
	// 	std::cout << "Capacity: " << ft_string.capacity() << ", ";
	// 	std::cout << "Size: " << ft_string.size() << std::endl;
	// }

	// {
	// 	std::cout << "\nSize + value constructor:\n";
	// 	std::vector<char>			std_char(2, 'c');
	// 	ft::vector<char>			ft_char(2, 'c');
	// 	std::vector<std::string>	std_string(5, "test");
	// 	ft::vector<std::string>		ft_string(5, "test");
	
	// 	std::cout << "std char : ";
	// 	std::cout << "Capacity: " << std_char.capacity() << ", ";
	// 	std::cout << "Size: " << std_char.size() << std::endl;
	// 	std::cout << "Contents: "; showData(std_char);
	// 	std::cout << "ft char : ";
	// 	std::cout << "Capacity: " << ft_char.capacity() << ", ";
	// 	std::cout << "Size: " << ft_char.size() << std::endl;
	// 	std::cout << "Contents: "; showData(ft_char);
	// 	std::cout << std::endl;
	// 	std::cout << "std string : ";
	// 	std::cout << "Capacity: " << std_string.capacity() << ", ";
	// 	std::cout << "Size: " << std_string.size() << std::endl;
	// 	std::cout << "Contents: "; showData(std_string);
	// 	std::cout << "ft string : ";
	// 	std::cout << "Capacity: " << ft_string.capacity() << ", ";
	// 	std::cout << "Size: " << ft_string.size() << std::endl;
	// 	std::cout << "Contents: "; showData(ft_string);
	// }

	// {
	// 	std::cout << "yep\n";
	// }
	// {
	
		// std::cout << "\nIterator range constructor:\n";
		// std::vector<std::string> 			tmp(5, "test");
		// std::vector<std::string>::iterator	it1 = tmp.begin();
		// std::vector<std::string>::iterator	ite1 = tmp.end();

		// ft::vector<std::string> 			tmp2(5, "test");
		// ft::vector<std::string>::iterator it2 = tmp2.begin();
		// ft::vector<std::string>::iterator	ite2 = tmp2.end();

		// std::vector<std::string>			std_int(it1, ite1);
		// ft::vector<std::string>				ft_int(it2, ite2);
		// std::vector<std::string>	std_string(5, "test");
		// ft::vector<std::string>		ft_string(5, "test");
	
		// std::cout << "std int : ";
		// std::cout << "Capacity: " << std_int.capacity() << ", ";
		// std::cout << "Size: " << std_int.size() << std::endl;
		// std::cout << "Contents: "; showData(std_int);
		// std::cout << "ft char : ";
		// std::cout << "Capacity: " << ft_int.capacity() << ", ";
		// std::cout << "Size: " << ft_int.size() << std::endl;
		// std::cout << "Contents: "; showData(ft_int);
		
		// std::cout << std::endl;
		// std::cout << "std string : ";
		// std::cout << "Capacity: " << std_string.capacity() << ", ";
		// std::cout << "Size: " << std_string.size() << std::endl;
		// std::cout << "Contents: "; showData(std_string);
		// std::cout << "ft string : ";
		// std::cout << "Capacity: " << ft_string.capacity() << ", ";
		// std::cout << "Size: " << ft_string.size() << std::endl;
		// std::cout << "Contents: "; showData(ft_string);
	// }

	// std::vector<int>	v1(2, 200);
	// ft::vector<int>	ft_v1(3, 300);

	// std::vector<int>	v2(v1);
	// ft::vector<int>	ft_v2(ft_v1);

	// std::cout << &v1 << " " << &v2 << std::endl;
	// std::cout << &ft_v1 << " " << &ft_v2 << std::endl;

	// std::cout << "Capacity: " << v2.capacity() << ", ";
	// std::cout << "Size: " << v2.size() << std::endl;
	// std::cout << "Contents: "; showData(v2);
	// v2.assign(1, 5);
	// std::cout << "Capacity: " << v2.capacity() << ", ";
	// std::cout << "Size: " << v2.size() << std::endl;
	// std::cout << "Contents: "; showData(v2);

	// std::cout << "Capacity: " << ft_v2.capacity() << ", ";
	// std::cout << "Size: " << ft_v2.size() << std::endl;
	// std::cout << "Contents: "; showData(ft_v2);
	// ft_v2.assign(1, 5);
	// std::cout << "Capacity: " << ft_v2.capacity() << ", ";
	// std::cout << "Size: " << ft_v2.size() << std::endl;
	// std::cout << "Contents: "; showData(ft_v2);

	std::cout << "rbegin\n";
	ft::vector<int>	v1;
	v1.push_back(100);
	v1.push_back(200);
	v1.push_back(300);

	ft::vector<int>::reverse_iterator r_it = v1.rbegin();
	
	std::cout << *r_it << std::endl;



	return 0;
}