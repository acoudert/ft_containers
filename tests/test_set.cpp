#include <set>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Set.hpp"

#ifndef STD
# define SET	ft::Set
# define PAIR	ft::pair
# else
# define SET	std::set
# define PAIR	std::pair
#endif

void	test_canonic()
{
	std::cout << "Tests Canonic: " << std::endl;

	SET<char>::iterator		it_cur;

	SET<char>		cur1;
	it_cur = cur1.begin();
	if (it_cur == cur1.end())
		std::cout << "Cur: Empty" << std::endl;

	char		c('a');
	for (int i = 1; i < 6; i++) {
		cur1.insert(c);
		c++;
	}
	it_cur = cur1.begin();
	it_cur++;
	it_cur++;

	SET<char>		cur2(cur1.begin(), it_cur);

	it_cur = cur2.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur2.end())
	{
		std::cout << *it_cur << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	SET<char>		cur3(cur1);
	it_cur = cur3.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur3.end())
	{
		std::cout << *it_cur << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	SET<char>		cur4;

	cur4 = cur3;
	it_cur = cur4.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur4.end())
	{
		std::cout << *it_cur << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_iterator()
{
	std::cout << "Tests Iterator: " << std::endl;

	SET<short>		cur;
	for (short i = 10; i < 16; i++) {
		cur.insert(i);
	}

	SET<short>::iterator	it_cur = cur.begin();

	std::cout << "Cur: | ";
	while (it_cur != cur.end())
	{
		std::cout << *it_cur << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	it_cur = cur.end();
	it_cur++;
	std::cout << *it_cur;
	std::cout << std::endl;
	it_cur++;
	it_cur++;
	std::cout << *it_cur;
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur--;
	if (it_cur == cur.end())
		std::cout << "Ok" << std::endl;
	
	SET<short>::const_iterator		c_it_cur = cur.end();

	c_it_cur--;
	std::cout << "Cur: | ";
	while (c_it_cur != cur.begin()) {
		std::cout << *c_it_cur << " | ";
		--c_it_cur;
	}
	std::cout << *c_it_cur << " | ";
	std::cout << std::endl;

	SET<short>::reverse_iterator		r_it_cur = cur.rbegin();

	std::cout << "Cur: | ";
	while (r_it_cur != cur.rend()) {
		std::cout << *r_it_cur << " | ";
		++r_it_cur;
	}
	std::cout << std::endl;

	r_it_cur = cur.rend();
	r_it_cur++;
	std::cout << *r_it_cur;
	std::cout << std::endl;
	r_it_cur++;
	r_it_cur++;
	std::cout << *r_it_cur;
	std::cout << std::endl;

	SET<short>::const_reverse_iterator		c_r_it_cur = cur.rbegin();

	std::cout << "Cur: | ";
	while (c_r_it_cur != cur.rend()) {
		std::cout << *c_r_it_cur << " | ";
		++c_r_it_cur;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_capacity()
{
	std::cout << "Tests Capacity: " << std::endl;
	
	SET<long long>		cur;
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	cur.insert(1);
	cur.insert(2);

	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	cur.insert(5);
	cur.insert(0);
	
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	if (cur.max_size() > 100000000000000)
		std::cout << "Ok" << std::endl;

	std::cout << std::endl;
}

void	test_insert()
{
	SET<char>								cur;
	PAIR<SET<char>::iterator, bool>			pa;
	SET<char>::iterator						it_cur = cur.begin();

	std::cout << "Tests Insert: " << std::endl;

	std::cout << "Cur: | " << std::boolalpha;
	for (char c('a'); c <= 'b'; c++) {
		pa = cur.insert(c);
		it_cur = pa.first;
		std::cout << *it_cur << " " << pa.second << " | ";
	}
	std::cout << std::noboolalpha << std::endl;

	std::cout << "Cur: | " << std::boolalpha;
	for (char c('a'); c <= 'd'; c++) {
		pa = cur.insert(c);
		it_cur = pa.first;
		std::cout << *it_cur << " " << pa.second << " | ";
	}
	std::cout << std::noboolalpha << std::endl;

	it_cur = cur.begin();
	std::cout << "Cur: | " << std::boolalpha;
	for (char c('c'); c <= 'f'; c++) {
		it_cur = cur.insert(it_cur, c);
		std::cout << *it_cur << " | ";
	}
	std::cout << std::noboolalpha << std::endl;

	SET<char>						cur2;

	it_cur = cur.begin();
	it_cur++;
	cur2.insert(it_cur, cur.end());
	it_cur = cur2.begin();
	std::cout << "Cur: | " << std::boolalpha;
	while (it_cur != cur2.end()) {
		std::cout << *it_cur << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_erase()
{
	std::cout << "Tests Erase: " << std::endl;

	SET<int>				cur;
	SET<int>::iterator		it_cur;

	for (int i = 1; i <= 10; i++) {
		cur.insert(i);
	}
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;
	
	it_cur = cur.find(4);
	cur.erase(it_cur);
	cur.erase(cur.begin());
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur++;
	cur.erase(it_cur);
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.end();
	it_cur--;
	cur.erase(it_cur);
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(2) << std::endl;
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(9) << std::endl;
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(5) << std::endl;
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(9) << std::endl;
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur++;
	it_cur++;
	cur.erase(cur.begin(), it_cur);
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	cur.insert(9);
	cur.insert(10);

	it_cur = cur.begin();
	it_cur++;
	cur.erase(it_cur, cur.end());
	cur.erase(cur.begin(), cur.begin());
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	cur.erase(cur.begin(), cur.end());
	std::cout << "Cur: | ";
	for (SET<int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;


	std::cout << "Size: " << cur.size() << std::endl;

	std::cout << std::endl;
}

void	test_swap()
{
	std::cout << "Tests Swap: " << std::endl;

	SET<char>	cur1;
	SET<char>	cur2;

	for (char c = 'a'; c <= 'd'; c++) {
		cur1.insert(c);
		cur2.insert(c + 4);
	}
	cur2.insert('i');
	cur2.insert('j');
	std::cout << "Cur1: | ";
	for (SET<char>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (SET<char>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	cur1.swap(cur2);
	std::cout << "Cur1: | ";
	for (SET<char>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (SET<char>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	cur1.clear();
	std::cout << "Cur1: | ";
	for (SET<char>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (SET<char>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	cur1.swap(cur2);
	std::cout << "Cur1: | ";
	for (SET<char>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (SET<char>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_clear()
{
	std::cout << "Tests Clear: " << std::endl;

	SET<char>		cur;

	cur.clear();
	std::cout << "Cur: | ";
	for (SET<char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	for (char c = 'a'; c <= 'e'; c++) {
		cur.insert(c);
	}
	std::cout << "Cur: | ";
	for (SET<char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	cur.clear();
	std::cout << "Cur: | ";
	for (SET<char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << *it << " | ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_observers()
{
	std::cout << "Tests Clear: " << std::endl;

	SET<char>		cur;
	SET<char>::key_compare		k = cur.key_comp();
	SET<char>::value_compare	v = cur.value_comp();

	std::cout << std::boolalpha;
	std::cout << k('a', 'b') << std::endl;
	std::cout << k('b', 'a') << std::endl;
	std::cout << k('a', 'a') << std::endl;

	std::cout << v('a', 'b') << std::endl;
	std::cout << v('b', 'a') << std::endl;
	std::cout << v('a', 'a') << std::endl;
	std::cout << std::noboolalpha;

	std::cout << std::endl;
}

void	test_find()
{
	std::cout << "Tests Find: " << std::endl;

	SET<int>						cur;
	SET<int>::iterator				it;

	for (int i = 0; i < 5; i++) {
		cur.insert(i);
	}

	it = cur.find(0);
	std::cout << *it << std::endl;
	it = cur.find(2);
	std::cout << *it << std::endl;
	it = cur.find(4);
	std::cout << *it << std::endl;
	it = cur.find(6);
	if (it == cur.end())
		std::cout << "Ok" << std::endl;

	std::cout << std::endl;
}

void	test_count()
{
	std::cout << "Tests Count: " << std::endl;

	SET<int>						cur;

	std::cout << "Count: " << cur.count(1) <<std::endl;

	for (int i = 0; i < 5; i++) {
		cur.insert(i);
	}

	std::cout << "Count: " << cur.count(1) <<std::endl;
	std::cout << "Count: " << cur.count(6) <<std::endl;

	std::cout << std::endl;
}

void	test_bound_range()
{
	std::cout << "Tests Bound: " << std::endl;

	SET<char>					cur;
	SET<char>::iterator		it;

	if (cur.end() == cur.lower_bound(0))
		std::cout << "Ok" << std::endl;
	if (cur.end() == cur.upper_bound(1))
		std::cout << "Ok" << std::endl;

	cur.insert('1');
	cur.insert('2');

	it = cur.lower_bound('0');
	std::cout << *it << std::endl;
	it = cur.lower_bound('1');
	std::cout << *it << std::endl;
	it = cur.lower_bound('2');
	std::cout << *it << std::endl;
	it = cur.lower_bound('3');
	if (it == cur.end())
		std::cout << "Ok" << std::endl;

	it = cur.upper_bound('0');
	std::cout << *it << std::endl;
	it = cur.upper_bound('1');
	std::cout << *it << std::endl;
	it = cur.upper_bound('2');
	if (it == cur.end())
		std::cout << "Ok" << std::endl;

	PAIR<SET<char>::iterator, SET<char>::iterator>	pa;
	pa = cur.equal_range('0');
	it = pa.first;
	std::cout << *it << std::endl;
	it = pa.second;
	std::cout << *it << std::endl;
	pa = cur.equal_range('1');
	it = pa.first;
	std::cout << *it << std::endl;
	it = pa.second;
	std::cout << *it << std::endl;
	pa = cur.equal_range('2');
	it = pa.first;
	std::cout << *it << std::endl;
	it = pa.second;
	if (it == cur.end())
		std::cout << "Ok" << std::endl;
	pa = cur.equal_range('3');
	it = pa.first;
	if (it == cur.end())
		std::cout << "Ok" << std::endl;
	it = pa.second;
	if (it == cur.end())
		std::cout << "Ok" << std::endl;

	std::cout << std::endl;
}

void	test_final()
{
	std::cout << "Tests Final: " << std::endl;

	SET<int>	a;
	int		i;

	srand(time(NULL));
	for (int j(0); j < 20; j++) {
		i = rand() % 1000;
		while (i-- > 0) {
			a.insert(rand() % 1000);
		}
		for (int k = rand() % 1000; k > 0; k--) {
			a.erase(k);
		}
		a.clear();
		std::cout << j << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

int		main()
{
	test_canonic();
	test_iterator();
	test_capacity();
	test_insert();
	test_erase();
	test_swap();
	test_clear();
	test_observers();
	test_find();
	test_count();
	test_bound_range();
	test_final();

	return 0;
}
