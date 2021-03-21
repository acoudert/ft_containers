#ifndef MULTISET_HPP
# define MULTISET_HPP

# include <iostream>
# include "utils.hpp"
# include "iterator.hpp"

# define RED			0
# define BLACK			1

/*
 * Multiset
 * Implemented as Red-Black Tree
 * /usr/include/c++/9/bits/stl_multiset.h if using 42 VM
 * https://www.cplusplus.com/reference/multiset/
*/
namespace ft {

template <typename T>
struct	MultisetNode
{
	MultisetNode() : parent(NULL), right(NULL), left(NULL), color(RED), data(T()) {}
	MultisetNode(T * _data) : parent(NULL), right(NULL), left(NULL), color(RED), data(_data) {}
	MultisetNode(MultisetNode<T> const * _parent, MultisetNode<T> const * _right, MultisetNode<T> const * _left
			, bool const & _color, T * _data)
		: parent(_parent), right(_right), left(_left), color(_color), data(_data) {}
	MultisetNode(MultisetNode<T> const & src)
		: parent(src.parent), right(src.right), left(src.left)
		, color(src.color), data(src.data) {}
	MultisetNode<T> &	operator=(MultisetNode<T> const & x) {
		this->parent = x.parent;
		this->right = x.right;
		this->left = x.left;
		this->color = x.color;
		this->data = x.data;
	}
	virtual ~MultisetNode() {}

	MultisetNode<T> *	parent;
	MultisetNode<T> *	right;
	MultisetNode<T> *	left;
	bool			color;
	T *				data;
};

template <typename T>
struct  MultisetConstIterator : public iterator<bidirectional_iterator_tag, T>
{
        // Member Typedefs
        typedef T																	value_type;
        typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
        typedef T const *															pointer;
        typedef T const &															reference;
        typedef bidirectional_iterator_tag											iterator_category;

		// Member Attributes
        MultisetNode<T> *   node;
        MultisetNode<T> *   utils;

		// Canonic Class
		MultisetConstIterator() : node(NULL), utils(NULL) {}
		MultisetConstIterator(MultisetNode<T> * x, MultisetNode<T> * y) : node(x), utils(y) {
			if (this->node == NULL)
				this->node = this->utils;
		}
		MultisetConstIterator(MultisetConstIterator<T> const & x) : node(x.node), utils(x.utils) {}
		virtual ~MultisetConstIterator() {}
		MultisetConstIterator &	operator=(MultisetConstIterator<T> const & x) {
			this->node = x.node;
			this->utils = x.utils;
			return *this;
		}

		// Member Functions
		reference	operator*() const {
			return *this->node->data;
		}
		pointer		operator->() const {
			return this->node->data;
		}
		MultisetConstIterator<T> &	operator++() {
			MultisetNode<T> *	temp = NULL;

			if (this->node == this->utils && this->utils->parent != NULL) {
				this->node = this->utils->parent;
				return *this;
			}
			if (this->node->right) {
				this->node = this->node->right;
				while (this->node->left)
					this->node = this->node->left;
			}
			else {
				do {
					temp = this->node;
					this->node = this->node->parent;
				} while (this->node && temp == this->node->right);
			}
			if (this->node == NULL)
				this->node = this->utils;
			return *this;
		}
		MultisetConstIterator<T>		operator++(int) {
			MultisetConstIterator<T>	temp(this->node, this->utils);

			++(*this);
			return temp;
		}
		MultisetConstIterator<T> &	operator--() {
			MultisetNode<T> *	temp = NULL;

			if (this->node == this->utils && this->utils->parent != NULL) {
				this->node = this->utils->parent;
				return *this;
			}
			if (this->node->left) {
				this->node = this->node->left;
				while (this->node->right)
					this->node = this->node->right;
			}
			else {
				do {
					temp = this->node;
					this->node = this->node->parent;
				} while (this->node && temp == this->node->left);
			}
			if (this->node == NULL)
				this->node = this->utils;
			return *this;
		}
		MultisetConstIterator<T>		operator--(int) {
			MultisetConstIterator<T>	temp(this->node, this->utils);

			--(*this);
			return temp;
		}
		// Friend used to allow non binary operations
		inline friend bool  operator==(MultisetConstIterator<T> const & x, MultisetConstIterator<T> const & y) {
			return x.node == y.node;
		}
		inline friend bool  operator!=(MultisetConstIterator<T> const & x, MultisetConstIterator<T> const & y) {
			return x.node != y.node;
		}
};

template < class Key, class Compare = less<Key>
	, class Alloc = std::allocator<Key> >
class Multiset
{
public:
	// Member Typedefs
	typedef Key													key_type;
	typedef Key													value_type;
	typedef Compare												key_compare;
	typedef Compare												value_compare;
	typedef Alloc												allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
	typedef MultisetConstIterator<value_type>					iterator;
	typedef MultisetConstIterator<value_type>					const_iterator;
	typedef reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef size_t												size_type;

