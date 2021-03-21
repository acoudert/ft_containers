#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Vector.hpp"

#ifndef STD
# define VEC	ft::Vector
# else
# define VEC	std::vector
#endif

void	test_canonic()
{
	VEC<char>::iterator	it_cur;

	std::cout << "Tests Canonic: " << std::endl;

	VEC<char>		cur1;
	it_cur = cur1.begin();
	if (it_cur == cur1.end())
		std::cout << "Cur: Empty" << std::endl;
	VEC<char>		cur2(5, 'a');
	it_cur = cur2.begin();
	std::cout << "Cur: ";
	while (it_cur != cur2.end())
	{
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;

	VEC<char>		temp(3, 'b');
	VEC<char>		cur3(temp.begin(), temp.end());
	it_cur = cur3.begin();
	std::cout << "Cur: ";
	while (it_cur != cur3.end())
	{
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;

	VEC<char>		cur4(cur2);
	it_cur = cur4.begin();
	std::cout << "Cur: ";
	while (it_cur != cur4.end())
	{
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;

	cur4 = cur3;
	it_cur = cur4.begin();
	std::cout << "Cur: ";
	while (it_cur != cur4.end())
	{
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_iterator()
{
	std::cout << "Tests Iterator: " << std::endl;

	VEC<std::string>	cur(5, "Hello");
	VEC<std::string>::iterator	it_cur = cur.begin();
	std::cout << "Cur: ";
	while (it_cur != cur.end())
	{
		std::cout << *it_cur << " ";
		*it_cur = "Hola";
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;
	
	it_cur = cur.begin();
	std::cout << "Cur: ";
	for (int i = 0; i < 5; i++) {
		std::cout << it_cur[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Cur: ";
	for (int i = 0; i < 5; i++) {
		std::cout << *(it_cur + i) << " " << *(i + it_cur) << " ";
	}
	std::cout << std::endl;
	it_cur = cur.end();
	std::cout << "Cur: ";
	for (int i = 5; i >= 1; i--) {
		std::cout << *(it_cur - i) << " ";
	}
	std::cout << std::endl;

	std::cout << "Cur: ";
	for (VEC<std::string>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << (it - cur.begin()) << " " << (cur.begin() - it) << " ";
	}
	std::cout << std::endl;
	
	VEC<std::string> 		cur2(cur);
	it_cur = cur2.end();
	VEC<std::string>::const_iterator		c_it_cur(it_cur);
	c_it_cur--;
	std::cout << "Cur: ";
	while (c_it_cur != cur2.begin())
	{
		std::cout << *c_it_cur << " ";
		--c_it_cur;
	}
	std::cout << *c_it_cur << " ";
	std::cout << std::endl;

	VEC<std::string>	cur3(3, "Salut");
	VEC<std::string>::reverse_iterator	r_it_cur = cur3.rbegin();
	std::cout << "Cur: ";
	while (r_it_cur != cur3.rend())
	{
		std::cout << *r_it_cur << " ";
		*r_it_cur = "Yoo";
		std::cout << *r_it_cur << " ";
		r_it_cur++;
	}
	std::cout << std::endl;

	VEC<std::string>::const_reverse_iterator		c_r_it_cur = cur2.rbegin();
	std::cout << "Cur: ";
	while (c_r_it_cur != cur2.rend())
	{
		std::cout << *c_r_it_cur << " ";
		c_r_it_cur++;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_capacity()
{
	std::cout << "Tests Capacity: " << std::endl;
	
	VEC<long>		cur;
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	std::cout << "Cur: capacity : " << cur.capacity() << std::endl;
	std::cout << "Cur: ";
	for (VEC<long>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.insert(cur.begin(), 1);
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	std::cout << "Cur: capacity : " << cur.capacity() << std::endl;
	std::cout << "Cur: ";
	for (VEC<long>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	cur.insert(cur.begin(), 2);
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	std::cout << "Cur: capacity : " << cur.capacity() << std::endl;
	std::cout << "Cur: ";
	for (VEC<long>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.insert(cur.begin(), 3, 3);
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	std::cout << "Cur: capacity : " << cur.capacity() << std::endl;
	std::cout << "Cur: ";
	for (VEC<long>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.resize(5);
	cur.reserve(7);
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	std::cout << "Cur: capacity : " << cur.capacity() << std::endl;
	std::cout << "Cur: ";
	for (VEC<long>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.resize(7, 13);
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	std::cout << "Cur: capacity : " << cur.capacity() << std::endl;
	std::cout << "Cur: ";
	for (VEC<long>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.resize(9, 10);
	cur.pop_back();
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	std::cout << "Cur: capacity : " << cur.capacity() << std::endl;
	std::cout << "Cur: ";
	for (VEC<long>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.reserve(10);
	cur.resize(12);
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	std::cout << "Cur: capacity : " << cur.capacity() << std::endl;
	std::cout << "Cur: ";
	for (VEC<long>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	if (cur.max_size() > 100000000000000)
		std::cout << "Ok" << std::endl;

	std::cout << std::endl;
}

void	test_element_access()
{
	std::cout << "Tests Element Access: " << std::endl;

	VEC<int>				cur;
	for (int i = 1; i <= 5; i++) {
		cur.push_back(i);
	}

	std::cout << "Cur: ";
	for (VEC<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Cur: ";
	for (int i = 10; i > 5; i--) {
		cur[i - 6] = i;
		try {
			cur.at(i - 6) = i;
		}
		catch (std::out_of_range & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Cur: first: " << cur.front() << std::endl;
	std::cout << "Cur: back: " << cur.back() << std::endl;

	VEC<int> const		cur2(cur);
	
	std::cout << "Cur: ";
	for (int i = 0; i < 5; i++) {
		std::cout << cur2[i] << " ";
		try {
			std::cout << cur2.at(i) << " ";
		}
		catch (std::out_of_range & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Cur: const first: " << cur2.front() << std::endl;
	std::cout << "Cur: const back: " << cur2.back() << std::endl;

	std::cout << std::endl;

}

void	test_assign()
{
	VEC<float>		cur(5, 10.0);

	std::cout << "Tests Assign: " << std::endl;

	VEC<float>		li(3, 5.0);

	std::cout << "Cur: ";
	for (VEC<float>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.assign(li.begin(), li.end());
	std::cout << "Cur: ";
	for (VEC<float>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.assign(15, 2);
	std::cout << "Cur: ";
	for (VEC<float>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;

}

void	test_push_pop()
{
	VEC<double>			cur;

	std::cout << "Tests Push Pop: " << std::endl;

	cur.push_back(1);
	cur.push_back(2);
	cur.push_back(3);
	cur.push_back(4);
	std::cout << "Cur: ";
	for (VEC<double>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.pop_back();
	cur.pop_back();
	std::cout << "Cur: ";
	for (VEC<double>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;
	std::cout << "Capacity: " << cur.capacity() << std::endl;

	std::cout << std::endl;
}

void	test_insert()
{
	VEC<int>				cur;
	VEC<int>::iterator	it_cur = cur.begin();

	std::cout << "Tests Insert: " << std::endl;

	std::cout << "Cur: ";
	for (int i = 0; i < 3; i++) {
		it_cur = cur.insert(cur.begin(), i);
	}
	cur.insert(cur.end(), 3);
	it_cur = cur.begin();
	while (it_cur != cur.end()) {
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;
	std::cout << "Capacity: " << cur.capacity() << std::endl;

	std::cout << "Cur: ";
	it_cur = cur.begin();
	cur.insert(it_cur, 3, 4);
	cur.insert(cur.end(), 2, 5);
	it_cur = cur.begin();
	while (it_cur != cur.end()) {
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;
	std::cout << "Capacity: " << cur.capacity() << std::endl;

	std::cout << "Cur: ";
	it_cur = cur.begin();
	++it_cur++;
	cur.insert(it_cur, 1, 6);
	it_cur = cur.begin();
	while (it_cur != cur.end()) {
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;
	std::cout << "Capacity: " << cur.capacity() << std::endl;

	VEC<int>				temp1(5, 3);

	std::cout << "Cur: ";
	it_cur = cur.begin();
	cur.insert(it_cur, temp1.begin(), temp1.end());
	it_cur = cur.begin();
	while (it_cur != cur.end()) {
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;
	std::cout << "Size: " << cur.size() << std::endl;
	std::cout << "Capacity: " << cur.capacity() << std::endl;
	
	std::cout << std::endl;
}

void	test_erase()
{
	std::cout << "Tests Erase: " << std::endl;

	VEC<int>				cur;
	for (int i = 1; i < 15; i++) {
		cur.push_back(i);
	}
	std::cout << "Cur: ";
	for (VEC<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	cur.erase(cur.begin());
	std::cout << "Cur: ";
	for (VEC<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		if (*it % 2)
		{
			it = cur.erase(it);
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;

	VEC<int>::iterator	it_cur = cur.end();
	VEC<int>::iterator	it_cur2;
	it_cur--;
	cur.erase(it_cur, cur.end());
	std::cout << "Cur: ";
	for (VEC<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur2 = cur.begin();
	it_cur2++;
	++it_cur2;
	cur.erase(it_cur, it_cur2);
	std::cout << "Cur: ";
	for (VEC<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur2 = cur.end();
	it_cur++;
	it_cur2--;
	cur.erase(it_cur, it_cur2);
	std::cout << "Cur: ";
	for (VEC<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;

}

void	test_swap()
{
	std::cout << "Tests Swap: " << std::endl;

	VEC<float>	cur1(5, 10.5);
	VEC<float>	cur2(10, 4.2);

	std::cout << "Cur1: ";
	for (VEC<float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (VEC<float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	VEC<float>::iterator	it1 = cur1.begin();
	VEC<float>::iterator	it2 = cur2.begin();

	cur1.swap(cur2);
	std::cout << "Cur1: ";
	while (it2 != cur1.end()) {
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	while (it1 != cur2.end()) {
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
#ifndef STD
	ft::swap(cur1, cur2);
# else
	std::swap(cur1, cur2);
# endif
	std::cout << "Cur1: ";
	for (VEC<float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (VEC<float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_clear()
{
	VEC<int>	cur(10, 5);

	std::cout << "Size: " << cur.size() << std::endl;
	std::cout << "Capacity: " << cur.capacity() << std::endl;

	cur.clear();

	std::cout << "Size: " << cur.size() << std::endl;
	std::cout << "Capacity: " << cur.capacity() << std::endl;

	std::cout << std::endl;
}

void	test_operators()
{
	std::cout << "Tests Operators: " << std::endl;

	VEC<int>	cur1;
	VEC<int>	cur2;
	VEC<int>	cur3;
	for (int i = 1; i <= 3; i++) {
		cur1.push_back(i);
		cur2.push_back(i);
	}
	for (int i = 3; i >= 1; i--) {
		cur3.push_back(i);
	}
	std::cout << "Cur1: ";
	for (VEC<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (VEC<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur3: ";
	for (VEC<int>::iterator it = cur3.begin(); it != cur3.end(); it++) {
		std::cout << *it << " ";
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

void	test_final()
{
	std::cout << "Tests Final: " << std::endl;

	VEC<int>				a;
	VEC<int>::iterator		it;
	int		c;
	int		i;

	srand(time(NULL));
	for (int j(0); j < 20; j++) {
		i = rand() % 1000;
		while (i-- > 0) {
			c = rand() % 1000;
			if (c % 4 == 0)
				a.push_back(rand() % 1000);
			else {
				it = a.begin();
				if (a.size()) {
					for (int j = rand() % a.size(); j > 0; j--) {
						it++;
					}
					a.insert(it, rand() % 1000);
				}
				else
					a.insert(a.begin(), rand() % 1000);
			}
		}
		for (int k = rand() % 1000; k > 0; k--) {
			it = a.begin();
			if (a.size()) {
				for (int j = rand() % a.size(); j > 0; j--) {
					it++;
				}
				a.erase(it);
			}
		}
		std::cout << j << " ";
		a.clear();
	}
	std::cout << std::endl;

	std::cout << std::endl;
}


int		main()
{
	test_canonic();
	test_iterator();
	test_capacity();
	test_element_access();
	test_assign();
	test_push_pop();
	test_insert();
	test_erase();
	test_swap();
	test_clear();
	test_operators();
	test_final();

	return 0;
}
