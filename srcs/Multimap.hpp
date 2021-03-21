#ifndef MULTIMAP_HPP
# define MULTIMAP_HPP

# include <iostream>
# include "utils.hpp"
# include "iterator.hpp"

# define RED			0
# define BLACK			1

/*
 * Multimap
 * Implemented as Red-Black Tree
 * /usr/include/c++/9/bits/stl_multimap.h if using 42 VM
 * https://www.cplusplus.com/reference/multimap/
*/
namespace ft {

template <typename T>
struct	MultimapNode
{
	MultimapNode() : parent(NULL), right(NULL), left(NULL), color(RED), data(T()) {}
	MultimapNode(T * _data) : parent(NULL), right(NULL), left(NULL), color(RED), data(_data) {}
	MultimapNode(MultimapNode<T> const * _parent, MultimapNode<T> const * _right, MultimapNode<T> const * _left
			, bool const & _color, T * _data)
		: parent(_parent), right(_right), left(_left), color(_color), data(_data) {}
	MultimapNode(MultimapNode<T> const & src)
		: parent(src.parent), right(src.right), left(src.left)
		, color(src.color), data(src.data) {}
	MultimapNode<T> &	operator=(MultimapNode<T> const & x) {
		this->parent = x.parent;
		this->right = x.right;
		this->left = x.left;
		this->color = x.color;
		this->data = x.data;
	}
	virtual ~MultimapNode() {}

	MultimapNode<T> *	parent;
	MultimapNode<T> *	right;
	MultimapNode<T> *	left;
	bool			color;
	T *				data;
};

template <typename T>
struct  MultimapIterator : public iterator<bidirectional_iterator_tag, T>
{
        // Member Typedefs
        typedef T																	value_type;
        typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
        typedef T *																	pointer;
        typedef T &																	reference;
        typedef bidirectional_iterator_tag											iterator_category;

		// Member Attributes
        MultimapNode<T> *   node;
        MultimapNode<T> *   utils;

