#include "test.hpp"

#define  _set TESTED_NAMESPACE::set<T1>
#define  _it _set::iterator
#define  _c_it _set::const_iterator
#define _pair		TESTED_NAMESPACE::pair

// UTILS -----------------------------------------------------------------------------------

template <typename T_SET>
void	printContent(T_SET const &mp, std::ofstream &FILE)
{
	FILE << "size: " << mp.size() << std::endl;
	FILE << "max_size: " << mp.max_size() << std::endl;

	typename T_SET::const_iterator it = mp.begin(), ite = mp.end();
	FILE << "- CONTENT OF CONTAINER -" << std::endl;
	for (; it != ite; ++it)
		FILE << *it << std::endl;
}

template <typename SET, typename T>
void	ft_bound(SET &st, const T &x, std::ofstream &FILE)
{
	typename SET::iterator ite = st.end(), it[2];
	_pair<typename SET::iterator, typename SET::iterator> ft_range;

	FILE << "key [" << x << "]:" << std::endl;
	it[0] = st.lower_bound(x); it[1] = st.upper_bound(x);
	ft_range = st.equal_range(x);
	FILE << "lower_bound: " << (it[0] == ite ? "end()" : it[0]) << std::endl;
	FILE << "upper_bound: " << (it[1] == ite ? "end()" : it[1], false) << std::endl;
	FILE << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename SET, typename T>
void	ft_const_bound(const SET &st, const T &x, std::ofstream &FILE)
{
	typename SET::const_iterator ite = st.end(), it[2];
	_pair<typename SET::const_iterator, typename SET::const_iterator> ft_range;

	FILE << "key [" << x << "]:" << std::endl;
	it[0] = st.lower_bound(x); it[1] = st.upper_bound(x);
	ft_range = st.equal_range(x);
	FILE << "lower_bound: " << (it[0] == ite ? "end()" : it[0]) << std::endl;
	FILE << "upper_bound: " << (it[1] == ite ? "end()" : it[1]) << std::endl;
	FILE << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}
// -----------------------------------------------------------------------------------------
// TESTS -----------------------------------------------------------------------------------

void	set_test_1(std::ofstream& FILE)
{
	typedef int T1;

	FILE << "----- TEST 1 -----" << std::endl;
	FILE << "Testing: Bounds" << std::endl;
	FILE << "T1: int, T2: int" << std::endl;
	TIMER t(&FILE);

	std::list<T1> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back((i + 1) * 3);
	_set st(lst.begin(), lst.end());
	printContent(st, FILE);

	ft_const_bound(st, -10, FILE);
	ft_const_bound(st, 1, FILE);
	ft_const_bound(st, 5, FILE);
	ft_const_bound(st, 10, FILE);
	ft_const_bound(st, 50, FILE);

	printContent(st, FILE);

	ft_bound(st, 5, FILE);
	ft_bound(st, 7, FILE);

	printContent(st, FILE);
}

void	set_test_(std::ofstream& FILE)
{
	typedef int T1;
	typedef int T2;
	
	FILE << "----- TEST 1 -----" << std::endl;
	FILE << "Testing: Bounds" << std::endl;
	FILE << "T1: int, T2: int" << std::endl;
	TIMER t(&FILE);
}

void	set_test()
{
	std::ofstream FILE;

	set_test_1(FILE);
	FILE << "################################################################################" << std::endl;
	// set_test_2(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_3(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_4(FILE);
	// FILE << "################################################################################" << std::endl;
	// // set_test_5(FILE);
	// // FILE << "################################################################################" << std::endl;
	// set_test_6(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_7(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_8(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_9(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_10(FILE);
	// FILE << "############## ##################################################################" << std::endl;
	// set_test_11(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_12(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_13(FILE);
	// FILE << "################################################################################" << std::endl;
	// set_test_14(FILE);
	// FILE << "################################################################################" << std::endl;
	// // set_test_15(FILE);
	// // FILE << "################################################################################" << std::endl;
	// // set_test_16(FILE);
	// // FILE << "################################################################################" << std::endl;
	
}