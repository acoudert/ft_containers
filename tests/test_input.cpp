#include "List.hpp"
#include "Vector.hpp"
#include "Map.hpp"
#include "Set.hpp"
#include "Multiset.hpp"
#include "Multimap.hpp"
#include <cstdlib>
#include <ctime>

template <typename C>
void	insert(C & container, int n)
{
	container.insert(container.begin(), n);
}

template <>
void	insert< ft::Map<int, int> >(ft::Map<int, int> & container, int n)
{
	ft::pair<int, int>	pa(n, 0);
	container.insert(pa);
}

template <>
void	insert< ft::Multimap<int, int> >(ft::Multimap<int, int> & container, int n)
{
	ft::pair<int, int>	pa(n, 0);
	container.insert(pa);
}

template <typename C>
void	erase(C & container)
{
	int		to_erase;

	std::cout << "Elems: ";
	for (typename C::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Type elem to erase: ";
	std::cin >> to_erase;
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	container.erase(to_erase);
}

template <>
void	erase< ft::List<int> >(ft::List<int> & container)
{
	int		to_erase;

	std::cout << "Elems: ";
	for (ft::List<int>::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Type elem to erase: ";
	std::cin >> to_erase;
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	ft::List<int>::iterator		it(container.begin());

	while (it != container.end()) {
		if (*it == to_erase) {
			container.erase(it);
			break ;
		}
		it++;
	}
}

template <>
void	erase< ft::Vector<int> >(ft::Vector<int> & container)
{
	int		to_erase;

	std::cout << "Elems: ";
	for (ft::Vector<int>::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Type elem to erase: ";
	std::cin >> to_erase;
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	ft::Vector<int>::iterator		it(container.begin());

	while (it != container.end()) {
		if (*it == to_erase) {
			container.erase(it);
			break ;
		}
		it++;
	}
}

template <>
void	erase< ft::Map<int, int> >(ft::Map<int, int> & container)
{
	int		to_erase;

	std::cout << "Elems: ";
	for (ft::Map<int, int>::iterator it = container.begin(); it != container.end(); it++)
		std::cout << (*it).first << " ";
	std::cout << std::endl;

	std::cout << "Type elem to erase: ";
	std::cin >> to_erase;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	
	container.erase(to_erase);
}

template <>
void	erase< ft::Multimap<int, int> >(ft::Multimap<int, int> & container)
{
	int		to_erase;

	std::cout << "Elems: ";
	for (ft::Multimap<int, int>::iterator it = container.begin(); it != container.end(); it++)
		std::cout << (*it).first << " ";
	std::cout << std::endl;

	std::cout << "Type elem to erase: ";
	std::cin >> to_erase;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	
	container.erase(to_erase);
}

template <typename C>
void	test(int nb_elem)
{
	C							container;
	typename C::iterator		it;

	srand(time(NULL));
	while (nb_elem-- > 0)
		insert<C>(container, rand() % 100);
	while (container.size())
		erase<C>(container);
}

int		main()
{
	int				nb_elem;
	std::string		input;

	std::cout << "How many elements in container: ";
	std::cin >> nb_elem;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	if (nb_elem <= 0)
		return 1;
	std::cout << "Type 'list', 'vector', 'map', 'set', 'multiset' or 'multimap': ";
	std::cin >> input;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	if (input == "list")
		test< ft::List<int> >(nb_elem);
	else if (input == "vector")
		test< ft::Vector<int> >(nb_elem);
	else if (input == "map")
		test< ft::Map<int, int> >(nb_elem);
	else if (input == "set")
		test< ft::Set<int> >(nb_elem);
	else if (input == "multiset")
		test< ft::Multiset<int> >(nb_elem);
	else if (input == "multimap")
		test< ft::Multimap<int, int> >(nb_elem);

	return 0;
}
