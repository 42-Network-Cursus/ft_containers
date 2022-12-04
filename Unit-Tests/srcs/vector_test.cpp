#include "test.hpp"

#define TESTED_TYPE int
#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

// UTILS ---------------------------------------------------------------------------
template <typename T>
void	printContent(TESTED_NAMESPACE::vector<T> const &vct, std::ofstream &FILE)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";

	FILE << "size: " << size << std::endl;
	FILE << "capacity: " << isCapacityOk << std::endl;
	FILE << "max_size: " << vct.max_size() << std::endl;

	typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
	typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
	FILE << "- CONTENT OF CONTAINER -" << std::endl;
	for (; it != ite; ++it)
		FILE << *it << std::endl;
}

void	checkErase(TESTED_NAMESPACE::vector<std::string> const &vct,
					TESTED_NAMESPACE::vector<std::string>::const_iterator const &it,
					std::ofstream &FILE)
{
	static int i = 0;
	FILE << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printContent(vct, FILE);
}

void	incr_decr_test(TESTED_NAMESPACE::vector<TESTED_TYPE> &vct, std::ofstream &FILE)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

	FILE << "Pre inc" << std::endl;
	it_tmp = ++it;
	FILE << *it_tmp << " | " << *it << std::endl;

	FILE << "Pre dec" << std::endl;
	it_tmp = --it;
	FILE << *it_tmp << " | " << *it << std::endl;

	FILE << "Post inc" << std::endl;
	it_tmp = it++;
	FILE << *it_tmp << " | " << *it << std::endl;

	FILE << "Post dec" << std::endl;
	it_tmp = it--;
	FILE << *it_tmp << " | " << *it << std::endl;
	FILE << "-------------------------------------" << std::endl;
}

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs, std::ofstream &FILE)
{
	FILE << "---------------"  << std::endl;
	FILE << "==: " << (lhs == rhs) << " | !=: " << (lhs != rhs) << std::endl;
	FILE << " <: " << (lhs <  rhs) << " | <=: " << (lhs <= rhs) << std::endl;
	FILE << " >: " << (lhs >  rhs) << " | >=: " << (lhs >= rhs) << std::endl;
}
// ---------------------------------------------------------------------------------
// TESTS ---------------------------------------------------------------------------

void	vector_test_1(std::ofstream &FILE)
{
	FILE << "----- TEST 1 -----" << std::endl;
	FILE << "Testing: default constructor (w/ size as param), adding elements, assign()" << std::endl;
	TIMER t(&FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	printContent(vct, FILE);
	printContent(vct_two, FILE);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	FILE << "\t### After assign(): ###" << std::endl;

	printContent(vct, FILE);
	printContent(vct_two, FILE);
	printContent(vct_three, FILE);
	printContent(vct_four, FILE);

	vct_four.assign(6, 84);
	printContent(vct_four, FILE);

	FILE << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	printContent(vct, FILE);
	printContent(vct_two, FILE);
}

void	vector_test_2(std::ofstream &FILE)
{
	FILE << "----- TEST 2 -----" << std::endl;
	FILE << "Testing: at, front & back" << std::endl;
	TIMER t(&FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		FILE << "vct.at(): ";
		if (i > 3)
			FILE << " ";
		FILE << vct.at(i) << " | ";
		FILE << "vct[]: " << vct[i] << std::endl;
	}
	printContent(vct, FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

	FILE << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	FILE << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	try {
		vct.at(10) = 42;
	}
	catch (std::out_of_range &e) {
		FILE << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		FILE << "Catch exception: " << e.what() << std::endl;
	}
}

void	vector_test_3(std::ofstream &FILE)
{
	FILE << "----- TEST 3 -----" << std::endl;
	FILE << "Testing: CONST at, front & back" << std::endl;
	TIMER t(&FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		FILE << "vct[]: " << vct[i] << std::endl;
	}
	printContent(vct, FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

	FILE << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	FILE << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	for (unsigned long int i = 0; i < vct_c.size(); ++i)
		FILE << "vct_c.at(): " << vct_c.at(i) << std::endl;
	try {
		FILE << vct_c.at(10) << std::endl;
	}
	catch (std::out_of_range &e) {
		FILE << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		FILE << "Catch exception: " << e.what() << std::endl;
	}
	printContent(vct_c, FILE);
}

void	vector_test_4(std::ofstream &FILE)
{
	FILE << "----- TEST 4 -----" << std::endl;
	FILE << "Testing: Construct w/ list iterator as param" << std::endl;
	TIMER t(&FILE);

	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printContent(vct, FILE);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printContent(vct, FILE);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printContent(vct, FILE);
}

void	vector_test_5(std::ofstream &FILE)
{
	FILE << "----- TEST 5 -----" << std::endl;
	FILE << "Testing: Copy constructor, iterator range constructor & clear" << std::endl;
	TIMER t(&FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

	FILE << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	FILE << "\t-- PART ONE --" << std::endl;
	printContent(vct, FILE);
	printContent(vct_range, FILE);
	printContent(vct_copy, FILE);

	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();

	FILE << "\t-- PART TWO --" << std::endl;
	printContent(vct, FILE);
	printContent(vct_range, FILE);
	printContent(vct_copy, FILE);
}

void	vector_test_6(std::ofstream &FILE)
{
	FILE << "----- TEST 6 -----" << std::endl;
	FILE << "Testing: Erase" << std::endl;
	TIMER t(&FILE);
	
	#undef TESTED_TYPE
	#define TESTED_TYPE std::string
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printContent(vct, FILE);

	checkErase(vct, vct.erase(vct.begin() + 2), FILE);

	checkErase(vct, vct.erase(vct.begin()), FILE);
	checkErase(vct, vct.erase(vct.end() - 1), FILE);

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3), FILE);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1), FILE);

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printContent(vct, FILE);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()), FILE);

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	printContent(vct, FILE);
	checkErase(vct, vct.erase(vct.begin(), vct.end()), FILE);
}