		// Canonic Class
		MultimapIterator() : node(NULL), utils(NULL) {}
		MultimapIterator(MultimapNode<T> * x, MultimapNode<T> * y) : node(x), utils(y) {
			if (this->node == NULL)
				this->node = this->utils;
		}
		MultimapIterator(MultimapIterator<T> const & x) : node(x.node), utils(x.utils) {}
		virtual ~MultimapIterator() {}
		MultimapIterator &	operator=(MultimapIterator<T> const & x) {
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
		MultimapIterator<T> &	operator++() {
			MultimapNode<T> *	temp = NULL;

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
		MultimapIterator<T>		operator++(int) {
			MultimapIterator<T>	temp(this->node, this->utils);

			++(*this);
			return temp;
		}
		MultimapIterator<T> &	operator--() {
			MultimapNode<T> *	temp = NULL;

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
		MultimapIterator<T>		operator--(int) {
			MultimapIterator<T>	temp(this->node, this->utils);

			--(*this);
			return temp;
		}
		// Friend used to allow non binary operations
		inline friend bool  operator==(MultimapIterator<T> const & x, MultimapIterator<T> const & y) {
			return x.node == y.node;
		}
		inline friend bool  operator!=(MultimapIterator<T> const & x, MultimapIterator<T> const & y) {
			return x.node != y.node;
		}
};

template <typename T>
struct  MultimapConstIterator : public iterator<bidirectional_iterator_tag, T>
{
        // Member Typedefs
        typedef T																	value_type;
        typedef typename iterator<bidirectional_iterator_tag, T>::difference_type	difference_type;
        typedef T const *															pointer;
        typedef T const &															reference;
        typedef bidirectional_iterator_tag											iterator_category;

		// Member Attributes
        MultimapNode<T> *   node;
        MultimapNode<T> *   utils;

		// Canonic Class
		MultimapConstIterator() : node(NULL), utils(NULL) {}
		MultimapConstIterator(MultimapNode<T> * x, MultimapNode<T> * y) : node(x), utils(y) {
			if (this->node == NULL)
				this->node = this->utils;
		}
		MultimapConstIterator(MultimapIterator<T> const & x) : node(x.node), utils(x.utils) {}
		MultimapConstIterator(MultimapConstIterator<T> const & x) : node(x.node), utils(x.utils) {}
		virtual ~MultimapConstIterator() {}
		MultimapConstIterator &	operator=(MultimapConstIterator<T> const & x) {
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
		MultimapConstIterator<T> &	operator++() {
			MultimapNode<T> *	temp = NULL;

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
		MultimapConstIterator<T>		operator++(int) {
			MultimapConstIterator<T>	temp(this->node, this->utils);

			++(*this);
			return temp;
		}
		MultimapConstIterator<T> &	operator--() {
			MultimapNode<T> *	temp = NULL;

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
		MultimapConstIterator<T>		operator--(int) {
			MultimapConstIterator<T>	temp(this->node, this->utils);

			--(*this);
			return temp;
		}
		// Friend used to allow non binary operations
		inline friend bool  operator==(MultimapConstIterator<T> const & x, MultimapConstIterator<T> const & y) {
			return x.node == y.node;
		}
		inline friend bool  operator!=(MultimapConstIterator<T> const & x, MultimapConstIterator<T> const & y) {
			return x.node != y.node;
		}
};

template < class Key, class T,  class Compare = less<Key>
	, class Alloc = std::allocator<pair<const Key, T> > >
class Multimap
{
public:
	// Member Typedefs
	typedef Key													key_type;
	typedef T													mapped_type;
	typedef pair<const key_type, mapped_type>					value_type;
	typedef Compare												key_compare;
	class value_compare : public binary_function<value_type, value_type, bool>
	{
	friend class Multimap;

	protected:
		Compare	    comp;
		value_compare(Compare c) : comp(c) {};

	public:
		typedef bool            result_type;
		typedef value_type      first_argument_type;
		typedef value_type      second_argument_type;

		bool operator()(const value_type & x, const value_type & y) const {
			return comp(x.first, y.first);
		}
	};
	typedef Alloc												allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
	typedef MultimapConstIterator<value_type>					iterator;
	typedef MultimapConstIterator<value_type>					const_iterator;
	typedef reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef size_t												size_type;

	// Canonic Class
	explicit Multimap(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
			: _root(NULL), _utils(NULL), _comp(comp), _alloc(alloc) {
		this->_utils = this->_createNode(value_type());
		this->_updateUtils();
	}
	template <class InputIterator>
	Multimap(InputIterator first, InputIterator last, const key_compare & comp = key_compare(),
			const allocator_type & alloc = allocator_type(),
			typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
			: _root(NULL), _utils(NULL), _comp(comp), _alloc(alloc) {
		this->_utils = this->_createNode(value_type());
		this->_updateUtils();
		this->insert(first, last);
	}
	Multimap(Multimap<key_type, mapped_type> const & x)
			: _root(NULL), _utils(NULL), _comp(x._comp), _alloc(x._alloc) {
		this->_utils = this->_createNode(value_type());
		this->_updateUtils();
		*this = x;
	}
	virtual ~Multimap() {
		this->clear();
		this->_deletePair(this->_utils->data);
		this->_deleteNode(this->_utils);
	}
	Multimap<key_type, mapped_type> &	operator=(Multimap<key_type, mapped_type> const & src) {
		this->clear();
		this->insert(src.begin(), src.end());
		return *this;
	}

	// Member Iterator Functions
	iterator	begin() {
		MultimapNode<value_type> *	cur = this->_root;

		while (cur && cur->left)
			cur = cur->left;
		return iterator(cur, this->_utils);
	}
	const_iterator	begin() const {
		MultimapNode<value_type> *	cur = this->_root;

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
			this->_deletePair(position.node->data);
			position.node->data = NULL;
			this->_deleteHelper(position.node);
		}
	}
	size_type		erase(const key_type & k) {
		value_type					val(k, mapped_type());
		MultimapNode<value_type> *	node = NULL;
		size_type					n(0);

		while ((node = this->_getNode(val)) != NULL) {
			this->_deletePair(node->data);
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
	void	swap(Multimap<key_type, mapped_type> & x) {
		Multimap<key_type, mapped_type>		temp(*this);

		*this = x;
		x = temp;
	}
	void clear() {
		while (this->_root != NULL)
			this->erase(this->_root->data->first);
	}

	// Member Observer Functions
	key_compare			key_comp() const {
		return key_compare();
	}
	value_compare		value_comp() const {
		return this->_comp;
	}

	// Member Operations
	iterator		find(const key_type & k) {
		value_type					val(k, mapped_type());
		MultimapNode<value_type> *	node = this->_getNode(val);

		if (node == NULL)
			return this->end();
		return iterator(node, this->_utils);
	}
	const_iterator	find(const key_type & k) const {
		value_type					val(k, mapped_type());
		MultimapNode<value_type> *	node = this->_getNode(val);

		if (node == NULL)
			return this->end();
		return iterator(node, this->_utils);
	}
	size_type	count(const key_type & k) const {
		size_type	n(0);
		value_type  val(k, mapped_type());
		iterator	it = this->begin();

		while (it != this->end()) {
			if (this->_comp(*it.node->data, val) == 0 && this->_comp(val, *it.node->data) == 0)
				n++;
			it++;
		}
		return n;
	}
	iterator		lower_bound(const key_type & k) {
		iterator	it = this->begin();
		value_type  val(k, mapped_type());

		while (it != this->end()) {
			if (this->_comp(*it.node->data, val) == 0)
				return it;
			it++;
		}
		return it;
	}
	const_iterator	lower_bound(const key_type & k) const {
		const_iterator	it = this->begin();
		value_type		val(k, mapped_type());

		while (it != this->end()) {
			if (this->_comp(*it.node->data, val) == 0)
				return it;
			it++;
		}
		return it;
	}
	iterator		upper_bound(const key_type & k) {
		iterator		it = this->begin();
		value_type		val(k, mapped_type());

		while (it != this->end()) {
			if (this->_comp(val, *it.node->data) == 1)
				return it;
			it++;
		}
		return it;
	}
	const_iterator	upper_bound(const key_type & k) const {
		const_iterator	it = this->begin();
		value_type		val(k, mapped_type());

		while (it != this->end()) {
			if (this->_comp(val, *it.node->data) == 1)
				return it;
			it++;
		}
		return it;
	}
	pair<iterator, iterator> equal_range(const key_type & k) {
		pair<iterator, iterator>	ret;

		ret.first = this->lower_bound(k);
		ret.second = this->upper_bound(k);
		return ret;
	}
	pair<const_iterator, const_iterator> equal_range(const key_type & k) const {
		pair<const_iterator, const_iterator>	ret;

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
	MultimapNode<value_type> *														_root;
	MultimapNode<value_type> *														_utils;
	value_compare																	_comp;
	allocator_type																	_alloc;
	typename allocator_type::template rebind< value_type >::other					_pair_alloc;
	typename allocator_type::template rebind< MultimapNode<value_type> >::other		_node_alloc;

	// Node Constructor/Destructor + _utils update
	MultimapNode<value_type> *	_createNode(value_type const & val) {
		MultimapNode<value_type> *	node = this->_node_alloc.allocate(1);
		value_type *				pa = this->_pair_alloc.allocate(1);

		this->_pair_alloc.construct(pa, value_type(val));
		this->_node_alloc.construct(node, MultimapNode<value_type>(pa));
		return node;
	}
	void					_deleteNode(MultimapNode<value_type> * node) {
		this->_node_alloc.destroy(node);
		this->_node_alloc.deallocate(node, 1);
	}
	void					_deletePair(value_type * pa) {
		this->_pair_alloc.destroy(pa);
		this->_pair_alloc.deallocate(pa, 1);
	}
	void	_updateUtils() {
		MultimapNode<value_type> *	cur = this->_root;

		if (this->_utils == NULL)
			return ;
		while (cur && cur->right)
			cur = cur->right;
		this->_utils->parent = cur;
	}

	// Getters/Multimapters
	MultimapNode<value_type> *	_getNode(value_type const & val) const {
		MultimapNode<value_type> *	node = this->_root;
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
	bool	_getColor(MultimapNode<value_type> * node) {
		if (node == NULL)
			return BLACK;
		return node->color;
	}

	// Rotations
	void	_rotateLeft(MultimapNode<value_type> * x) {
		MultimapNode<value_type> *   y = x->right;

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
	void	_rotateRight(MultimapNode<value_type> * x) {
		MultimapNode<value_type> *   y = x->left;

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
		MultimapNode<value_type> *	node = this->_createNode(val);
		MultimapNode<value_type> *	x = this->_root;
		MultimapNode<value_type> *	y = NULL;

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
	void				_fixInsert(MultimapNode<value_type> * node) {
		while (node->parent && node->parent->parent && this->_getColor(node->parent) == RED) {
			if (node->parent == node->parent->parent->left) { // Left subtree
				MultimapNode<value_type> *   y = node->parent->parent->right;
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
				MultimapNode<value_type> *   y = node->parent->parent->left;
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
	size_type				_deleteHelper(MultimapNode<value_type> * node) {
		MultimapNode<value_type> *	x = NULL;
		MultimapNode<value_type> *	y = NULL;

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
	void					_fixDelete(MultimapNode<value_type> * node) {
		MultimapNode<value_type> *	w = NULL;

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
	MultimapNode<value_type> *	_successor(MultimapNode<value_type> * node) {
		MultimapNode<value_type> *	x = NULL;

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
		MultimapNode<value_type> *	max = this->_root;
		MultimapNode<value_type> *	temp = this->_root;
		MultimapNode<value_type> *	left = NULL;
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
	void	_printTree(MultimapNode<value_type> * node, int indent) const {
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
			std::cout << "'" << node->data->first << "'" << std::endl;
		else
			std::cout << "<" << node->data->first << ">" << std::endl;
		if (node->left != NULL)
			this->_printTree(node->left, indent + 4);
	}
	void	_printInOrder(MultimapNode<value_type> * node) const {
		if (node == NULL)
			return ;
		this->_printInOrder(node->left);
		std::cout << "[" << node->data->first << "] " << node->data->second << " | ";
		this->_printInOrder(node->right);
	}
};

}

#endif
