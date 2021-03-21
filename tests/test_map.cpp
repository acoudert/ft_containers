#include <map>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Map.hpp"

#ifndef STD
# define MAP	ft::Map
# define PAIR	ft::pair
# else
# define MAP	std::map
# define PAIR	std::pair
#endif

void	test_canonic()
{
	std::cout << "Tests Canonic: " << std::endl;

	MAP<char, int>::iterator		it_cur;

	MAP<char, int>		cur1;
	it_cur = cur1.begin();
	if (it_cur == cur1.end())
		std::cout << "Cur: Empty" << std::endl;

	char		c('a');
	for (int i = 1; i < 6; i++) {
		cur1[c] = i;
		c++;
	}
	it_cur = cur1.begin();
	it_cur++;
	it_cur++;

	MAP<char, int>		cur2(cur1.begin(), it_cur);

	it_cur = cur2.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur2.end())
	{
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	MAP<char, int>		cur3(cur1);
	it_cur = cur3.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur3.end())
	{
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	MAP<char, int>		cur4;

	cur4 = cur3;
	it_cur = cur4.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur4.end())
	{
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_iterator()
{
	std::cout << "Tests Iterator: " << std::endl;

	MAP<short, short>		cur;
	for (short i = 10; i < 16; i++) {
		cur[i] = i;
	}

	MAP<short, short>::iterator	it_cur = cur.begin();

	std::cout << "Cur: | ";
	while (it_cur != cur.end())
	{
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur.end())
	{
		(*it_cur).second = (*it_cur).second + 5;
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	it_cur = cur.end();
	it_cur++;
	std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second;
	std::cout << std::endl;
	it_cur++;
	it_cur++;
	std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second;
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur--;
	if (it_cur == cur.end())
		std::cout << "Ok" << std::endl;

	it_cur = cur.end();
	MAP<short, short>::const_iterator		c_it_cur = it_cur;

	c_it_cur--;
	std::cout << "Cur: | ";
	while (c_it_cur != cur.begin()) {
		std::cout << "[" << (*c_it_cur).first << "] " << (*c_it_cur).second << " | ";
		--c_it_cur;
	}
	std::cout << "[" << (*c_it_cur).first << "] " << (*c_it_cur).second << " | ";
	std::cout << std::endl;

	MAP<short, short>::reverse_iterator		r_it_cur = cur.rbegin();

	std::cout << "Cur: | ";
	while (r_it_cur != cur.rend()) {
		std::cout << "[" << (*r_it_cur).first << "] " << (*r_it_cur).second << " | ";
		++r_it_cur;
	}
	std::cout << std::endl;

	r_it_cur = cur.rend();
	r_it_cur++;
	std::cout << "[" << (*r_it_cur).first << "] " << (*r_it_cur).second;
	std::cout << std::endl;
	r_it_cur++;
	r_it_cur++;
	std::cout << "[" << (*r_it_cur).first << "] " << (*r_it_cur).second;
	std::cout << std::endl;

	MAP<short, short>::const_reverse_iterator		c_r_it_cur = cur.rbegin();

	std::cout << "Cur: | ";
	while (c_r_it_cur != cur.rend()) {
		std::cout << "[" << (*c_r_it_cur).first << "] " << (*c_r_it_cur).second << " | ";
		++c_r_it_cur;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_capacity()
{
	std::cout << "Tests Capacity: " << std::endl;
	
	MAP<double, std::string>		cur;
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	cur[1.5] = "Hello";
	cur[2.4] = "Hola";

	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	cur[0.5] = "Salut";
	cur[0] = "Oye";
	
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	if (cur.max_size() > 100000000000000)
		std::cout << "Ok" << std::endl;

	std::cout << std::endl;
}

void	test_element_access()
{
	std::cout << "Tests Element Access: " << std::endl;

	MAP<int, int>				cur;

	cur[1] = 10;
	cur[2] = 12;
	cur[3] = 20;
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur[1] = 20;
	cur[2] = 15;
	cur[3] = 1;
	cur[7] = 62;
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_insert()
{
	MAP<char, double>						cur;
	PAIR<MAP<char, double>::iterator, bool>	pa;
	MAP<char, double>::iterator				it_cur = cur.begin();
	double									d(-2.5);

	std::cout << "Tests Insert: " << std::endl;

	std::cout << "Cur: | " << std::boolalpha;
	for (char c('a'); c <= 'b'; c++) {
		pa = cur.insert(PAIR<char, double>(c, d));
		it_cur = pa.first;
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second \
			<< " " << pa.second << " | ";
		d += 1.0;
	}
	std::cout << std::noboolalpha << std::endl;

	std::cout << "Cur: | " << std::boolalpha;
	for (char c('a'); c <= 'd'; c++) {
		pa = cur.insert(PAIR<char, double>(c, d));
		it_cur = pa.first;
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second \
			<< " " << pa.second << " | ";
		d += 1.0;
	}
	std::cout << std::noboolalpha << std::endl;

	it_cur = cur.begin();
	std::cout << "Cur: | " << std::boolalpha;
	for (char c('c'); c <= 'f'; c++) {
		it_cur = cur.insert(it_cur, PAIR<char, double>(c, d));
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		d += 1.0;
	}
	std::cout << std::noboolalpha << std::endl;

	MAP<char, double>						cur2;

	cur2.insert(cur.begin(), cur.end());
	it_cur = cur2.begin();
	it_cur++;
	it_cur++;
	std::cout << "Cur: | " << std::boolalpha;
	while (it_cur != cur2.end()) {
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_erase()
{
	std::cout << "Tests Erase: " << std::endl;

	MAP<int, int>				cur;
	MAP<int, int>::iterator		it_cur;

	for (int i = 1; i <= 10; i++) {
		cur.insert(PAIR<int, int>(i, i));
	}
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.find(4);
	cur.erase(it_cur);
	cur.erase(cur.begin());
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur++;
	cur.erase(it_cur);
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.end();
	it_cur--;
	cur.erase(it_cur);
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(2) << std::endl;
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(9) << std::endl;
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(5) << std::endl;
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(9) << std::endl;
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur++;
	it_cur++;
	cur.erase(cur.begin(), it_cur);
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << std::endl;
	cur[9] = 9;
	cur[10] = 10;

	it_cur = cur.begin();
	it_cur++;
	cur.erase(it_cur, cur.end());
	cur.erase(cur.begin(), cur.begin());
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur.erase(cur.begin(), cur.end());
	std::cout << "Cur: | ";
	for (MAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << "Size: " << cur.size() << std::endl;

	std::cout << std::endl;
}

void	test_swap()
{
	std::cout << "Tests Swap: " << std::endl;

	MAP<char, float>	cur1;
	MAP<char, float>	cur2;

	for (char c = 'a'; c <= 'd'; c++) {
		cur1[c] = static_cast<float>(c) + 0.5;
		cur2[c + 4] = static_cast<float>(c + 5) + 0.5;
	}
	cur2['i'] = 106.5;
	cur2['j'] = 107.5;
	std::cout << "Cur1: | ";
	for (MAP<char, float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (MAP<char, float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur1.swap(cur2);
	std::cout << "Cur1: | ";
	for (MAP<char, float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (MAP<char, float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur1.clear();
	std::cout << "Cur1: | ";
	for (MAP<char, float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (MAP<char, float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur1.swap(cur2);
	std::cout << "Cur1: | ";
	for (MAP<char, float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (MAP<char, float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_clear()
{
	std::cout << "Tests Clear: " << std::endl;

	MAP<char, char>		cur;

	cur.clear();
	std::cout << "Cur: | ";
	for (MAP<char, char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	for (char c = 'a'; c <= 'e'; c++) {
		cur[c] = c;
	}
	std::cout << "Cur: | ";
	for (MAP<char, char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur.clear();
	std::cout << "Cur: | ";
	for (MAP<char, char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_observers()
{
	std::cout << "Tests Clear: " << std::endl;

	MAP<char, char>		cur;
	MAP<char, char>::key_compare	k = cur.key_comp();
	MAP<char, char>::value_compare	v = cur.value_comp();

	std::cout << std::boolalpha;
	std::cout << k('a', 'b') << std::endl;
	std::cout << k('b', 'a') << std::endl;
	std::cout << k('a', 'a') << std::endl;

	std::cout << v(PAIR<char, char>('a', char()), PAIR<char, char>('b', char())) << std::endl;
	std::cout << v(PAIR<char, char>('b', char()), PAIR<char, char>('a', char())) << std::endl;
	std::cout << v(PAIR<char, char>('a', char()), PAIR<char, char>('a', char())) << std::endl;
	std::cout << std::noboolalpha;

	std::cout << std::endl;
}

void	test_find()
{
	std::cout << "Tests Find: " << std::endl;

	MAP<int, int>						cur;
	MAP<int, int>::iterator				it;
	MAP<int, int>::const_iterator		c_it;

	for (int i = 0; i < 5; i++) {
		cur[i] = i * i;
	}

	it = cur.find(0);
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = cur.find(2);
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = cur.find(4);
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = cur.find(6);
	if (it == cur.end())
		std::cout << "Ok" << std::endl;

	c_it = cur.find(0);
	std::cout << "[" << (*c_it).first << "] " << (*c_it).second << std::endl;
	c_it = cur.find(2);
	std::cout << "[" << (*c_it).first << "] " << (*c_it).second << std::endl;
	c_it = cur.find(4);
	std::cout << "[" << (*c_it).first << "] " << (*c_it).second << std::endl;
	c_it = cur.find(-1);
	if (it == cur.end())
		std::cout << "Ok" << std::endl;

	std::cout << std::endl;
}

void	test_count()
{
	std::cout << "Tests Count: " << std::endl;

	MAP<int, int>						cur;

	std::cout << "Count: " << cur.count(1) <<std::endl;

	for (int i = 0; i < 5; i++) {
		cur[i] = i * i;
	}

	std::cout << "Count: " << cur.count(1) <<std::endl;
	std::cout << "Count: " << cur.count(6) <<std::endl;

	std::cout << std::endl;
}

void	test_bound_range()
{
	std::cout << "Tests Bound: " << std::endl;

	MAP<char, char>					cur;
	MAP<char, char>::iterator		it;

	if (cur.end() == cur.lower_bound(0))
		std::cout << "Ok" << std::endl;
	if (cur.end() == cur.upper_bound(1))
		std::cout << "Ok" << std::endl;

	cur['1'] = '1';
	cur['2'] = '2';

	it = cur.lower_bound('0');
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = cur.lower_bound('1');
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = cur.lower_bound('2');
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = cur.lower_bound('3');
	if (it == cur.end())
		std::cout << "Ok" << std::endl;

	it = cur.upper_bound('0');
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = cur.upper_bound('1');
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = cur.upper_bound('2');
	if (it == cur.end())
		std::cout << "Ok" << std::endl;

	PAIR<MAP<char, char>::iterator, MAP<char, char>::iterator>	pa;
	pa = cur.equal_range('0');
	it = pa.first;
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = pa.second;
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	pa = cur.equal_range('1');
	it = pa.first;
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	it = pa.second;
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
	pa = cur.equal_range('2');
	it = pa.first;
	std::cout << "[" << (*it).first << "] " << (*it).second << std::endl;
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

	MAP<const int, int>	a;
	int		c;
	int		i;

	srand(time(NULL));
	for (int j(0); j < 20; j++) {
		i = rand() % 1000;
		while (i > 0) {
			c = rand() % 1000;
			a[c] = rand() % 1000;
			i--;
		}
		for (int k = rand() % 1000; k > 0; k--) {
			a.erase(k);
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