void	vector_test_7(std::ofstream &FILE)
{
	FILE << "----- TEST 7 -----" << std::endl;
	FILE << "Testing: Insert" << std::endl;
	TIMER t(&FILE);

	#undef TESTED_TYPE
	#define TESTED_TYPE int
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printContent(vct, FILE);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	printContent(vct2, FILE);

	vct2.insert(vct2.end() - 2, 42);
	printContent(vct2, FILE);

	vct2.insert(vct2.end(), 2, 84);
	printContent(vct2, FILE);

	vct2.resize(4);
	printContent(vct2, FILE);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printContent(vct2, FILE);

	printContent(vct, FILE);

	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	printContent(vct3, FILE);
}

void	vector_test_8(std::ofstream &FILE)
{
	FILE << "----- TEST 8 -----" << std::endl;
	FILE << "Testing: Insert" << std::endl;
	TIMER t(&FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	printContent(vct, FILE);

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	printContent(vct2, FILE);
	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	printContent(vct2, FILE);
	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	printContent(vct2, FILE);

	FILE << "insert return:" << std::endl;

	FILE << *vct2.insert(vct2.end(), 42) << std::endl;
	FILE << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	FILE << "----------------------------------------" << std::endl;

	printContent(vct2, FILE);
}

void	vector_test_9(std::ofstream &FILE)
{
	FILE << "----- TEST 9 -----" << std::endl;
	FILE << "Testing: Iterator operations" << std::endl;
	TIMER t(&FILE);
	
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	incr_decr_test(vct, FILE);

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	FILE << *(it += 2) << std::endl;
	FILE << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	FILE << "const_ite +=: " << *(ite += 2) << std::endl;
	FILE << "const_ite -=: " << *(ite -= 2) << std::endl;

	FILE << "(it == const_it): " << (ite == it) << std::endl;
	FILE << "(const_ite - it): " << (ite - it) << std::endl;
	FILE << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printContent(vct, FILE);
}

void	vector_test_10(std::ofstream &FILE)
{
	FILE << "----- TEST 10 -----" << std::endl;
	FILE << "Testing: Push & pop" << std::endl;
	TIMER t(&FILE);

	#undef TESTED_TYPE
	#define TESTED_TYPE std::string
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(8);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (unsigned long int i = 0; i < vct.size(); ++i)
		it[i] = std::string((vct.size() - i), i + 65);
	printContent(vct, FILE);

	FILE << "push_back():\n" << std::endl;

	std::cout << vct.capacity() << std::endl;
	vct.push_back("One long string");
	std::cout << "SEG\n";
	vct2.push_back("Another long string");

	printContent(vct, FILE);
	printContent(vct2, FILE);

	vct.pop_back();
	vct2.pop_back();

	printContent(vct, FILE);
	printContent(vct2, FILE);
}

void	vector_test_11(std::ofstream &FILE)
{
	FILE << "----- TEST 11 -----" << std::endl;
	FILE << "Testing: Relational operators" << std::endl;
	TIMER t(&FILE);

	#undef TESTED_TYPE
	#define TESTED_TYPE int
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2(4);

	cmp(vct, vct, FILE);
	cmp(vct, vct2, FILE);

	vct2.resize(10);

	cmp(vct, vct2, FILE);
	cmp(vct2, vct, FILE);

	vct[2] = 42;

	cmp(vct, vct2, FILE);
	cmp(vct2, vct, FILE);

	swap(vct, vct2);

	cmp(vct, vct2, FILE);
	cmp(vct2, vct, FILE);
}

void	vector_test_12(std::ofstream &FILE)
{
	FILE << "----- TEST 12 -----" << std::endl;
	FILE << "Testing: Reverse iterator constructors\n No output, checks for compile errors" << std::endl;
	TIMER t(&FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);

	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);
}

