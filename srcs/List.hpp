#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include "iterator.hpp"
# include "utils.hpp"

namespace ft {

/*
 * List Iterators
 * /usr/include/c++/9/bits/stl_list.h if using 42 VM
 * https://www.cplusplus.com/reference/list/
*/
template <typename T>
struct	ListNode
{
	ListNode() : next(NULL), prev(NULL) {}
	ListNode(T const & _data) : next(NULL), prev(NULL), data(_data) {}
	ListNode(ListNode<T> const & src) { *this = src; }
	~ListNode() {}
	ListNode<T> &	operator=(ListNode<T> const & src) {
		this->next = src.next;
		this->prev = src.prev;
		this->data = src.data;
		return *this;
	}

	ListNode<T> *	next;
	ListNode<T> *	prev;
	T				data;
};

template <typename T>
struct	ListIterator : public iterator<bidirectional_iterator_tag, T>
{
	// Member Typedefs
	typedef T																	value_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T *																	pointer;
	typedef T &																	reference;
	typedef bidirectional_iterator_tag											iterator_category;

	// Member Attributes
	ListNode<T> *	node;

	// Canonic Class
	ListIterator() : node(NULL) {}
	ListIterator(ListNode<T> * x) : node(x) {}
	ListIterator(ListIterator<T> const & x) : node(x.node) {}
	virtual ~ListIterator() {}
	ListIterator &	operator=(ListIterator<T> const & x) {
		this->node = x.node;
		return *this;
	}

	// Member Functions
	reference	operator*() const {
		return this->node->data;
	}
	pointer		operator->() const {
		return &(this->node->data);
	}
	ListIterator<T> &	operator++() {
		this->node = this->node->next;
		return (*this);
	}
	ListIterator<T>		operator++(int) {
		ListIterator<T>		temp = *this;

		this->node = this->node->next;
		return (temp);
	}
	ListIterator<T> &	operator--() {
		this->node = this->node->prev;
		return (*this);
	}
	ListIterator<T>		operator--(int) {
		ListIterator<T>		temp = *this;

		this->node = this->node->prev;
		return (temp);
	}
	// Friend used to allow non binary operations
	inline friend bool	operator==(ListIterator<T> const & x, ListIterator<T> const & y) {
		return x.node == y.node;
	}
	inline friend bool	operator!=(ListIterator<T> const & x, ListIterator<T> const & y) {
		return x.node != y.node;
	}
};

template <typename T>
struct	ListConstIterator : public iterator<bidirectional_iterator_tag, T>
{
	// Member Typedefs
	typedef T																	value_type;
	typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T const *															pointer;
	typedef T const &															reference;
	typedef bidirectional_iterator_tag											iterator_category;

	// Member Attributes
	ListNode<T> *	node;

	// Canonic Class
	ListConstIterator() : node(NULL) {}
	ListConstIterator(ListNode<T> * x) : node(x) {}
	ListConstIterator(ListIterator<T> const & x) : node(x.node) {}
	ListConstIterator(ListConstIterator<T> const & x) : node(x.node) {}
	virtual ~ListConstIterator() {}
	ListConstIterator &	operator=(ListConstIterator const & x) {
		this->node = x.node;
		return *this;
	}

	// Member Functions
	reference	operator*() const {
		return this->node->data;
	}
	pointer		operator->() const {
		return &(this->node->data);
	}
	ListConstIterator<T> &	operator++() {
		this->node = this->node->next;
		return (*this);
	}
	ListConstIterator<T>		operator++(int) {
		ListConstIterator<T>		temp = *this;

		this->node = this->node->next;
		return (temp);
	}
	ListConstIterator<T> &	operator--() {
		this->node = this->node->prev;
		return (*this);
	}
	ListConstIterator<T>		operator--(int) {
		ListConstIterator<T>		temp = *this;

		this->node = this->node->prev;
		return (temp);
	}
	// Friend used to allow non binary operations
	inline friend bool	operator==(ListConstIterator<T> const & x, ListConstIterator<T> const & y) {
		return x.node == y.node;
	}
	inline friend bool	operator!=(ListConstIterator<T> const & x, ListConstIterator<T> const & y) {
		return x.node != y.node;
	}
};

/*
 * List Class
 * /usr/include/c++/9/bits/stl_list.h if using 42 VM
 * https://www.cplusplus.com/reference/list/
*/
template < class T, class Alloc = std::allocator<T> >
class List
{
public:
	// Member Typedefs
	typedef T													value_type;
	typedef Alloc												allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
	typedef ListIterator<T>										iterator;
	typedef ListConstIterator<T>								const_iterator;
	typedef reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef size_t												size_type;

