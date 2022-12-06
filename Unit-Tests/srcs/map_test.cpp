#include "Unit-Test.hpp"

#define _pair		TESTED_NAMESPACE::pair
#define _map		TESTED_NAMESPACE::map<T1, T2>
#define _it			_map::iterator
#define _c_it		_map::const_iterator
#define _val_type	_map::value_type

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
void	ft_bound(MAP &mp, const int &param, std::ofstream &FILE)
{
	typedef int T1;
	typedef int T2;

	typename _it ite = mp.end(), it[2];
	_pair<typename _it, typename _it> ft_range;

	FILE << "key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	FILE << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], FILE)) << std::endl;
	FILE << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], FILE)) << std::endl;
	FILE << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const int &param, std::ofstream &FILE)
{
	typedef int T1;
	typedef int T2;

	typename _c_it ite = mp.end(), it[2];
	_pair<typename _c_it, typename _c_it> ft_range;

	FILE << "key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	FILE << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], FILE)) << std::endl;
	FILE << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], FILE)) << std::endl;
	FILE << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_comp(const MAP &mp, const typename MAP::const_iterator &it1, const typename MAP::const_iterator &it2, std::ofstream &FILE)
{
	bool res[2];

	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	FILE << "[" << it1->first << " and " << it2->first << "]: ";
	FILE << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

template <typename MAP, typename IT>
void	ft_erase(std::ofstream &FILE, MAP &mp, IT x)
{
	mp.erase(x);
	printContent(mp, FILE);
}

template <typename MAP, typename IT1, typename IT2>
void	ft_erase(std::ofstream &FILE, MAP &mp, IT1 x, IT2 y)
{
	mp.erase(x, y);
	printContent(mp, FILE);
}

template <typename MAP, typename T>
void	ft_find(MAP& mp, T const &k, std::ofstream &FILE)
{
	typename MAP::iterator ret = mp.find(k);
	typename MAP::iterator it = mp.end();

	if (ret != it)
		printPair(ret, FILE);
	else
		FILE << "map::find(" << k << ") returned end()" << std::endl;
}

template <typename MAP, typename T>
void	ft_insert(MAP &mp, T x, std::ofstream& FILE)
{
	_pair<typename MAP::iterator, bool> tmp;

	tmp = mp.insert(x);
	FILE << "insert return: " << printPair(tmp.first, FILE);
	FILE << "Created new node: " << tmp.second << std::endl;
	printContent(mp, FILE);
}

template <typename MAP, typename T1, typename T2>
void	ft_insert(MAP &mp, T1 x, T2 y, std::ofstream& FILE)
{
	typename MAP::iterator tmp;

	tmp = mp.insert(x, y);
	FILE << "insert return: " << printPair(tmp, FILE);
	printContent(mp, FILE);
}

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs, std::ofstream& FILE)
{
	static int i = 0;

	FILE << "############### [" << i++ << "] ###############"  << std::endl;
	FILE << "==: " << (lhs == rhs) << " | !=: " << (lhs != rhs) << std::endl;
	FILE << " <: " << (lhs <  rhs) << " | <=: " << (lhs <= rhs) << std::endl;
	FILE << " >: " << (lhs >  rhs) << " | >=: " << (lhs >= rhs) << std::endl;
}
// -----------------------------------------------------------------------------------------
// TESTS -----------------------------------------------------------------------------------

void	map_test_1(std::ofstream &FILE)
{
	typedef int T1;
	typedef int T2;
	FILE << "----- TEST 1 -----" << std::endl;
	FILE << "Testing: Bounds" << std::endl;
	FILE << "T1: int, T2: int" << std::endl;
	TIMER t(&FILE);

	std::list<_val_type> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_val_type(i + 1, (i + 1) * 3));
	_map mp(lst.begin(), lst.end());
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
	typedef char	T1;
	typedef float	T2;

	FILE << "----- TEST 2 -----" << std::endl;
	FILE << "Testing: [] operator, assignment & relational operators" << std::endl;
	FILE << "T1: char, T2: float" << std::endl;
	TIMER t(&FILE);

	_map	mp;

	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;
	printContent(mp, FILE);

	for (_c_it it1 = mp.begin(); it1 != mp.end(); ++it1)
		for (_c_it it2 = mp.begin(); it2 != mp.end(); ++it2)
			ft_comp(mp, it1, it2, FILE);
}