void	vector_test_13(std::ofstream &FILE)
{
	FILE << "----- TEST 13 -----" << std::endl;
	FILE << "Testing: Reverse iterator operations" << std::endl;
	TIMER t(&FILE);

	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	printContent(vct, FILE);

	FILE << (it_ == it.base()) << std::endl;
	FILE << (it_ == (it + 3).base()) << std::endl;

	FILE << *(it.base() + 1) << std::endl;
	FILE << *(it - 3) << std::endl;
	FILE << *(it - 3).base() << std::endl;
	it -= 3;
	FILE << *it.base() << std::endl;

	FILE << "TEST OFFSET" << std::endl;
	FILE << *(it) << std::endl;
	FILE << *(it).base() << std::endl;
	FILE << *(it - 0) << std::endl;
	FILE << *(it - 0).base() << std::endl;
	FILE << *(it - 1).base() << std::endl;
}

void	vector_test_14(std::ofstream &FILE)
{
	FILE << "----- TEST 14 -----" << std::endl;
	FILE << "Testing: More reverse iterator operations" << std::endl;
	TIMER t(&FILE);

	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	FILE << *(it += 2) << std::endl;
	FILE << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	FILE << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	FILE << "(it == const_it): " << (ite == it) << std::endl;
	FILE << "(const_ite - it): " << (ite - it) << std::endl;
	FILE << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printContent(vct, FILE);
}

void	vector_test_15(std::ofstream &FILE)
{
	FILE << "----- TEST 15 -----" << std::endl;
	FILE << "Testing: Empty, reserve, resize" << std::endl;
	TIMER t(&FILE);

	const int start_size = 7;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	printContent(vct, FILE);

	vct.resize(10, 42);
	printContent(vct, FILE);

	vct.resize(18, 43);
	printContent(vct, FILE);
	vct.resize(10);
	printContent(vct, FILE);
	vct.resize(23, 44);
	printContent(vct, FILE);
	vct.resize(5);
	printContent(vct, FILE);
	vct.reserve(5);
	vct.reserve(3);
	printContent(vct, FILE);
	vct.resize(87);
	vct.resize(5);
	printContent(vct, FILE);

	FILE << "is_empty: " << vct2.empty() << std::endl;
	vct2 = vct;
	FILE << "is_empty: " << vct2.empty() << std::endl;
	vct.reserve(vct.capacity() + 1);
	printContent(vct, FILE);
	printContent(vct2, FILE);

	vct2.resize(0);
	FILE << "is_empty: " << vct2.empty() << std::endl;
	printContent(vct2, FILE);
}

void	vector_test_16(std::ofstream &FILE)
{
	FILE << "----- TEST 16 -----" << std::endl;
	FILE << "Testing: Swap" << std::endl;
	TIMER t(&FILE);

	TESTED_NAMESPACE::vector<TESTED_TYPE> foo(3, 15);
	TESTED_NAMESPACE::vector<TESTED_TYPE> bar(5, 42);
	
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();

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
// ---------------------------------------------------------------------------------

void	vector_test()
{
	std::ofstream FILE("TEST-LOG/vector/" F_OUT "vector.txt");

	vector_test_1(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_2(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_3(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_4(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_5(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_6(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_7(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_8(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_9(FILE);
	FILE << "################################################################################" << std::endl;
	// vector_test_10(FILE); // SEGFAULT ON WINDOWS PC
	// FILE << "############## ##################################################################" << std::endl;
	vector_test_11(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_12(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_13(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_14(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_15(FILE);
	FILE << "################################################################################" << std::endl;
	vector_test_16(FILE);
	FILE << "################################################################################" << std::endl;
}