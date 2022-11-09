#include "vector.hpp"
#include <vector>
int main()
{
	ft::vector<int> vec(5, 5);

	ft::vector<int>::iterator it = vec.begin();

	ft::vector<int>::const_iterator c_it(it);

	return 0;
}