void	map_test_3(std::ofstream &FILE)
{
	typedef int T1;
	typedef int T2;

	FILE << "----- TEST 3 -----" << std::endl;
	FILE << "Testing: Assignment" << std::endl;
	FILE << "T1: int, T2: int" << std::endl;
	TIMER t(&FILE);

	std::list<_pair<const T1, T2> > lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_pair<const T1, T2>(lst_size - i, i));

	_map mp(lst.begin(), lst.end());
	_it it = mp.begin(), ite = mp.end();

	_map mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	_map mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	FILE << "\t-- PART ONE --" << std::endl;
	printContent(mp, FILE);
	printContent(mp_range, FILE);
	printContent(mp_copy, FILE);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	FILE << "\t-- PART TWO --" << std::endl;
	printContent(mp, FILE);
	printContent(mp_range, FILE);
	printContent(mp_copy, FILE);
	
}
void	map_test_4(std::ofstream &FILE)
{
	typedef char	T1;
	typedef int		T2;

	FILE << "----- TEST 4 -----" << std::endl;
	FILE << "Testing: Empty, clear" << std::endl;
	FILE << "T1: char, T2: int" << std::endl;
	TIMER t(&FILE);
	
	std::list<_pair<const T1, T2> > lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_pair<const T1, T2>('a' + i, lst_size - i));

	_map mp(lst.begin(), lst.end()), mp2;
	_map::iterator it;

	lst.clear();
	FILE << "is_empty: " << mp.empty() << std::endl;
	printContent(mp, FILE);
	FILE << "is_empty: " << mp2.empty() << std::endl;

	mp2 = mp;
	FILE << "is_empty: " << mp2.empty() << std::endl;


	it = mp.begin();
	for (unsigned long int i = 3; i < mp.size(); ++i)
		it++->second = i * 7;

	printContent(mp, FILE);
	printContent(mp2, FILE);

	mp2.clear();
	FILE << "is_empty: " << mp2.empty() << std::endl;
	printContent(mp2, FILE);
}

void	map_test_5(std::ofstream &FILE)
{
	typedef char	T1;
	typedef int		T2;

	FILE << "----- TEST 5 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);

	std::list<_pair<const T1, T2> > lst;

	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_pair<const T1, T2>('a' + i, lst_size - i));
	_map foo(lst.begin(), lst.end());

	lst.clear(); lst_size = 4;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_pair<const T1, T2>('z' - i, i * 5));
	_map bar(lst.begin(), lst.end());

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

void	map_test_6(std::ofstream &FILE)
{
	typedef int				T1;
	typedef std::string		T2;

	FILE << "----- TEST 6 -----" << std::endl;
	FILE << "Testing: Erase" << std::endl;
	FILE << "T1: int, T2: string" << std::endl;
	TIMER t(&FILE);
	
	std::list<_pair<const T1, T2> > lst;
	unsigned int lst_size = 6;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_pair<const T1, T2>(i, std::string((lst_size - i), i + 65)));
	_map mp(lst.begin(), lst.end());
	printContent(mp, FILE);

	for (int i = 2; i < 4; ++i)
		ft_erase(FILE, mp, i);

	ft_erase(FILE, mp, mp.begin()->first);
	ft_erase(FILE, mp, (--mp.end())->first);

	mp[-1] = "Hello";
	mp[10] = "Hi there";
	mp[10] = "Hi there";
	printContent(mp, FILE);

	ft_erase(FILE, mp, 0);
	ft_erase(FILE, mp, 1);
}

