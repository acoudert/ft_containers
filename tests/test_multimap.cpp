#include <map>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Multimap.hpp"

#ifndef STD
# define MULTIMAP	ft::Multimap
# define PAIR		ft::pair
# else
# define MULTIMAP	std::multimap
# define PAIR		std::pair
#endif

void	test_canonic()
{
	std::cout << "Tests Canonic: " << std::endl;

	MULTIMAP<char, int>::iterator		it_cur;

	MULTIMAP<char, int>		cur1;
	it_cur = cur1.begin();
	if (it_cur == cur1.end())
		std::cout << "Cur: Empty" << std::endl;

	char		c('a');
	for (int i = 1; i < 6; i++) {
		cur1.insert(PAIR<char, int>(c, i));
		cur1.insert(PAIR<char, int>(c, i + 5));
		c++;
	}
	it_cur = cur1.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur1.end())
	{
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	it_cur = cur1.begin();
	it_cur++;
	it_cur++;
	it_cur++;
	it_cur++;

	MULTIMAP<char, int>		cur2(cur1.begin(), it_cur);

	it_cur = cur2.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur2.end())
	{
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	MULTIMAP<char, int>		cur3(cur1);
	it_cur = cur3.begin();
	std::cout << "Cur: | ";
	while (it_cur != cur3.end())
	{
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	MULTIMAP<char, int>		cur4;

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

	MULTIMAP<short, short>		cur;
	for (short i = 10; i < 16; i++) {
		cur.insert(PAIR<short, short>(i, i));
		cur.insert(PAIR<short, short>(i, i));
	}

	MULTIMAP<short, short>::iterator	it_cur = cur.begin();

	std::cout << "Cur: | ";
	while (it_cur != cur.end())
	{
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur++;
	}
	std::cout << std::endl;

	it_cur = cur.end();
	it_cur++;
	std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
	std::cout << std::endl;
	it_cur++;
	it_cur++;
	std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur--;
	if (it_cur == cur.end())
		std::cout << "Ok" << std::endl;
	
	MULTIMAP<short, short>::const_iterator		c_it_cur = cur.end();

	c_it_cur--;
	std::cout << "Cur: | ";
	while (c_it_cur != cur.begin()) {
		std::cout << "[" << (*c_it_cur).first << "] " << (*c_it_cur).second << " | ";
		--c_it_cur;
	}
	std::cout << "[" << (*c_it_cur).first << "] " << (*c_it_cur).second;
	std::cout << std::endl;

	MULTIMAP<short, short>::reverse_iterator		r_it_cur = cur.rbegin();

	std::cout << "Cur: | ";
	while (r_it_cur != cur.rend()) {
		std::cout << "[" << (*r_it_cur).first << "] " << (*r_it_cur).second << " | ";
		++r_it_cur;
	}
	std::cout << std::endl;

	r_it_cur = cur.rend();
	r_it_cur++;
	std::cout << "[" << (*r_it_cur).first << "] " << (*r_it_cur).second << " | ";
	std::cout << std::endl;
	r_it_cur++;
	r_it_cur++;
	std::cout << "[" << (*r_it_cur).first << "] " << (*r_it_cur).second << " | ";
	std::cout << std::endl;

	MULTIMAP<short, short>::const_reverse_iterator		c_r_it_cur = cur.rbegin();

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
	
	MULTIMAP<double, std::string>		cur;
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	cur.insert(PAIR<double, std::string>(1, "Hello"));
	cur.insert(PAIR<double, std::string>(2, "Hola"));
	cur.insert(PAIR<double, std::string>(1, "Hello"));
	cur.insert(PAIR<double, std::string>(2, "Hola"));
	cur.insert(PAIR<double, std::string>(1, "Hello"));
	cur.insert(PAIR<double, std::string>(2, "Hola"));

	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	cur.insert(PAIR<double, std::string>(0.5, "Salut"));
	cur.insert(PAIR<double, std::string>(0, "Oye"));
	
	std::cout << "Cur: empty : " << std::boolalpha << cur.empty() << std::noboolalpha << std::endl;
	std::cout << "Cur: size : " << cur.size() << std::endl;

	if (cur.max_size() > 100000000000000)
		std::cout << "Ok" << std::endl;

	std::cout << std::endl;
}

void	test_insert()
{
	MULTIMAP<char, double>								cur;
	MULTIMAP<char, double>::iterator					it_cur = cur.begin();

	std::cout << "Tests Insert: " << std::endl;

	std::cout << "Cur: | " << std::boolalpha;
	for (char c('a'); c <= 'b'; c++) {
		it_cur = cur.insert(PAIR<char, double>(c, c + 3));
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur = cur.insert(PAIR<char, double>(c, c + 3));
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur = cur.insert(PAIR<char, double>(c, c + 3));
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
	}
	std::cout << std::noboolalpha << std::endl;

	std::cout << "Cur: | " << std::boolalpha;
	for (char c('c'); c <= 'd'; c++) {
		it_cur = cur.insert(PAIR<char, double>(c, c + 7));
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur = cur.insert(PAIR<char, double>(c, c + 7));
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
	}
	std::cout << std::noboolalpha << std::endl;

	it_cur = cur.begin();
	std::cout << "Cur: | " << std::boolalpha;
	for (char c('e'); c <= 'f'; c++) {
		it_cur = cur.insert(it_cur, PAIR<char, double>(c, c + 10));
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
		it_cur = cur.insert(it_cur, PAIR<char, double>(c, c + 10));
		std::cout << "[" << (*it_cur).first << "] " << (*it_cur).second << " | ";
	}
	std::cout << std::noboolalpha << std::endl;

	MULTIMAP<char, double>						cur2;

	it_cur = cur.begin();
	it_cur++;
	it_cur++;
	it_cur++;
	it_cur++;
	it_cur++;
	it_cur++;
	cur2.insert(it_cur, cur.end());
	it_cur = cur2.begin();
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

	MULTIMAP<int, int>				cur;
	MULTIMAP<int, int>::iterator		it_cur;

	for (int i = 1; i <= 10; i++) {
		if (i % 2) {
			cur.insert(PAIR<int, int>(i, i));
			cur.insert(PAIR<int, int>(i, i));
		}
		else {
			cur.insert(PAIR<int, int>(i, i));
			cur.insert(PAIR<int, int>(i, i));
			cur.insert(PAIR<int, int>(i, i));
		}
	}
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur.erase(cur.begin());
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur++;
	cur.erase(it_cur);
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.end();
	it_cur--;
	cur.erase(it_cur);
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(3) << std::endl;
	std::cout << cur.erase(4) << std::endl;
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(9) << std::endl;
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(5) << std::endl;
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << cur.erase(9) << std::endl;
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	it_cur = cur.begin();
	it_cur++;
	it_cur++;
	cur.erase(cur.begin(), it_cur);
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur.insert(PAIR<int, int>(9, 9));
	cur.insert(PAIR<int, int>(10, 10));

	it_cur = cur.begin();
	it_cur++;
	cur.erase(it_cur, cur.end());
	cur.erase(cur.begin(), cur.begin());
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur.erase(cur.begin(), cur.end());
	std::cout << "Cur: | ";
	for (MULTIMAP<int, int>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << "Size: " << cur.size() << std::endl;

	std::cout << std::endl;
}

void	test_swap()
{
	std::cout << "Tests Swap: " << std::endl;

	MULTIMAP<char, float>	cur1;
	MULTIMAP<char, float>	cur2;

	for (char c = 'a'; c <= 'd'; c++) {
		cur1.insert(PAIR<char, float>(c, static_cast<float>(c) + 0.5));
		cur1.insert(PAIR<char, float>(c + 4, static_cast<float>(c + 4) + 0.5));
		cur1.insert(PAIR<char, float>(c, static_cast<float>(c) + 0.5));
		cur1.insert(PAIR<char, float>(c + 4, static_cast<float>(c + 4) + 0.5));
	}
	cur1.insert(PAIR<char, float>('i', static_cast<float>('i') + 0.5));
	cur1.insert(PAIR<char, float>('j', static_cast<float>('j') + 0.5));

	std::cout << "Cur1: | ";
	for (MULTIMAP<char, float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (MULTIMAP<char, float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur1.swap(cur2);
	std::cout << "Cur1: | ";
	for (MULTIMAP<char, float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (MULTIMAP<char, float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur1.clear();
	std::cout << "Cur1: | ";
	for (MULTIMAP<char, float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (MULTIMAP<char, float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur1.swap(cur2);
	std::cout << "Cur1: | ";
	for (MULTIMAP<char, float>::iterator it = cur1.begin(); it != cur1.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Cur2: | ";
	for (MULTIMAP<char, float>::iterator it = cur2.begin(); it != cur2.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_clear()
{
	std::cout << "Tests Clear: " << std::endl;

	MULTIMAP<char, char>		cur;

	cur.clear();
	std::cout << "Cur: | ";
	for (MULTIMAP<char, char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	for (char c = 'a'; c <= 'e'; c++) {
		cur.insert(PAIR<char, char>(c, c));
		cur.insert(PAIR<char, char>(c, c));
	}
	std::cout << "Cur: | ";
	for (MULTIMAP<char, char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	cur.clear();
	std::cout << "Cur: | ";
	for (MULTIMAP<char, char>::iterator it = cur.begin(); it != cur.end(); it++) {
		std::cout << "[" << (*it).first << "] " << (*it).second << " | ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	test_observers()
{
	std::cout << "Tests Clear: " << std::endl;

	MULTIMAP<char, char>		cur;
	MULTIMAP<char, char>::key_compare		k = cur.key_comp();
	MULTIMAP<char, char>::value_compare		v = cur.value_comp();

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

	MULTIMAP<int, int>						cur;
	MULTIMAP<int, int>::iterator			it;

	for (int i = 0; i < 5; i++) {
		cur.insert(PAIR<int, int>(i, i * i));
		cur.insert(PAIR<int, int>(i, i * i));
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

	std::cout << std::endl;
}

void	test_count()
{
	std::cout << "Tests Count: " << std::endl;

	MULTIMAP<int, int>						cur;

	std::cout << "Count: " << cur.count(1) <<std::endl;

	for (int i = 0; i < 5; i++) {
		cur.insert(PAIR<int, int>(i, i * i));
		cur.insert(PAIR<int, int>(i, i * i));
	}

	std::cout << "Count: " << cur.count(1) <<std::endl;
	std::cout << "Count: " << cur.count(6) <<std::endl;

	std::cout << std::endl;
}

void	test_bound_range()
{
	std::cout << "Tests Bound: " << std::endl;

	MULTIMAP<char, char>					cur;
	MULTIMAP<char, char>::iterator			it;

	if (cur.end() == cur.lower_bound(0))
		std::cout << "Ok" << std::endl;
	if (cur.end() == cur.upper_bound(1))
		std::cout << "Ok" << std::endl;

	cur.insert(PAIR<char, char>('1', '1'));
	cur.insert(PAIR<char, char>('2', '2'));
	cur.insert(PAIR<char, char>('1', '1'));
	cur.insert(PAIR<char, char>('2', '2'));

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

	PAIR<MULTIMAP<char, char>::iterator, MULTIMAP<char, char>::iterator>	pa;
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

	MULTIMAP<const int, int>	a;
	int		i;

	srand(time(NULL));
	for (int j(0); j < 20; j++) {
		i = rand() % 1000;
		while (i-- > 0)
			a.insert(PAIR<int, const int>(rand() % 1000, rand() % 1000));
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
