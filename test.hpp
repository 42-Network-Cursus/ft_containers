#include <vector>

class test : public std::vector
{
	public:
		void	show() {
			std::cout << _data << std::endl;
		}
};