	// Canonic Class
	explicit List(const allocator_type & alloc = allocator_type()) : _alloc(alloc) {
		this->_createLast();
	}
	explicit List(size_type n, const value_type & val = value_type(),
			const allocator_type & alloc = allocator_type()) : _alloc(alloc) {
		iterator			it;

		this->_createLast();
		it = this->begin();
		while (n-- > 0) {
			this->insert(it, val);
		}
	}
	template <class InputIterator>
	List(InputIterator first, InputIterator last
			, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
				: _alloc(alloc) {
		this->_createLast();
		while (first != last) {
			this->insert(this->end(), *first);
			first++;
		}
	}
	List(List<T> const & x) {
		this->_createLast();
		*this = x;
	}
	virtual ~List() {
		this->clear();
		this->_deleteNode(this->end().node);
	}
	List<T> &	operator=(List<T> const & src) {
		const_iterator	it = src.begin();

		this->clear();
		this->_deleteNode(this->_last);
		this->_createLast();
		this->insert(this->begin(), src.begin(), src.end());
		return *this;
	}

	// Member Iterator Functions
	iterator		begin() { return iterator(this->_last->next); }
	const_iterator	begin() const { return const_iterator(this->_last->next); }
	iterator		end() { return iterator(this->_last); }
	const_iterator	end() const { return const_iterator(this->_last); }
	reverse_iterator rbegin() { return reverse_iterator(this->_last->prev); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_last->prev); }
	reverse_iterator rend() { return reverse_iterator(this->_last); }
	const_reverse_iterator rend() const { return const_reverse_iterator(this->_last); }

	// Member Capacity Functions
	bool		empty() const { return this->_last == this->_last->prev; }
	size_type	size() const {
		size_type	size = 0;
		
		for (const_iterator it = this->begin(); it != this->end(); it++)
			size++;
		return size;
	}
	size_type	max_size() const { return _node_alloc.max_size(); }

	// Member Element Access Functions
	reference	front() { return this->_last->next->data; }
	const_reference	front() const { return this->_last->next->data; }
	reference	back() { return this->_last->prev->data; }
	const_reference	back() const { return this->_last->prev->data; }