void	map_test_7(std::ofstream &FILE)
{
	typedef int				T1;
	typedef std::string		T2;

	FILE << "----- TEST 7 -----" << std::endl;
	FILE << "Testing: Find, count" << std::endl;
	FILE << "T1: int, T2: string" << std::endl;
	TIMER t(&FILE);

	_map mp;

	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printContent(mp, FILE);

	FILE << "\t-- FIND --" << std::endl;
	ft_find(mp, 12, FILE);
	ft_find(mp, 3, FILE);
	ft_find(mp, 35, FILE);
	ft_find(mp, 90, FILE);
	ft_find(mp, 100, FILE);

	FILE << "\t-- COUNT --" << std::endl;
	FILE << "map::count(-3)\treturned [" << mp.count(-3) << "]" << std::endl;
	FILE << "map::count(12)\treturned [" << mp.count(12) << "]" << std::endl;
	FILE << "map::count(3)\treturned [" << mp.count(3) << "]" << std::endl;
	FILE << "map::count(35)\treturned [" << mp.count(35) << "]" << std::endl;
	FILE << "map::count(90)\treturned [" << mp.count(90) << "]" << std::endl;
	FILE << "map::count(100)\treturned [" << mp.count(100) << "]" << std::endl;

	mp.find(27)->second = "newly inserted mapped_value";

	printContent(mp, FILE);

	_map const c_map(mp.begin(), mp.end());
	FILE << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
	FILE << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;
	
}

void	map_test_8(std::ofstream &FILE)
{
	typedef int				T1;
	typedef std::string		T2;
	typedef _map::value_type T3;

	FILE << "----- TEST 8 -----" << std::endl;
	FILE << "Testing: Insert" << std::endl;
	FILE << "T1: int, T2: string" << std::endl;
	TIMER t(&FILE);

	_map mp, mp2;

	ft_insert(mp, T3(42, "lol"), FILE);
	ft_insert(mp, T3(42, "mdr"), FILE);

	ft_insert(mp, T3(50, "mdr"), FILE);
	ft_insert(mp, T3(35, "funny"), FILE);

	ft_insert(mp, T3(45, "bunny"), FILE);
	ft_insert(mp, T3(21, "fizz"), FILE);
	ft_insert(mp, T3(38, "buzz"), FILE);

	ft_insert(mp, mp.begin(), T3(55, "fuzzy"), FILE);

	ft_insert(mp2, mp2.begin(), T3(1337, "beauty"), FILE);
	ft_insert(mp2, mp2.end(), T3(1000, "Hello"), FILE);
	ft_insert(mp2, mp2.end(), T3(1500, "World"), FILE);
	
}

void	map_test_9(std::ofstream &FILE)
{
	typedef float	T1;
	typedef int		T2;

	FILE << "----- TEST 9 -----" << std::endl;
	FILE << "Testing: Increment & decrement" << std::endl;
	TIMER t(&FILE);
	
	std::list<_pair<const T1, T2> > lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_pair<const T1, T2>(2.5 + i, i + 1));

	_map mp(lst.begin(), lst.end());
	_it it(mp.begin());
	_c_it ite(mp.begin());
	printContent(mp, FILE);

	FILE << "-- ++ const_it --" << std::endl;
	printPair(++ite, FILE);
	FILE << std::endl;
	printPair(ite++, FILE);
	FILE << std::endl;
	printPair(ite++, FILE);
	FILE << std::endl;
	printPair(++ite, FILE);
	FILE << std::endl;

	it = mp.begin();
	ite = mp.begin();

	FILE << "-- ++ it --" << std::endl;
	printPair(++it, FILE);
	FILE << std::endl;
	printPair(it++, FILE);
	FILE << std::endl;
	printPair(it++, FILE);
	FILE << std::endl;
	printPair(++it, FILE);
	FILE << std::endl;

	it = mp.end();
	ite = mp.end();

	FILE << "-- -- const_it --" << std::endl;
	printPair(--ite, FILE);
	FILE << std::endl;
	printPair(ite--, FILE);
	FILE << std::endl;
	printPair(--ite, FILE);
	FILE << std::endl;
	printPair(ite--, FILE);
	FILE << std::endl;

	it = mp.end();
	ite = mp.end();

	FILE << "-- -- it --" << std::endl;
	printPair(--it, FILE);
	FILE << std::endl;
	printPair(it--, FILE);
	FILE << std::endl;
	printPair(it--, FILE);
	FILE << std::endl;
	printPair(--it, FILE);
	FILE << std::endl;
}

