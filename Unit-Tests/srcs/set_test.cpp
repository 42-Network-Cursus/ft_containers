#include "Unit-Test.hpp"

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
	FILE << "lower_bound: ";
	if (it[0] == ite)
		FILE << "end()"; 
	else
		FILE << *it[0];
	FILE << std::endl;
	FILE << "upper_bound: ";
	if (it[1] == ite)
		FILE << "end()"; 
	else
		FILE << *it[1];
	FILE << std::endl;
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
	FILE << "lower_bound: ";
	if (it[0] == ite)
		FILE << "end()"; 
	else
		FILE << *it[0];
	FILE << std::endl;
	FILE << "upper_bound: ";
	if (it[1] == ite)
		FILE << "end()"; 
	else
		FILE << *it[1];
	FILE << std::endl;
	FILE << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename SET, typename C_IT>
void	ft_comp(const SET &st, const C_IT &it1, const C_IT &it2, std::ofstream &FILE)
{
	bool res[2];

	res[0] = st.key_comp()(*it1, *it2);
	res[1] = st.value_comp()(*it1, *it2);
	FILE << "[" << *it1 << " and " << *it2 << "]: ";
	FILE << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

template <typename SET, typename T>
void	ft_erase(SET &st, T x, std::ofstream &FILE)
{
	st.erase(x);
	printContent(st, FILE);
}

template <typename SET, typename T1, typename T2>
void	ft_erase(SET &st, T1 x, T2 y, std::ofstream &FILE)
{
	st.erase(x, y);
	printContent(st, FILE);
}

template <typename SET, typename T>
void	ft_find(SET &st, T const &k, std::ofstream &FILE)
{
	typename SET::iterator ret = st.find(k);
	typename SET::iterator ite = st.end();

	if (ret != ite)
		FILE << "value: " << *ret << std::endl;
	else
		FILE << "set::find(" << k << ") returned end()" << std::endl;
}

template <typename SET, typename T>
void	ft_insert(SET &st, T x, std::ofstream &FILE)
{
	_pair<typename SET::iterator, bool> tmp;

	tmp = st.insert(x);
	FILE << "insert return: " << *(tmp.first) << std::endl;
	FILE << "Created new node: " << tmp.second << std::endl;
	printContent(st, FILE);
}

template <typename SET, typename T1, typename T2>
void	ft_insert(SET &st, T1 x, T2 y, std::ofstream &FILE)
{
	typename SET::iterator tst;

	tst = st.insert(x, y);
	FILE << "insert return: " << *tst << std::endl;
	printContent(st, FILE);
}

template <class SET>
void	cst(const SET &lhs, const SET &rhs, std::ofstream &FILE)
{
	FILE << "-------------"  << std::endl;
	FILE << "==: " << (lhs == rhs) << " | !=: " << (lhs != rhs) << std::endl;
	FILE << " <: " << (lhs <  rhs) << " | <=: " << (lhs <= rhs) << std::endl;
	FILE << " >: " << (lhs >  rhs) << " | >=: " << (lhs >= rhs) << std::endl;
}
// -----------------------------------------------------------------------------------------
// TESTS -----------------------------------------------------------------------------------

void	set_test_1(std::ofstream& FILE)
{
	typedef int T1;

	FILE << "----- TEST 1 -----" << std::endl;
	FILE << "Testing: Bounds" << std::endl;
	FILE << "T1: int" << std::endl;
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

void	set_test_2(std::ofstream& FILE)
{
	typedef char T1;
	
	FILE << "----- TEST 2 -----" << std::endl;
	FILE << "Testing: Key_comp, value_comp" << std::endl;
	FILE << "T1: char" << std::endl;
	TIMER t(&FILE);

	_set	st;

	st.insert('a');
	st.insert('b');
	st.insert('c');
	st.insert('d');
	printContent(st, FILE);

	for (_c_it it1 = st.begin(); it1 != st.end(); ++it1)
		for (_c_it it2 = st.begin(); it2 != st.end(); ++it2)
			ft_comp(st, it1, it2, FILE);

	printContent(st, FILE);
}

void	set_test_3(std::ofstream& FILE)
{
	typedef int T1;
	
	FILE << "----- TEST 3 -----" << std::endl;
	FILE << "Testing: Copy constructor" << std::endl;
	FILE << "T1: int" << std::endl;
	TIMER t(&FILE);

	std::list<T1> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(lst_size - i);

	_set st(lst.begin(), lst.end());
	_it it = st.begin(), ite = st.end();

	_set st_range(it, --(--ite));
	for (int i = 0; i < 5; ++i)
		st.insert(i * 5);

	it = st.begin(); ite = --(--st.end());
	_set st_copy(st);
	for (int i = 0; i < 7; ++i)
		st.insert(i * 7);

	FILE << "\t-- PART ONE --" << std::endl;
	printContent(st, FILE);
	printContent(st_range, FILE);
	printContent(st_copy, FILE);

	st = st_copy;
	st_copy = st_range;
	st_range.clear();

	FILE << "\t-- PART TWO --" << std::endl;
	printContent(st, FILE);
	printContent(st_range, FILE);
	printContent(st_copy, FILE);
}

void	set_test_4(std::ofstream& FILE)
{
	typedef char T1;
	
	FILE << "----- TEST 4 -----" << std::endl;
	FILE << "Testing: Empty, clear" << std::endl;
	FILE << "T1: char" << std::endl;
	TIMER t(&FILE);

	std::list<T1> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('a' + i);

	_set st(lst.begin(), lst.end()), st2;
	_it it;

	lst.clear();
	FILE << "is_empty: " << st.empty() << std::endl;
	printContent(st, FILE);

	FILE << "is_empty: " << st2.empty() << std::endl;
	st2 = st;
	FILE << "is_empty: " << st2.empty() << std::endl;


	it = st.begin();
	for (unsigned long int i = 3; i < 6; ++i)
		st.insert(i * 7);

	printContent(st, FILE);
	printContent(st2, FILE);

	st2.clear();
	FILE << "is_empty: " << st2.empty() << std::endl;
	printContent(st2, FILE);
}

void	set_test_5(std::ofstream& FILE)
{
	typedef int T1;
	
	FILE << "----- TEST 5 -----" << std::endl;
	FILE << "Testing: Erase" << std::endl;
	FILE << "T1: int" << std::endl;
	TIMER t(&FILE);

	std::list<T1> lst;
	unsigned int lst_size = 6;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(i);
	_set st(lst.begin(), lst.end());
	printContent(st, FILE);

	for (int i = 2; i < 4; ++i)
		ft_erase(st, i, FILE);

	ft_erase(st, *st.begin(), FILE);
	ft_erase(st, *(--st.end()), FILE);

	st.insert(-1);
	st.insert(10);
	st.insert(10);
	printContent(st, FILE);

	ft_erase(st, 0, FILE);
	ft_erase(st, 1, FILE);
	printContent(st, FILE);
}

void	set_test_6(std::ofstream& FILE)
{
	typedef int T1;
	
	FILE << "----- TEST 6 -----" << std::endl;
	FILE << "Testing: Find, count" << std::endl;
	FILE << "T1: int" << std::endl;
	TIMER t(&FILE);

	_set st;

	st.insert(42);
	st.insert(25);
	st.insert(80);
	st.insert(12);
	st.insert(27);
	st.insert(90);
	printContent(st, FILE);

	FILE << "\t-- FIND --" << std::endl;
	ft_find(st, 12, FILE);
	ft_find(st, 3, FILE);
	ft_find(st, 35, FILE);
	ft_find(st, 90, FILE);
	ft_find(st, 100, FILE);

	FILE << "\t-- COUNT --" << std::endl;
	FILE << "set::count(-3)\treturned [" << st.count(-3) << "]" << std::endl;
	FILE << "set::count(12)\treturned [" << st.count(12) << "]" << std::endl;
	FILE << "set::count(3)\treturned [" << st.count(3) << "]" << std::endl;
	FILE << "set::count(35)\treturned [" << st.count(35) << "]" << std::endl;
	FILE << "set::count(90)\treturned [" << st.count(90) << "]" << std::endl;
	FILE << "set::count(100)\treturned [" << st.count(100) << "]" << std::endl;

	st.erase(st.find(27));

	printContent(st, FILE);

	_set const c_set(st.begin(), st.end());
	FILE << "const set.find(" << 42 << ")->second: [" << *(c_set.find(42)) << "]" << std::endl;
	FILE << "const set.count(" << 80 << "): [" << c_set.count(80) << "]" << std::endl;
}

void	set_test_7(std::ofstream& FILE)
{
	typedef std::string T1;
	
	FILE << "----- TEST 7 -----" << std::endl;
	FILE << "Testing: insert" << std::endl;
	FILE << "T1: string" << std::endl;
	TIMER t(&FILE);

	_set st, st2;

	ft_insert(st, "lol", FILE);
	ft_insert(st, "mdr", FILE);

	ft_insert(st, "mdr", FILE);
	ft_insert(st, "funny", FILE);

	ft_insert(st, "bunny", FILE);
	ft_insert(st, "fizz", FILE);
	ft_insert(st, "buzz", FILE);

	ft_insert(st, st.begin(), "fuzzy", FILE);

	ft_insert(st2, st2.begin(), "beauty", FILE);
	ft_insert(st2, st2.end(), "Hello", FILE);
	ft_insert(st2, st2.end(), "World", FILE);
}

void	set_test_8(std::ofstream& FILE)
{
	typedef int T1;
	
	FILE << "----- TEST 8 -----" << std::endl;
	FILE << "Testing: Insert" << std::endl;
	FILE << "T1: int" << std::endl;
	TIMER t(&FILE);

	std::list<T1> lst;
	std::list<T1>::iterator itlst;

	lst.push_back(42);

	lst.push_back(50);
	lst.push_back(35);

	lst.push_back(45);
	lst.push_back(21);
	lst.push_back(38);
	lst.push_back(55);

	FILE << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		FILE << *itlst << std::endl;

	_set st;
	st.insert(lst.begin(), lst.end());
	printContent(st, FILE);

	lst.clear();

	lst.push_back(87);
	lst.push_back(47);
	lst.push_back(35);
	lst.push_back(23);
	lst.push_back(1);
	lst.push_back(100);
	lst.push_back(55);

	FILE << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		FILE << *itlst << std::endl;
}

void	set_test_9(std::ofstream& FILE)
{
	typedef int T1;
	
	FILE << "----- TEST 9 -----" << std::endl;
	FILE << "Testing: Increment, decrement it" << std::endl;
	FILE << "T1: int" << std::endl;
	TIMER t(&FILE);

	std::list<T1> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(2.5 + i);

	_set st(lst.begin(), lst.end());
	_it it(st.begin());
	_c_it ite(st.begin());
	printContent(st, FILE);

	FILE << "++ const it" << std::endl;
	FILE << *(++ite) << std::endl;
	FILE << *(ite++) << std::endl;
	FILE << *(ite++) << std::endl;
	FILE << *(++ite) << std::endl;

	it = st.begin();
	ite = st.begin();

	FILE << "++ const it" << std::endl;
	FILE << *(++it) << std::endl;
	FILE << *(it++) << std::endl;
	FILE << *(it++) << std::endl;
	FILE << *(++it) << std::endl;

	it = st.end();
	ite = st.end();
	
	FILE << "++ const it" << std::endl;
	FILE << *(--ite) << std::endl;
	FILE << *(ite--) << std::endl;
	FILE << *(--ite) << std::endl;
	FILE << *(ite--) << std::endl;

	it = st.end();
	ite = st.end();

	FILE << "++ const it" << std::endl;
	FILE << *(--it) << std::endl;
	FILE << *(it--) << std::endl;
	FILE << *(it--) << std::endl;
	FILE << *(--it) << std::endl;
}

void	set_test_10(std::ofstream& FILE)
{
	typedef char T1;
	
	FILE << "----- TEST 10 -----" << std::endl;
	FILE << "Testing: Relational operators" << std::endl;
	FILE << "T1: char" << std::endl;
	TIMER t(&FILE);

	_set st1;
	_set st2;

	st1.insert('a');
	st1.insert('b');
	st1.insert('c');
	st1.insert('d');
	st2.insert('a');
	st2.insert('b');
	st2.insert('c');
	st2.insert('d');

	cst(st1, st1, FILE);
	cst(st1, st2, FILE);

	st2.insert('e');
	st2.insert('f');
	st2.insert('h');
	st2.insert('h');

	cst(st1, st2, FILE);
	cst(st2, st1, FILE);

	swap(st1, st2);

	cst(st1, st2, FILE);
	cst(st2, st1, FILE);
}

void	set_test_11(std::ofstream& FILE)
{
	typedef int T1;
	
	FILE << "----- TEST 11 -----" << std::endl;
	FILE << "Testing: Reverse iterator" << std::endl;
	FILE << "T1: int" << std::endl;
	TIMER t(&FILE);

	std::list<T1> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back((i + 1) * 7);

	_set st(lst.begin(), lst.end());
	_it it_ = st.begin();
	_set::reverse_iterator it(it_), ite;
	printContent(st, FILE);

	FILE << (it_ == it.base()) << std::endl;

	FILE << *(it.base()) << std::endl;

	FILE << "TEST OFFSET" << std::endl;
	--it;
	FILE << *(it) << std::endl;
	FILE << *(it.base()) << std::endl;

	it = st.rbegin(); ite = st.rend();
	while (it != ite)
		FILE << "[rev] " << *(it++) << std::endl;
}

void	set_test_12(std::ofstream& FILE)
{
	typedef char T1;
	
	FILE << "----- TEST 12 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	FILE << "T1: char" << std::endl;
	TIMER t(&FILE);

	std::list<T1> lst;

	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('a' + i);
	_set foo(lst.begin(), lst.end());

	lst.clear(); lst_size = 4;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back('z' - i);
	_set bar(lst.begin(), lst.end());

	_c_it it_foo = foo.begin();
	_c_it it_bar = bar.begin();

	FILE << "BEFORE SWAP" << std::endl;

	FILE << "foo contains:" << std::endl;
	printContent(foo, FILE);
	FILE << "bar contains:" << std::endl;
	printContent(bar, FILE);

	foo.swap(bar);

	FILE << "AFTER SWAP" << std::endl;

	FILE << "foo contains:" << std::endl;
	printContent(foo, FILE);
	FILE << "bar contains:" << std::endl;
	printContent(bar, FILE);

	FILE << "Iterator validity:" << std::endl;
	FILE << (it_foo == bar.begin()) << std::endl;
	FILE << (it_bar == foo.begin()) << std::endl;
}

void	set_test()
{
	std::ofstream FILE("TEST-LOG/set/" F_OUT "set.txt");

	set_test_1(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_2(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_3(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_4(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_5(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_6(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_7(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_8(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_9(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_10(FILE);
	FILE << "############## ##################################################################" << std::endl;
	set_test_11(FILE);
	FILE << "################################################################################" << std::endl;
	set_test_12(FILE);
	FILE << "################################################################################" << std::endl;
}