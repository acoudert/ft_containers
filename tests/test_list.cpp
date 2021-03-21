#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "List.hpp"

#ifndef STD
# define LIST	ft::List
# else
# define LIST	std::list
#endif

void	test_canonic()
{
	LIST<char>::iterator	it_cur;

	std::cout << "Tests Canonic: " << std::endl;

	LIST<char>		cur1;
	it_cur = cur1.begin();
	if (it_cur == cur1.end())
		std::cout << "Cur: Empty" << std::endl;
	LIST<char>		cur2(5, 'a');
	it_cur = cur2.begin();
	std::cout << "Cur: ";
	while (it_cur != cur2.end())
	{
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;

	LIST<char>		temp(3, 'b');
	LIST<char>		cur3(temp.begin(), temp.end());
	it_cur = cur3.begin();
	std::cout << "Cur: ";
	while (it_cur != cur3.end())
	{
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;

	LIST<char>		cur4(cur2);
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

	LIST<std::string>	cur(5, "Hello");
	LIST<std::string>::iterator	it_cur = cur.begin();
	std::cout << "Cur: ";
	while (it_cur != cur.end())
	{
		std::cout << *it_cur << " ";
		*it_cur = "Hola";
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;
	
	LIST<std::string> 		cur2(cur);
	it_cur = cur2.end();
	LIST<std::string>::const_iterator		c_it_cur(it_cur);
	c_it_cur--;
	std::cout << "Cur: ";
	while (c_it_cur != cur2.end())
	{
		std::cout << *c_it_cur << " ";
		--c_it_cur;
	}
	std::cout << std::endl;

	LIST<std::string>	cur3(3, "Salut");
	LIST<std::string>::reverse_iterator	r_it_cur = cur3.rbegin();
	std::cout << "Cur: ";
	while (r_it_cur != cur3.rend())
	{
		std::cout << *r_it_cur << " ";
		*r_it_cur = "Yoo";
		std::cout << *r_it_cur << " ";
		r_it_cur++;
	}
	std::cout << std::endl;

	r_it_cur = cur2.rbegin();
	LIST<std::string>::const_reverse_iterator		c_r_it_cur(r_it_cur);
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
	
	LIST<long>		cur;
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	cur.insert(cur.begin(), 1);
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;
	
	cur.insert(cur.begin(), 2);
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	if (cur.max_size() > 100000000000000)
		std::cout << "Ok" << std::endl;

	std::cout << std::endl;
}

void	test_element_access()
{
	std::cout << "Tests Element Access: " << std::endl;

	LIST<int>				cur(1, 1);

	cur.insert(cur.end(), 5);
	cur.insert(cur.end(), 10);
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.front() = 3;
	cur.back() = 7;
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	LIST<int> const		cur2(cur);
	std::cout << "Cur: const first: " << cur2.front() << std::endl;
	std::cout << "Cur: const back: " << cur2.back() << std::endl;

	std::cout << std::endl;
}

void	test_assign()
{
	LIST<float>		cur(5, 10.0);

	std::cout << "Tests Assign: " << std::endl;

	LIST<float>		li(3, 5.0);

	std::cout << "Cur: ";
	for (LIST<float>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.assign(li.begin(), li.end());
	std::cout << "Cur: ";
	for (LIST<float>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.assign(15, 2);
	std::cout << "Cur: ";
	for (LIST<float>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_push_pop()
{
	LIST<double>			cur;

	std::cout << "Tests Push Pop: " << std::endl;

	cur.push_front(2);
	cur.push_front(1);
	cur.push_back(3);
	cur.push_back(4);
	std::cout << "Cur: ";
	for (LIST<double>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.pop_front();
	cur.pop_back();
	std::cout << "Cur: ";
	for (LIST<double>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_insert()
{
	LIST<int>				cur;
	LIST<int>::iterator	it_cur = cur.begin();

	std::cout << "Tests Insert: " << std::endl;

	std::cout << "Cur: ";
	for (int i = 0; i < 3; i++) {
		it_cur = cur.insert(it_cur, i);
	}
	cur.insert(cur.end(), 3);
	it_cur = cur.begin();
	while (it_cur != cur.end()) {
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;

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

	LIST<int>				temp1(5, 3);

	std::cout << "Cur: ";
	it_cur = cur.begin();
	cur.insert(it_cur, temp1.begin(), temp1.end());
	it_cur = cur.begin();
	while (it_cur != cur.end()) {
		std::cout << *it_cur << " ";
		it_cur++;
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
}

void	test_erase()
{
	std::cout << "Tests Erase: " << std::endl;

	LIST<int>				cur;
	for (int i = 1; i < 15; i++) {
		cur.push_back(i);
	}
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	cur.erase(cur.begin());
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		if (*it % 2)
		{
			it = cur.erase(it);
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;

	LIST<int>::iterator	it_cur = cur.end();
	LIST<int>::iterator	it_cur2;
	it_cur--;
	cur.erase(it_cur, cur.end());
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur2 = cur.begin();
	it_cur2++;
	++it_cur2;
	cur.erase(it_cur, it_cur2);
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur2 = cur.end();
	it_cur++;
	it_cur2--;
	cur.erase(it_cur, it_cur2);
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_swap()
{
	std::cout << "Tests Swap: " << std::endl;

	LIST<float>	cur1(5, 10.5);
	LIST<float>	cur2(10, 4.2);

	std::cout << "Cur1: ";
	for (LIST<float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur1.swap(cur2);
	std::cout << "Cur1: ";
	for (LIST<float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::swap(cur1, cur2);
	std::cout << "Cur1: ";
	for (LIST<float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_resize()
{
	std::cout << "Tests Resize: " << std::endl;

	LIST<unsigned int>		cur;

	cur.resize(2, 5);
	cur.resize(5, 10);
	std::cout << "Cur: ";
	for (LIST<unsigned int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.resize(3);
	std::cout << "Cur: ";
	for (LIST<unsigned int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_splice()
{
	std::cout << "Tests Splice: " << std::endl;

	LIST<unsigned char>	cur1(5, 'a');
	LIST<unsigned char>	cur2(3, 'b');
	LIST<unsigned char>::iterator	it_cur1 = cur1.begin();
	LIST<unsigned char>::iterator	it_cur2 = cur2.begin();

	cur1.splice(it_cur1, cur2);
	cur2 = LIST<unsigned char>(5, 'c');
	cur1.splice(it_cur1, cur2);
	cur2 = LIST<unsigned char>(2, 'd');
	cur1.splice(cur1.end(), cur2);

	std::cout << "Cur1: ";
	for (LIST<unsigned char>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<unsigned char>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur2 = LIST<unsigned char>(3, 'e');
	it_cur1 = cur1.end();
	it_cur2 = cur2.end();
	it_cur2--;
	cur1.splice(cur1.begin(), cur2, cur2.begin());
	cur1.splice(it_cur1, cur2, it_cur2);
	it_cur1 = cur1.begin();
	for (int i = 0; i <= 5; i++) {
		it_cur1++;
		if (i == 5) {
			cur1.splice(it_cur1, cur2, cur2.begin());
		}
	}

	std::cout << "Cur1: ";
	for (LIST<unsigned char>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<unsigned char>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur2 = LIST<unsigned char>(10, 'f');
	it_cur2 = cur2.begin();
	it_cur2++;
	it_cur2++;
	cur1.splice(cur1.begin(), cur2, cur2.begin(), it_cur2);
	it_cur1 = cur1.begin();
	it_cur2 = cur2.begin();
	for (int i = 0; i < 4; i++) {
		it_cur1++;
		it_cur2++;
	}
	cur1.splice(it_cur1, cur2, cur2.begin(), it_cur2);
	it_cur1++;
	cur1.splice(it_cur1, cur2, cur2.begin(), cur2.end());

	std::cout << "Cur1: ";
	for (LIST<unsigned char>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<unsigned char>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

bool	odd_number(int nb)
{
	return nb % 2;
}

void	test_remove()
{
	std::cout << "Tests Remove: " << std::endl;

	LIST<int>		cur1(5, 10);
	LIST<int>		cur2;

	for(int i = 0; i < 20; i++) {
		cur2.push_back(i);
	}
	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	int		temp(10);
	cur1.remove(temp);
	cur2.remove(temp);
	temp = 5;
	cur1.remove(temp);
	cur2.remove(temp);
	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur2.remove_if(odd_number);
	std::cout << "Cur2: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

bool	are_equals(int a, int b)
{
	return a == b;
}

void	test_unique()
{
	std::cout << "Tests Unique: " << std::endl;

	LIST<std::string>		cur(5, "Hello");
	
	std::cout << "Cur: ";
	for (LIST<std::string>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.unique();
	std::cout << "Cur: ";
	for (LIST<std::string>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	LIST<int>		cur2;

	for (int i = 0; i < 10; i++) {
		if (i % 2) {
			cur2.push_back(i - 1);
		}
		else {
			cur2.push_back(i);
		}
	}
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur2.unique();
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur2 = LIST<int>();

	for (int i = 0; i < 10; i++) {
		if (i % 2) {
			cur2.push_back(i - 1);
		}
		else {
			cur2.push_back(i);
		}
	}
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur2.unique(are_equals);
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

bool	is_lower(int a, int b)
{
	return a < b;
}

void	test_merge()
{
	std::cout << "Tests Merge: " << std::endl;

	LIST<int>		cur1;
	LIST<int>		cur2;

	for (int i = 0; i < 10; i++) {
		if (i % 2) {
			cur1.push_back(i);
		}
		else {
			cur2.push_back(i);
		}
	}

	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur1.merge(cur2);

	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur2 = LIST<int>(3, 0);
	cur1.merge(cur2);
	cur2 = LIST<int>(0, 10);
	cur1.merge(cur2);
	cur2 = LIST<int>(1, 5);
	cur1.merge(cur2);
	cur2 = LIST<int>(4, 10);
	cur1.merge(cur2);

	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur1 = LIST<int>();
	cur2 = LIST<int>();

	for (int i = 0; i < 10; i++) {
		if (i % 2) {
			cur1.push_back(i);
		}
		else {
			cur2.push_back(i);
		}
	}

	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur1.merge(cur2, is_lower);

	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur2 = LIST<int>(3, 0);
	cur1.merge(cur2, is_lower);
	cur2 = LIST<int>(0, 10);
	cur1.merge(cur2, is_lower);
	cur2 = LIST<int>(1, 5);
	cur1.merge(cur2, is_lower);
	cur2 = LIST<int>(4, 10);
	cur1.merge(cur2, is_lower);

	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_sort()
{
	std::cout << "Tests Sort: " << std::endl;

	LIST<int>	cur;

	cur.push_back(81);
	cur.push_back(3);
	cur.push_back(6);
	cur.push_back(18);
	cur.push_back(18);
	cur.push_back(78);
	cur.push_back(63);
	cur.push_back(45);
	cur.push_back(54);

	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.sort();
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur = LIST<int>();

	cur.push_back(1);
	cur.push_back(10);
	cur.push_back(7);
	cur.push_back(1);
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.sort(is_lower);
	std::cout << "Cur: ";
	for (LIST<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_reverse()
{
	std::cout << "Tests Reverse: " << std::endl;

	LIST<char>		cur;

	cur.reverse();
	std::cout << "Cur: ";
	for (LIST<char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.push_back('a');
	cur.reverse();
	std::cout << "Cur: ";
	for (LIST<char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	for (char c = 'b'; c <= 'z'; c++) {
		cur.push_back(c);
	}
	std::cout << "Cur: ";
	for (LIST<char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.reverse();
	std::cout << "Cur: ";
	for (LIST<char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	cur.reverse();
	std::cout << "Cur: ";
	for (LIST<char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_operators()
{
	std::cout << "Tests Operators: " << std::endl;

	LIST<int>	cur1;
	LIST<int>	cur2;
	LIST<int>	cur3;
	for (int i = 1; i <= 3; i++) {
		cur1.push_back(i);
		cur2.push_back(i);
	}
	for (int i = 3; i >= 1; i--) {
		cur3.push_back(i);
	}
	std::cout << "Cur1: ";
	for (LIST<int>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: ";
	for (LIST<int>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Cur3: ";
	for (LIST<int>::iterator it = cur3.begin(); it != cur3.end(); it++) {
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
}

void	test_final()
{
	LIST<int>			a;
	LIST<int>::iterator	it;
	int		c;
	int		i;

	std::cout << "Tests Final: " << std::endl;

	srand(time(NULL));
	for (int j(0); j < 20; j++) {
		i = rand() % 1000;
		while (i-- > 0) {
			c = rand() % 3;
			if (c == 0)
				a.push_back(rand() % 1000);
			else if (c == 1)
				a.push_front(rand() % 1000);
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
		it = a.begin();
		for (int k = rand() % 1000; k > 0; k--) {
			it++;
		}
		a.erase(it);
		std::cout << j << " " << std::endl;
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
	test_resize();
	test_splice();
	test_remove();
	test_unique();
	test_merge();
	test_sort();
	test_reverse();
	test_operators();
	test_final();

	return 0;
}