	// Member Modifier Functions
	template <class InputIterator>
	void	assign (InputIterator first, InputIterator last
			, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL) {
		this->clear();
		this->_deleteNode(this->_last);
		this->_createLast();
		while (first != last) {
			this->insert(this->end(), *first);
			first++;
		}
	}
	void	assign(size_type n, value_type const & val) {
		this->clear();
		this->_deleteNode(this->_last);
		this->_createLast();
		for (size_type i = 0; i < n; i++) {
			this->insert(this->end(), val);
		}
	}
	void	push_front(value_type const & val) {
		this->insert(this->begin(), val);
	}
	void	pop_front() {
		ListNode<T> *	next = this->_last->next->next;

		if (this->empty())
			return ;
		this->_deleteNode(this->_last->next);
		this->_last->next = next;
		next->prev = this->_last;
	}
	void	push_back(value_type const & val) {
		this->insert(this->end(), val);
	}
	void	pop_back() {
		ListNode<T> *	prev = this->_last->prev->prev;

		if (this->empty())
			return ;
		this->_deleteNode(this->_last->prev);
		this->_last->prev = prev;
		prev->next = this->_last;
	}
	iterator	insert(iterator position, const value_type & val) {
		ListNode<T> *		node = _createNode(val);
		ListNode<T> *		next = position.node;

		node->next = next;
		node->prev = next->prev;
		node->prev->next = node;
		next->prev = node;
		return --position;
	}
	void		insert(iterator position, size_type n, const value_type & val) {
		for (size_type i = 0; i < n; i++) {
			this->insert(position, val);
		}
	}
	template <class InputIterator>
	void		insert(iterator position
			, InputIterator first, InputIterator last
			, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL) {
		while (first != last) {
			this->insert(position, *first);
			first++;
		}
	}
	iterator	erase(iterator position) {
		ListNode<T> *	prev = position.node->prev;
		ListNode<T> *	next = position.node->next;

		if (this->empty() || position.node == this->_last)
			return position;
		this->_deleteNode(position.node);
		prev->next = next;
		next->prev = prev;
		return iterator(next);
	}
	iterator	erase(iterator first, iterator last) {
		iterator		next = first;

		next++;
		while (first != last) {
			this->erase(first);
			first = next;
			next++;
		}
		return last;
	}
	void	swap(List & x) {
		List<T>		temp(*this);

		*this = x;
		x = temp;
	}
	void	resize(size_type n, value_type val = value_type()) {
		iterator	it = this->begin();

		if (n < this->size()) {
			for (size_type i = 0; i < n; i++) {
				it++;
			}
			this->erase(it, this->end());
		}
		else 
			this->insert(this->end(), n - this->size(), val);
	}
	void	clear() {
		iterator	it_prev = this->begin();
		iterator	it_next = this->begin();

		it_next++;
		while (it_prev != this->end()) {
			this->_deleteNode(it_prev.node);
			it_prev = it_next;
			it_next++;
		}
		this->_deleteNode(this->_last);
		this->_createLast();
	}