	// Canonic Class
	explicit Multiset(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
			: _root(NULL), _utils(NULL), _comp(comp), _alloc(alloc) {
		this->_utils = this->_createNode(value_type());
		this->_updateUtils();
	}
	template <class InputIterator>
	Multiset(InputIterator first, InputIterator last, const key_compare & comp = key_compare(),
			const allocator_type & alloc = allocator_type(),
			typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
			: _root(NULL), _utils(NULL), _comp(comp), _alloc(alloc) {
		this->_utils = this->_createNode(value_type());
		this->_updateUtils();
		this->insert(first, last);
	}
	Multiset(Multiset<value_type> const & x)
			: _root(NULL), _utils(NULL), _comp(x._comp), _alloc(x._alloc) {
		this->_utils = this->_createNode(value_type());
		this->_updateUtils();
		*this = x;
	}
	virtual ~Multiset() {
		this->clear();
		this->_deleteData(this->_utils->data);
		this->_deleteNode(this->_utils);
	}
	Multiset<value_type> &	operator=(Multiset<value_type> const & src) {
		this->clear();
		this->insert(src.begin(), src.end());
		return *this;
	}

	// Member Iterator Functions
	iterator	begin() {
		MultisetNode<value_type> *	cur = this->_root;

		while (cur && cur->left)
			cur = cur->left;
		return iterator(cur, this->_utils);
	}
	const_iterator	begin() const {
		MultisetNode<value_type> *	cur = this->_root;

		while (cur && cur->left)
			cur = cur->left;
		return const_iterator(cur, this->_utils);
	}
	iterator		end() {
		return iterator(this->_utils, this->_utils);
	}
	const_iterator		end() const {
		return const_iterator(this->_utils, this->_utils);
	}
	reverse_iterator	rbegin() {
		return reverse_iterator(iterator(this->_utils->parent, this->_utils));
	}
	const_reverse_iterator	rbegin() const {
		return const_reverse_terator(const_iterator(this->_utils->parent, this->_utils));
	}
	reverse_iterator		rend() {
		return reverse_iterator(iterator(this->_utils, this->_utils));
	}
	const_reverse_iterator		rend() const {
		return const_reverse_iterator(const_iterator(this->_utils, this->_utils));
	}

	// Member Capacity Functions
	bool		empty() const {
		return this->_root == NULL;
	}
	size_type	size() const {
		size_type	c(0);
		const_iterator	it = this->begin();

		while (it++ != this->end())
			c++;
		return c;
	}
	size_type	max_size() const {
		return this->_node_alloc.max_size();
	}

	// Member Modifier Functions
	iterator					insert(const value_type & val) {
		return this->_insertHelper(val).first;
	}
	iterator					insert(iterator position, const value_type & val) {
		iterator	ret = this->insert(val);

		(void)position;
		return ret;
	}
	template <class InputIterator>
	void						insert(InputIterator first, InputIterator last
			, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL) {
		while (first != last) {
			this->insert(*first);
			first++;
		}
	}
	void			erase(iterator position) {
		if (position.node != this->_utils) {
			this->_deleteData(position.node->data);
			position.node->data = NULL;
			this->_deleteHelper(position.node);
		}
	}
	size_type		erase(const key_type & k) {
		MultisetNode<value_type> *	node = NULL;
		size_type					n(0);

		while ((node = this->_getNode(k)) != NULL) {
			this->_deleteData(node->data);
			node->data = NULL;
			this->_deleteHelper(node);
			n++;
		}
		return n;
	}
	void			erase(iterator first, iterator last) {
		size_type	size = 0;
		iterator	it = first;

		while (it++ != last)
			size++;
		it = first;
		while (size) {
			first++;
			this->erase(it);
			it = first;
			size--;
		}
	}
	void	swap(Multiset<value_type> & x) {
		Multiset<value_type>		temp(*this);

		*this = x;
		x = temp;
	}
	void clear() {
		while (this->_root != NULL)
			this->erase(*this->_root->data);
	}

	// Member Observer Functions
	key_compare			key_comp() const {
		return key_compare();
	}
	key_compare			value_comp() const {
		return key_compare();
	}

	// Member Operations
	iterator	find(const key_type & k) const {
		MultisetNode<value_type> *   node = this->_getNode(k);

		if (node == NULL)
			return this->end();
		return iterator(node, this->_utils);
	}
	size_type	count(const key_type & k) const {
		size_type	n(0);
		iterator	it = this->begin();

		while (it != this->end()) {
			if (this->_comp(*it.node->data, k) == 0 && this->_comp(k, *it.node->data) == 0)
				n++;
			it++;
		}
		return n;
	}
	iterator		lower_bound(const key_type & k) const {
		iterator	it = this->begin();

		while (it != this->end()) {
			if (this->_comp(*it.node->data, k) == 0)
				return it;
			it++;
		}
		return it;
	}
	iterator		upper_bound(const key_type & k) const {
		iterator	it = this->begin();

		while (it != this->end()) {
			if (this->_comp(k, *it.node->data) == 1)
				return it;
			it++;
		}
		return it;
	}
	pair<iterator, iterator> equal_range(const key_type & k) const {
		pair<iterator, iterator>	ret;

		ret.first = this->lower_bound(k);
		ret.second = this->upper_bound(k);
		return ret;
	}
/*
	// Printers
	void	_print() const {
		this->_printTree(this->_root, 0);
		std::cout << "| ";
		this->_printInOrder(this->_root);
		std::cout << std::endl << "-----" << std::endl;
	}
*/
private:
	MultisetNode<value_type> *														_root;
	MultisetNode<value_type> *														_utils;
	key_compare																	_comp;
	allocator_type																_alloc;
	typename allocator_type::template rebind< MultisetNode<value_type> >::other		_node_alloc;

	// Node Constructor/Destructor + _utils update
	MultisetNode<value_type> *	_createNode(value_type const & val) {
		MultisetNode<value_type> *	node = this->_node_alloc.allocate(1);
		value_type *				da = this->_alloc.allocate(1);

		this->_alloc.construct(da, val);
		this->_node_alloc.construct(node, MultisetNode<value_type>(da));
		return node;
	}
	void					_deleteNode(MultisetNode<value_type> * node) {
		this->_node_alloc.destroy(node);
		this->_node_alloc.deallocate(node, 1);
	}
	void					_deleteData(value_type * da) {
		this->_alloc.destroy(da);
		this->_alloc.deallocate(da, 1);
	}
	void	_updateUtils() {
		MultisetNode<value_type> *	cur = this->_root;

		if (this->_utils == NULL)
			return ;
		while (cur && cur->right)
			cur = cur->right;
		this->_utils->parent = cur;
	}

	// Getters/Multisetters
	MultisetNode<value_type> *	_getNode(value_type const & val) const {
		MultisetNode<value_type> *	node = this->_root;
		bool					comparison;

		while (node) {
			comparison = this->_comp(val, *node->data);
			if (comparison == 0 && this->_comp(*node->data, val) == 0)
				return node;
			else if (comparison == 1)
				node = node->left;
			else
				node = node->right;
		}
		return node;
	}
	bool	_getColor(MultisetNode<value_type> * node) {
		if (node == NULL)
			return BLACK;
		return node->color;
	}

	// Rotations
	void	_rotateLeft(MultisetNode<value_type> * x) {
		MultisetNode<value_type> *   y = x->right;

		if (x->parent == NULL && y)
			this->_root = y;
		else if (y == NULL)
			return ;
		else {
			if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
		}
		if (y && x) {
			y->parent = x->parent;
			x->right = y->left;
		}
		if (y && y->left)
			y->left->parent = x;
		if (y)
			y->left = x;
		if (x)
			x->parent = y;
	}
	void	_rotateRight(MultisetNode<value_type> * x) {
		MultisetNode<value_type> *   y = x->left;

		if (x->parent == NULL && y)
			this->_root = y;
		else if (y == NULL)
			return ;
		else {
			if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
		}
		if (y && x) {
			y->parent = x->parent;
			x->left = y->right;
		}
		if (y && y->right)
			y->right->parent = x;
		if (y)
			y->right = x;
		if (x)
			x->parent = y;
	}
	
	// Insertion
	pair<iterator, bool>	_insertHelper(value_type const & val) {
		bool					comparison;
		MultisetNode<value_type> *	node = this->_createNode(val);
		MultisetNode<value_type> *	x = this->_root;
		MultisetNode<value_type> *	y = NULL;

		while (x != NULL) {
			y = x; // y is last node before NULL
			comparison = this->_comp(val, *x->data);
			if (comparison == true)
				x = x->left;
			else
				x = x->right;
		}
		node->parent = y;
		if (y == NULL) // Empty tree
			this->_root = node;
		else {
			comparison = this->_comp(val, *y->data);
			if (comparison == true)
				y->left = node;
			else
				y->right = node;
		}
		this->_fixInsert(node);
		return pair<iterator, bool>(iterator(node, this->_utils), true);
	}
	void				_fixInsert(MultisetNode<value_type> * node) {
		while (node->parent && node->parent->parent && this->_getColor(node->parent) == RED) {
			if (node->parent == node->parent->parent->left) { // Left subtree
				MultisetNode<value_type> *   y = node->parent->parent->right;
				if (this->_getColor(y) == RED) {
					node->parent->color = BLACK;
					y->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}
				else {
					if (node == node->parent->right) {
						node = node->parent;
						this->_rotateLeft(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					if (node->parent->right)
						node->parent->right->color = BLACK;
					this->_rotateRight(node->parent->parent);
				}
			}
			else { // Right subtree
				MultisetNode<value_type> *   y = node->parent->parent->left;
				if (this->_getColor(y) == RED) {
					node->parent->color = BLACK;
					y->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}
				else {
					if (node == node->parent->left) {
						node = node->parent;
						this->_rotateRight(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					if (node->parent->left)
						node->parent->left->color = BLACK;
					this->_rotateLeft(node->parent->parent);
				}
			}
		}
		this->_root->color = BLACK;
		this->_updateUtils();
	}
	
	// Deletion
	size_type				_deleteHelper(MultisetNode<value_type> * node) {
		MultisetNode<value_type> *	x = NULL;
		MultisetNode<value_type> *	y = NULL;

		if (node == NULL)
			return 0;
		if (node->left == NULL || node->right == NULL)
			y = node;
		else
			y = this->_successor(node);
		if (y->left != NULL)
			x = y->left;
		else
			x = y->right;
		if (x)
			x->parent = y->parent;
		if (y->parent == NULL)
			this->_root = x;
		else {
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		}
		if (node != y) {
			node->data = y->data;
		}
		if (x && y->color == BLACK)
			this->_fixDelete(x);
		this->_deleteNode(y);
		if (this->_root)
			this->_fixRoot();
		this->_updateUtils();
		return 1;
	}
	void					_fixDelete(MultisetNode<value_type> * node) {
		MultisetNode<value_type> *	w = NULL;

		while (node && node->parent && node != this->_root && this->_getColor(node) == BLACK) {
			w = NULL;
			if (node->parent->left == node) {
				w = node->parent->right;
				if (this->_getColor(w) == RED) {
					w->color = BLACK;
					node->parent->color = RED;
					this->_rotateLeft(node->parent);
					w = node->parent->right;
				}
				if (w && this->_getColor(w->left) == BLACK && this->_getColor(w->right) == BLACK) {
					w->color = RED;
					node = node->parent;
				}
				else {
					if (w && this->_getColor(w->right) == BLACK) {
						if (w->left)
							w->left->color = BLACK;
						if (w) {
							w->color = RED;
							this->_rotateRight(w);
						}
						w = node->parent->right;
					}
					if (w)
						w->color = node->parent->color;
					node->parent->color = BLACK;
					if (w && w->right)
						w->right->color = BLACK;
					this->_rotateLeft(node->parent);
					node = this->_root;
				}
			}
			else {
				w = node->parent->left;
				if (this->_getColor(w) == RED) {
					if (w)
						w->color = BLACK;
					node->parent->color = RED;
					this->_rotateRight(node->parent);
					w = node->parent->left;
				}
				if (w && this->_getColor(w->right) == BLACK && this->_getColor(w->left) == BLACK) {
					w->color = RED;
					node = node->parent;
				}
				else {
					if (w && this->_getColor(w->left) == BLACK) {
						if (w && w->right)
							w->right->color = BLACK;
						if (w) {
							w->color = RED;
							this->_rotateLeft(w);
						}
						w = node->parent->left;
					}
					if (w)
						w->color = this->_getColor(node->parent);
					if (node->parent)
						node->parent->color = BLACK;
					if (w && w->left)
						w->left->color = BLACK;
					this->_rotateRight(node->parent);
					node = this->_root;
				}
			}
		}
		if (node)
			node->color = BLACK;
	}
	MultisetNode<value_type> *	_successor(MultisetNode<value_type> * node) {
		MultisetNode<value_type> *	x = NULL;

		if (node->right != NULL) {
			while (node->left != NULL)
				node = node->left;
			return node;
		}
		x = node->parent;
		while (x != NULL && node == x->right) {
			node = x;
			x = x->parent;
		}
		return x;
	}
	void					_fixRoot() {
		MultisetNode<value_type> *	max = this->_root;
		MultisetNode<value_type> *	temp = this->_root;
		MultisetNode<value_type> *	left = NULL;
		int							cl(0);
		int							cr(0);

		for (iterator it(this->begin()); it != iterator(this->_root, this->_utils); it++) {
			if (this->_comp(*max->data, *it.node->data) == true
					&& this->_comp(*it.node->data, *max->data) == false)
				max = it.node;
			else if (this->_comp(*max->data, *it.node->data) == false
					&& this->_comp(*it.node->data, *max->data) == false)
				max = it.node;
		}
		if (max == this->_root || *max->data == *this->_root->data)
			return;
		if (max->parent->right == max)
			max->parent->right = NULL;
		else
			max->parent->left = NULL;
		max->parent = NULL;
		max->right = this->_root->right;
		if (this->_root->left != max)
			max->left = this->_root->left;
		else
			max->left = 0;
		max->color = this->_root->color;
		if (max->right)
			max->right->parent = max;
		if (max->left)
			max->left->parent = max;
		temp = this->_root;
		this->_root = max;
		temp->left = NULL;
		temp->right = NULL;
		left = this->_root;
		while (left->left)
			left = left->left;
		left->left = temp;
		temp->parent = left;
		temp = this->_root;
		while (temp) {
			if (temp->color == BLACK)
				cl++;
			temp = temp->left;
		}
		temp = this->_root;
		while (temp) {
			if (temp->color == BLACK)
				cl++;
			temp = temp->right;
		}
		if (cr > cl)
			left->left->color = BLACK;
		else
			left->left->color = RED;
	}

	// Printer/Helper
	void	_printTree(MultisetNode<value_type> * node, int indent) const {
		int		i;

		if (node == NULL) {
			std::cout << "Empty" << std::endl;
			return ;
		}
		if (node->right != NULL)
			this->_printTree(node->right, indent + 4);
		for (i = 0; i < indent; i++) {
			std::cout << " ";
		}
		if (node->color == BLACK)
			std::cout << "'" << node << "' " << *node->data << std::endl;
		else
			std::cout << "<" << node << "> " << *node->data << std::endl;
		if (node->left != NULL)
			this->_printTree(node->left, indent + 4);
	}
	void	_printInOrder(MultisetNode<value_type> * node) const {
		if (node == NULL)
			return ;
		this->_printInOrder(node->left);
		std::cout << *node->data << " | ";
		this->_printInOrder(node->right);
	}
};

}

#endif
