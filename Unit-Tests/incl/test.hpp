#ifndef TEST_HPP
# define TEST_HPP

# include "../../Containers/vector.hpp"
# include "../../Containers/map.hpp"
# include "../../Containers/set.hpp"
# include "../../Containers/stack.hpp"

# include <vector>
# include <map>
# include <set>
# include <stack>
# include <list>

# include <fstream>
# include <iostream>
# include <iomanip>

# if defined(USING_STD)
#  define TESTED_NAMESPACE std
#  define NS_STR "std"
#  define F_OUT "std_"
# else
#  define TESTED_NAMESPACE ft
#  define NS_STR "ft"
#  define F_OUT "ft_"
# endif

void	vector_test();
void	stack_test();
void	set_test();
void	map_test();

# include <sys/time.h>

class TIMER
{
	public:
		TIMER(std::ofstream *F)
		: FILE(F)
		{
			gettimeofday(&begin, 0);
		}

		~TIMER() 
		{
			gettimeofday(&end, 0);
			long seconds = end.tv_sec - begin.tv_sec;
			long microseconds = end.tv_usec - begin.tv_usec;
			double elapsed = seconds + microseconds * 1E-6;
			*FILE << "Execution time: " << elapsed << std::endl;
		}
	private:
		struct timeval begin;
		struct timeval end;

		std::ofstream *FILE;
};

#endif // TEST_HPP