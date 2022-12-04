#include "test.hpp"

#define TESTED_TYPE int
#define t_stack TESTED_NAMESPACE::stack
#define t_list	std::list<TESTED_TYPE>

// UTILS -----------------------------------------------------------------------------------

template <typename Stack>
void	printContent(Stack &x, std::ofstream &FILE) 
{
	FILE << "- CONTENT OF CONTAINER -" << std::endl;
	
	while (x.size() != 0)
	{
		FILE << x.top() << std::endl;
		x.pop();
	}
}

template <class Stack>
void	cmp(const Stack &lhs, const Stack &rhs, std::ofstream &FILE)
{
	FILE << "==: " << (lhs == rhs) << " | !=: " << (lhs != rhs) << std::endl;
	FILE << " <: " << (lhs <  rhs) << " | <=: " << (lhs <= rhs) << std::endl;
	FILE << " >: " << (lhs >  rhs) << " | >=: " << (lhs >= rhs) << std::endl;
}
// -----------------------------------------------------------------------------------------
// TESTS -----------------------------------------------------------------------------------

void	stack_test_1(std::ofstream &FILE)
{
	FILE << "----- TEST 1 -----" << std::endl;
	FILE << "Testing: default constructor, adding elements, empty() & size()" << std::endl;
	TIMER t(&FILE);

	t_stack<TESTED_TYPE> stck;

	FILE << "empty: " << stck.empty() << std::endl;
	FILE << "size: " << stck.size() << std::endl;

	stck.push(41);
	stck.push(29);
	stck.push(10);
	stck.push(42);
	FILE << "Add 4 elements" << std::endl;

	FILE << "empty: " << stck.empty() << std::endl;
	FILE << "size: " << stck.size() << std::endl;

	printContent(stck, FILE);
}

void	stack_test_2(std::ofstream &FILE)
{
	FILE << "----- TEST 2 -----" << std::endl;
	FILE << "Testing: default constructor w/ " NS_STR "::vector as param, adding elements, empty() & size()" << std::endl;
	TIMER t(&FILE);

	t_stack<TESTED_TYPE>::container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);
	FILE << "Add 6 elements to container" << std::endl;
	
	t_stack<TESTED_TYPE>	stck(ctnr);

	FILE << "empty: " << stck.empty() << std::endl;
	FILE << "size: " << stck.size() << std::endl;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);
	FILE << "Add 6 elements to stack" << std::endl;

	FILE << "empty: " << stck.empty() << std::endl;
	FILE << "size: " << stck.size() << std::endl;

	printContent(stck, FILE);
}

void	stack_test_3(std::ofstream &FILE)
{
	FILE << "----- TEST 3 -----" << std::endl;
	FILE << "Testing: default constructor w/ std::list as param, adding elements, empty() & size()" << std::endl;
	TIMER t(&FILE);
	
	t_list	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);
	FILE << "Add 6 elements to container" << std::endl;

	t_stack<TESTED_TYPE, t_list>	stck(ctnr);

	FILE << "empty: " << stck.empty() << std::endl;
	FILE << "size: " << stck.size() << std::endl;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);
	FILE << "Add 6 elements" << std::endl;

	FILE << "empty: " << stck.empty() << std::endl;
	FILE << "size: " << stck.size() << std::endl;

	printContent(stck, FILE);
}

void	stack_test_4(std::ofstream &FILE)
{
	FILE << "----- TEST 4 -----" << std::endl;
	FILE << "Testing: Relational operators" << std::endl;
	TIMER t(&FILE);

	t_stack<TESTED_TYPE>::container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);
	FILE << "Add 6 elements to container" << std::endl;


	t_stack<TESTED_TYPE>	A_stack(ctnr);
	t_stack<TESTED_TYPE>	B_stack(ctnr);
	FILE << "Comparing two stacks, contructed with container" << std::endl;

	FILE << "1. A_stack && A_stack" << std::endl;
	cmp(A_stack, A_stack, FILE);
	FILE << "2. A_stack && B_stack" << std::endl;
	cmp(A_stack, B_stack, FILE);

	B_stack.push(60);
	B_stack.push(61);
	B_stack.push(62);
	FILE << "Add 3 elements to B_stack" << std::endl;

	FILE << "3. A_stack && B_stack" << std::endl;
	cmp(A_stack, B_stack, FILE);
	FILE << "4. B_stack && A_stack" << std::endl;
	cmp(B_stack, A_stack, FILE);

	A_stack.push(42);
	FILE << "Add 1 elements to A_stack" << std::endl;

	FILE << "5. A_stack && B_stack" << std::endl;
	cmp(A_stack, B_stack, FILE);
	FILE << "6. B_stack && A_stack" << std::endl;
	cmp(B_stack, A_stack, FILE);

	A_stack.push(100);
	FILE << "Add 1 elements to A_stack" << std::endl;

	FILE << "7. A_stack && B_stack" << std::endl;
	cmp(A_stack, B_stack, FILE);
	FILE << "8. B_stack && A_stack" << std::endl;
	cmp(B_stack, A_stack, FILE);
}

void	stack_test_5(std::ofstream &FILE)
{
	FILE << "----- TEST 5 -----" << std::endl;
	FILE << "Testing: Relational operators w/ std::list as container" << std::endl;
	TIMER t(&FILE);

	t_list	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);
	FILE << "Add 6 elements to container" << std::endl;


	t_stack<TESTED_TYPE, t_list>	A_stack(ctnr);
	t_stack<TESTED_TYPE, t_list>	B_stack(ctnr);
	FILE << "Comparing two stacks, contructed with std::list as container" << std::endl;

	FILE << "1. A_stack && A_stack" << std::endl;
	cmp(A_stack, A_stack, FILE);
	FILE << "2. A_stack && B_stack" << std::endl;
	cmp(A_stack, B_stack, FILE);

	B_stack.push(60);
	B_stack.push(61);
	B_stack.push(62);
	FILE << "Add 3 elements to B_stack" << std::endl;

	FILE << "3. A_stack && B_stack" << std::endl;
	cmp(A_stack, B_stack, FILE);
	FILE << "4. B_stack && A_stack" << std::endl;
	cmp(B_stack, A_stack, FILE);

	A_stack.push(42);
	FILE << "Add 1 elements to A_stack" << std::endl;

	FILE << "5. A_stack && B_stack" << std::endl;
	cmp(A_stack, B_stack, FILE);
	FILE << "6. B_stack && A_stack" << std::endl;
	cmp(B_stack, A_stack, FILE);

	A_stack.push(100);
	FILE << "Add 1 elements to A_stack" << std::endl;

	FILE << "7. A_stack && B_stack" << std::endl;
	cmp(A_stack, B_stack, FILE);
	FILE << "8. B_stack && A_stack" << std::endl;
	cmp(B_stack, A_stack, FILE);
}
// ------------------------------------------------------------------------------------------

void	stack_test()
{
	std::ofstream FILE("TEST-LOG/stack/" F_OUT "stack.txt");
	
	stack_test_1(FILE);
	FILE << "################################################################################" << std::endl;
	stack_test_2(FILE);
	FILE << "################################################################################" << std::endl;
	stack_test_3(FILE);
	FILE << "################################################################################" << std::endl;
	stack_test_4(FILE);
	FILE << "################################################################################" << std::endl;
	stack_test_5(FILE);
	FILE << "################################################################################" << std::endl;
}