#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <stack>
#include "Stack.hpp"

#ifndef STD
# define STACK	ft::Stack
# else
# define STACK	std::stack
#endif

void	test_canonic()
{
	std::cout << "Tests Canonic: " << std::endl;

	std::deque<int>						deq;
	for (int i(0); i < 5; i++) {
		deq.push_back(i);
	}

	STACK<int, std::deque<int> >		cur;
	if (cur.empty())
		std::cout << "Cur: Empty" << std::endl;

	STACK<int, std::deque<int> >		cur2(deq);
	std::cout << "Size: " << cur2.size() << std::endl;
	std::cout << "Top: " << cur2.top() << std::endl;

	STACK<int, std::deque<int> >		cur3(cur2);
	std::cout << "Size: " << cur2.size() << std::endl;
	std::cout << "Top: " << cur2.top() << std::endl;

	cur = cur2;
	std::cout << "Size: " << cur.size() << std::endl;
	std::cout << "Top: " << cur.top() << std::endl;

	std::cout << std::endl;
}

void	test_empty()
{
	std::cout << "Tests Empty: " << std::endl;

	STACK<int, std::vector<char> >		cur;

	if (cur.empty())
		std::cout << "Cur: Empty" << std::endl;
	cur.push('a');
	if (cur.empty())
		std::cout << "Cur: Empty" << std::endl;
	cur.push('b');
	if (cur.empty())
		std::cout << "Cur: Empty" << std::endl;
	cur.pop();
	if (cur.empty())
		std::cout << "Cur: Empty" << std::endl;
	cur.pop();
	if (cur.empty())
		std::cout << "Cur: Empty" << std::endl;

	std::cout << std::endl;
}

void	test_size()
{
	std::cout << "Tests Size: " << std::endl;

	STACK<int, std::list<double> >		cur;

	std::cout << "Size: " << cur.size() << " ";
	for (double d(-2.5); d < 2.4; d += 1) {
		cur.push(d);
		std::cout << cur.size() << " ";
	}
	std::cout << std::endl;

	std::cout << "Size: " << cur.size() << " ";
	for (int i(5); i > 0; i--) {
		cur.pop();
		std::cout << cur.size() << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_top()
{
	std::cout << "Tests Top: " << std::endl;

	std::deque<short>					deq;
	for (int i(1); i < 4; i++) {
		deq.push_back(i);
	}

	STACK<short, std::deque<short> >	cur(deq);

	std::cout << "Deq back: " << deq.back() << std::endl;
	std::cout << "Cur back: " << cur.top() << std::endl;

	cur.top() = 6;
	std::cout << "Deq back: " << deq.back() << std::endl;
	std::cout << "Cur back: " << cur.top() << std::endl;

	std::cout << std::endl;
}

void	test_push_pop()
{
	std::cout << "Tests Push Pop: " << std::endl;

	STACK<std::string, std::vector<std::string> >    cur(std::vector<std::string>(1, "Hello"));

	std::cout << "Top: " << cur.top() << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;

	cur.pop();
	std::cout << "Top: " << cur.top() << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;

	cur.push(std::string("Hola"));
	std::cout << "Top: " << cur.top() << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;

	cur.push(std::string("Salut"));
	std::cout << "Top: " << cur.top() << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;

	cur.pop();
	std::cout << "Top: " << cur.top() << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;

	std::cout << std::endl;
}

void	test_operators()
{
	std::cout << "Tests Operators: " << std::endl;

	STACK<int, std::list<int> >		cur1;
	STACK<int, std::list<int> >		cur2;
	STACK<int, std::list<int> >		cur3;

	for (int i = 1; i <= 3; i++) {
		cur1.push(i);
		cur2.push(i);
	}
	for (int i = 3; i >= 1; i--) {
		cur3.push(i);
	}
	std::cout << std::endl;

	std::cout << std::boolalpha;

	std::cout << "Cur1 == Cur2: " << (cur1 == cur2) << std::endl;
	std::cout << "Cur1 == Cur3: " << (cur1 == cur3) << std::endl;
	std::cout << "Cur2 == Cur3: " << (cur2 == cur3) << std::endl;

	std::cout << "Cur1 != Cur2: " << (cur1 != cur2) << std::endl;
	std::cout << "Cur1 != Cur3: " << (cur1 != cur3) << std::endl;
	std::cout << "Cur2 != Cur3: " << (cur2 != cur3) << std::endl;

	std::cout << "Cur1 < Cur2: " << (cur1 < cur2) << std::endl;
	std::cout << "Cur1 < Cur3: " << (cur1 < cur3) << std::endl;
	std::cout << "Cur2 < Cur3: " << (cur2 < cur3) << std::endl;

	std::cout << "Cur1 <= Cur2: " << (cur1 <= cur2) << std::endl;
	std::cout << "Cur1 <= Cur3: " << (cur1 <= cur3) << std::endl;
	std::cout << "Cur2 <= Cur3: " << (cur2 <= cur3) << std::endl;

	std::cout << "Cur1 > Cur2: " << (cur1 > cur2) << std::endl;
	std::cout << "Cur1 > Cur3: " << (cur1 > cur3) << std::endl;
	std::cout << "Cur2 > Cur3: " << (cur2 > cur3) << std::endl;

	std::cout << "Cur1 >= Cur2: " << (cur1 >= cur2) << std::endl;
	std::cout << "Cur1 >= Cur3: " << (cur1 >= cur3) << std::endl;
	std::cout << "Cur2 >= Cur3: " << (cur2 >= cur3) << std::endl;

	std::cout << std::noboolalpha;

	std::cout << std::endl;
}

int		main()
{
	test_canonic();
	test_empty();
	test_size();
	test_top();
	test_push_pop();
	test_operators();

	return 0;
}
