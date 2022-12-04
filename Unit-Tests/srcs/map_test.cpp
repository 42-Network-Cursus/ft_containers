#include "test.hpp"

#define T1 int
#define T2 int
#define _pair TESTED_NAMESPACE::pair
#define TESTED_NAMESPACE::map _map

static int iter = 0;
// UTILS -----------------------------------------------------------------------------------

template <typename T>
std::string	printPair(const T &iterator, std::ofstream &FILE)
{
	FILE << "key: " << std::setw(2) << iterator->first;
	FILE << std::setw(0) << " | value: " << iterator->second;
	return ("");
}

template <typename T_MAP>
void	printContent(T_MAP const &mp, std::ofstream &FILE)
{
	FILE << "size: " << mp.size() << std::endl;
	FILE << "max_size: " << mp.max_size() << std::endl;

	typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
	FILE << "- CONTENT OF CONTAINER -" << std::endl;
	for (; it != ite; ++it)
		FILE << printPair(it, FILE) << std::endl;
}

template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param, std::ofstream &FILE)
{
	_map<int, int>::iterator ite = mp.end(), it[2];
	_pair<_map<int, int>::iterator, _map<int, int>::iterator> ft_range;

	FILE << "\t-- [" << iter++ << "] --" << std::endl;
	FILE << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	FILE << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], FILE)) << std::endl;
	FILE << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], FILE)) << std::endl;
	FILE << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param, std::ofstream &FILE)
{
	_map<int, int>::const_iterator ite = mp.end(), it[2];
	_pair<_map<int, int>::const_iterator, _map<int, int>::const_iterator> ft_range;

	FILE << "\t-- [" << iter++ << "] (const) --" << std::endl;
	FILE << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	FILE << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], FILE)) << std::endl;
	FILE << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], FILE)) << std::endl;
	FILE << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}
// -----------------------------------------------------------------------------------------
// TESTS -----------------------------------------------------------------------------------

void	map_test_1(std::ofstream &FILE)
{
	FILE << "----- TEST 1 -----" << std::endl;
	FILE << "Testing: Bounds" << std::endl;
	TIMER t(&FILE);

	std::list<_map<int, int>::value_type> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_map<int, int>::value_type(i + 1, (i + 1) * 3));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printContent(mp, FILE);

	ft_const_bound(mp, -10, FILE);
	ft_const_bound(mp, 1, FILE);
	ft_const_bound(mp, 5, FILE);
	ft_const_bound(mp, 10, FILE);
	ft_const_bound(mp, 50, FILE);

	printContent(mp, FILE);

	mp.lower_bound(3)->second = 404;
	mp.upper_bound(7)->second = 842;
	ft_bound(mp, 5, FILE);
	ft_bound(mp, 7, FILE);

	printContent(mp, FILE);
}

void	map_test_2(std::ofstream &FILE)
{
	FILE << "----- TEST 2 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);

	_map	mp;

	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;
	printSize(mp);

	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
			ft_comp(mp, it1, it2);

	printSize(mp);
}
void	map_test_3(std::ofstream &FILE)
{
	FILE << "----- TEST 16 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);
	
}
void	map_test_4(std::ofstream &FILE)
{
	FILE << "----- TEST 16 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);
	
}
void	map_test_5(std::ofstream &FILE)
{
	FILE << "----- TEST 16 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);
	
}

void	map_test_6(std::ofstream &FILE)
{
	FILE << "----- TEST 16 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);
	
}
void	map_test_7(std::ofstream &FILE)
{
	FILE << "----- TEST 16 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);
	
}
void	map_test_8(std::ofstream &FILE)
{
	FILE << "----- TEST 16 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);
	
}
void	map_test_9(std::ofstream &FILE)
{
	FILE << "----- TEST 16 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);
	
}
// -----------------------------------------------------------------------------------------

void	map_test()
{
	std::ofstream FILE("TEST-LOG/map/" F_OUT "map.txt");

	map_test_1(FILE);
	FILE << "################################################################################" << std::endl;
	// map_test_2(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_3(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_4(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_5(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_6(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_7(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_8(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_9(FILE);
	// FILE << "################################################################################" << std::endl;
	// // map_test_10(FILE); // SEGFAULT ON WINDOWS PC
	// // FILE << "############## ##################################################################" << std::endl;
	// map_test_11(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_12(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_13(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_14(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_15(FILE);
	// FILE << "################################################################################" << std::endl;
	// map_test_16(FILE);
	// FILE << "################################################################################" << std::endl;
}