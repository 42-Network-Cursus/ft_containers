#include <iostream>
#include <stack>
#include "stack.hpp"
#include <vector> //delete and replace by ft::vector

//namespace ns = ft; // change ft to std


int main()
{
	ft::stack<int, std::vector<int> >	myStack;

	std::cout << std::boolalpha;

	std::cout << "empty : " << myStack.empty() << std::endl;
	std::cout << "size : " << myStack.size() << std::endl;

	std::cout << "push 5" << std::endl;
	myStack.push(5);
	std::cout << "top : " << myStack.top() << std::endl;

	std::cout << "empty : " << myStack.empty() << std::endl;
	std::cout << "size : " << myStack.size() << std::endl;

	std::cout << "push from 0 to 4" << std::endl;
	for (int i = 0; i < 5; i++)
		myStack.push(i);

	std::cout << "size : " << myStack.size() << std::endl;
	
	while (!myStack.empty())
	{
		std::cout << "top : " << myStack.top() << std::endl;
		std::cout << "pop" << std::endl;
		myStack.pop();
	}

	std::cout << "empty : " << myStack.empty() << std::endl;
	std::cout << "size : " << myStack.size() << std::endl;

	std::cout << "\n-- Relational operators --\n";
	ft::stack<int, std::vector<int> >	A;
	ft::stack<int, std::vector<int> >	B;
	ft::stack<int, std::vector<int> >	C;

	std::cout << "empty == empty : ";
	std::cout << (A == B) << std::endl;

	A.push(5);
	std::cout << "5 == empty : ";
	std::cout << (A == B) << std::endl;

	std::cout << "empty != empty : ";
	std::cout << (B != C) << std::endl;

	A.push(5);
	std::cout << "5 != empty : ";
	std::cout << (A != B) << std::endl;

	std::cout << "empty < empty : ";
	std::cout << (B < C) << std::endl;

	A.push(5);
	std::cout << "5 < empty : ";
	std::cout << (A < B) << std::endl;

	std::cout << "empty < 5 : ";
	std::cout << (B < A) << std::endl;

	//...
	return 0;
}