	// Member Operations
	void	splice(iterator position, List & x) {
		ListNode<T> *	next_x = position.node->prev;
		size_type		n = x.size();

		while (n--) {
			next_x = x._last->next->next;
			x._last->next->prev = position.node->prev;
			x._last->next->next = position.node;
			position.node->prev->next = x._last->next;
			position.node->prev = x._last->next;
			x._last->next = next_x;
		}
	}
	void	splice(iterator position, List & x, iterator i) {
		ListNode<T> *	prev = position.node->prev;

		if (i.node == x.end())
			return ;
		i.node->prev->next = i.node->next;
		i.node->next->prev = i.node->prev;
		position.node->prev = i.node;
		i.node->next = position.node;
		prev->next = i.node;
		i.node->prev = prev;
	}
	void	splice(iterator position, List & x, iterator first, iterator last) {
		iterator		next = first;

		while (first != last) {
			next++;
			this->splice(position, x, first);
			first = next;
		}
	}
	void	remove(value_type const & val) {
		iterator	it_temp;
		iterator	ite = this->end();

		for (iterator it = this->begin(); it != ite; it++) {
			it_temp = it;
			it_temp++;
			if (*it == val) {
				this->erase(it);
				it = --it_temp;
			}
		}
	}
	template <class Predicate>
	void	remove_if(Predicate pred) {
		iterator	it_temp;
		iterator	ite = this->end();

		for (iterator it = this->begin(); it != ite; it++) {
			it_temp = it;
			it_temp++;
			if (pred(*it) == true) {
				this->erase(it);
				it = --it_temp;
			}
		}
	}
	void	unique() {
		iterator	it_next;
		iterator	ite = this->end();

		for (iterator it = this->begin(); it != ite; it++) {
			it_next = it;
			it_next++;
			if (*it == *it_next) {
				this->erase(it_next);
				it_next = --it;
			}
		}
	}
	template <class BinaryPredicate>
	void	unique(BinaryPredicate binary_pred) {
		iterator	it_next;
		iterator	ite = this->end();

		for (iterator it = this->begin(); it != ite; it++) {
			it_next = it;
			it_next++;
			if (binary_pred(*it_next, *it) == true) {
				this->erase(it_next);
				it_next = --it;
			}
		}
	}
	void	merge(List & x) {
		iterator	it = this->begin();
		iterator	ite = this->end();
		iterator	it_x = x.begin();
		iterator	ite_x = x.end();

		if (this == &x)
			return ;
		while (it != ite || it_x != ite_x) {
			if (*it_x < *it || it == ite) {
				this->splice(it, x, it_x);
				it_x = x.begin();
				it--;
			}
			if (it_x == ite_x)
				break ;
			it++;
		}
	}
	template <class Compare>
	void	merge(List & x, Compare comp) {
		iterator	it = this->begin();
		iterator	ite = this->end();
		iterator	it_x = x.begin();
		iterator	ite_x = x.end();

		if (this == &x)
			return ;
		while (it != ite || it_x != ite_x) {
			if (comp(*it_x, *it) == true || it == ite) {
				this->splice(it, x, it_x);
				it_x = x.begin();
				it--;
			}
			if (it_x == ite_x)
				break ;
			it++;
		}
	}
	void	sort() {
		iterator	it;
		iterator	it_max;
		iterator	it_last = this->end();

		while (this->begin() != it_last) {
			it = this->begin();
			it_max = it;
			while (it != it_last) {
				if (*it_max < *it)
					it_max = it;
				it++;
			}
			if (it_max != --it)
				this->splice(it_last, *this, it_max);
			it_last--;
		}
	}
	template <class Compare>
	void	sort(Compare comp) {
		iterator	it;
		iterator	it_max;
		iterator	it_last = this->end();

		while (this->begin() != it_last) {
			it = this->begin();
			it_max = it;
			while (it != it_last) {
				if (comp(*it_max, *it) == true)
					it_max = it;
				it++;
			}
			if (it_max != --it)
				this->splice(it_last, *this, it_max);
			it_last--;
		}
	}
	void	reverse() {
		ListNode<T> *	temp;
		iterator		it_next =this->begin();
		iterator		ite = this->end();

		for (iterator it = it_next; it != ite; it = it_next) {
			it_next++;
			temp = it.node->next;
			it.node->next = it.node->prev;
			it.node->prev = temp;
		}
		temp = this->_last->next;
		this->_last->next = this->_last->prev;
		this->_last->prev = temp;
	}

private:
	ListNode<T> *													_last;
	allocator_type													_alloc;
	typename allocator_type::template rebind< ListNode<T> >::other	_node_alloc;

	ListNode<T> *	_createNode(value_type const & val) {
		ListNode<T> *	node = this->_node_alloc.allocate(1);

		this->_node_alloc.construct(node, ListNode<T>(val));
		return node;
	}
	void			_createLast() {
		this->_last = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_last, ListNode<T>());
		this->_last->prev = this->_last;
		this->_last->next = this->_last;
	}
	void			_deleteNode(ListNode<T> * node) {
		this->_node_alloc.destroy(node);
		this->_node_alloc.deallocate(node, 1);
	}
};

// Relational Operators
template <class T, class Alloc>
bool operator==(List<T, Alloc> const & lhs, List<T, Alloc> const & rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!=(List<T, Alloc> const & lhs, List<T, Alloc> const & rhs) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<(List<T, Alloc> const & lhs, List<T, Alloc> const & rhs) {
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator<=(List<T, Alloc> const & lhs, List<T, Alloc> const & rhs) {
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) ||
		equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator>(List<T, Alloc> const & lhs, List<T, Alloc> const & rhs) {
	return !(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) ||
			equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator>=(List<T, Alloc> const & lhs, List<T, Alloc> const & rhs) {
	return !lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

// Non Member Function Overloads
template <class T, class Alloc>
void swap (List<T, Alloc> & x, List<T, Alloc> & y) {
	List<T, Alloc>		temp(x);

	x = y;
	y = temp;
}

}

#endif