void	map_test_10(std::ofstream &FILE)
{
	typedef char			T1;
	typedef std::string		T2;

	FILE << "----- TEST 10 -----" << std::endl;
	FILE << "Testing: insert with []" << std::endl;

	_map mp;

	mp['a'] = "an element";
	mp['b'] = "another element";
	mp['c'] = mp['b'];
	mp['b'] = "old element";

	printContent(mp, FILE);

	FILE << "insert a new element via operator[]: " << mp['d'] << std::endl;

	printContent(mp, FILE);
}

void	map_test_11(std::ofstream &FILE)
{
	typedef char	T1;
	typedef int		T2;

	FILE << "----- TEST 11 -----" << std::endl;
	FILE << "Testing: Relational operators" << std::endl;
	TIMER t(&FILE);
	
	_map mp1;
	_map mp2;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	cmp(mp1, mp1, FILE);
	cmp(mp1, mp2, FILE);

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	cmp(mp1, mp2, FILE);
	cmp(mp2, mp1, FILE);

	(++(++mp1.begin()))->second = 42;

	cmp(mp1, mp2, FILE);
	cmp(mp2, mp1, FILE);

	swap(mp1, mp2);

	cmp(mp1, mp2, FILE);
	cmp(mp2, mp1, FILE);
}

void	map_test_12(std::ofstream &FILE)
{
	typedef int	T1;
	typedef int		T2;

	FILE << "----- TEST 12 -----" << std::endl;
	FILE << "Testing: Reverse iterator" << std::endl;
	FILE << "No output, checks for compile error" << std::endl;
	TIMER t(&FILE);

	_map mp;
	_it it = mp.begin();
	_c_it cit = mp.begin();

	_map::reverse_iterator rit(it);

	_map::const_reverse_iterator crit(rit);
	_map::const_reverse_iterator crit_(it);
	_map::const_reverse_iterator crit_2(cit);
	
}

void	map_test_13(std::ofstream &FILE)
{
	typedef char	T1;
	typedef int		T2;

	FILE << "----- TEST 13 -----" << std::endl;
	FILE << "Testing: Reverse iterator" << std::endl;
	TIMER t(&FILE);

	std::list<_pair<const T1, T2> > lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(_pair<const T1, T2>('a' + i, (i + 1) * 7));

	_map mp(lst.begin(), lst.end());
	_it it_ = mp.begin();
	_map::reverse_iterator it(it_), ite;
	printContent(mp, FILE);


	printPair(it.base(), FILE);

	FILE << "\nTEST OFFSET" << std::endl;
	--it;
	printPair(it, FILE);

	it = mp.rbegin(); ite = mp.rend();
	while (it != ite)
		FILE << "\n[rev] " << printPair(it++, FILE) << std::endl;
	printContent(mp, FILE);
	
}
// -----------------------------------------------------------------------------------------

void	map_test()
{
	std::ofstream FILE("TEST-LOG/map/" F_OUT "map.txt");

	map_test_1(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_2(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_3(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_4(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_5(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_6(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_7(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_8(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_9(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_10(FILE);
	FILE << "############## ##################################################################" << std::endl;
	map_test_11(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_12(FILE);
	FILE << "################################################################################" << std::endl;
	map_test_13(FILE);
	FILE << "################################################################################" << std::endl;
}