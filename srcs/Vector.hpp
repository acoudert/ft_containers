#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdexcept>
# include <cstdio>
# include <iostream>
# include "iterator.hpp"
# include "utils.hpp"

namespace ft {

/*
 * Vector Iterators/Data
 * /usr/include/c++/9/bits/stl_vector.h if using 42 VM
 * https://www.cplusplus.com/reference/list/
*/
template <typename T>
struct	VectorData
{
	VectorData() : start(NULL), end(NULL), end_storage(NULL) {}
	VectorData(T * const & _start, T * const & _end, T * const & _end_storage)
		: start(_start), end(_end), end_storage(_end_storage) {}
	VectorData(VectorData<T> const & src) { *this = src; }
	~VectorData() {}
	VectorData<T> &	operator=(VectorData<T> const & src) {
		this->start = src.start;
		this->end = src.end;
		this->end_storage = src.end_storage;
		return *this;
	}

	T *		start;
	T *		end;
	T *		end_storage;
};

template <typename T>
struct	VectorIterator : public iterator<random_access_iterator_tag, T>
{
	// Member Typedefs
	typedef T																	value_type;
	typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
	typedef T *																	pointer;
	typedef T &																	reference;
	typedef random_access_iterator_tag											iterator_category;

	// Member Attributes
	pointer		data;

	// Canonic Class
	VectorIterator() : data(NULL) {}
	VectorIterator(pointer x) : data(x) {}
	VectorIterator(VectorIterator<T> const & x) : data(x.data) {}
	virtual ~VectorIterator() {}
	VectorIterator &	operator=(VectorIterator<T> const & x) {
		this->data = x.data;
		return *this;
	}

	// Member Functions
	reference	operator*() const {
		return *(this->data);
	}
	pointer		operator->() const {
		return this->data;
	}
	VectorIterator<T> &		operator++() {
		this->data += 1;
		return (*this);
	}
	VectorIterator<T>		operator++(int) {
		VectorIterator<T>		temp = *this;

		this->data += 1;
		return (temp);
	}
	VectorIterator<T> &		operator--() {
		this->data -= 1;
		return (*this);
	}
	VectorIterator<T>		operator--(int) {
		VectorIterator<T>		temp = *this;

		this->data -= 1;
		return (temp);
	}
	VectorIterator<T>	operator+(difference_type n) {
		return VectorIterator<T>(this->data + n);
	}
	// Friend used to allow non binary operations
	inline friend VectorIterator<T>	operator+(difference_type n
			, VectorIterator<T> const & x) {
		return VectorIterator<T>(x.data + n);
	}
	VectorIterator<T>	operator-(difference_type const & n) {
		return VectorIterator<T>(this->data - n);
	}
	difference_type		operator-(VectorIterator<T> const & x) {
		return this->data - x.data;
	}
	bool	operator<(VectorIterator<T> const & x) const {
		return this->data < x.data;
	}
	bool	operator>(VectorIterator<T> const & x) const {
		return this->data > x.data;
	}
	bool	operator<=(VectorIterator<T> const & x) const {
		return this->data <= x.data;
	}
	bool	operator>=(VectorIterator<T> const & x) const {
		return this->data >= x.data;
	}
	VectorIterator<T>	operator+=(difference_type const & n) {
		this->data += n;
		return *this;
	}
	VectorIterator<T>	operator-=(difference_type const & n) {
		this->data -= n;
		return *this;
	}
	reference	operator[](difference_type const & n) {
		return *(this->data + n);
	}
	// Non Members Functions Overloads
	// Friend used to allow non binary operations
	inline friend bool	operator==(VectorIterator<T> const & x
			, VectorIterator<T> const & y) {
		return x.data == y.data;
	}
	inline friend bool	operator!=(VectorIterator<T> const & x
			, VectorIterator<T> const & y) {
		return x.data != y.data;
	}
};

template <typename T>
struct	VectorConstIterator : public iterator<random_access_iterator_tag, T>
{
	// Member Typedefs
	typedef T																	value_type;
	typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
	typedef T const *															pointer;
	typedef T const &															reference;
	typedef random_access_iterator_tag											iterator_category;

	// Member Attributes
	pointer		data;

	// Canonic Class
	VectorConstIterator() : data(NULL) {}
	VectorConstIterator(pointer x) : data(x) {}
	VectorConstIterator(VectorIterator<T> const & x) : data(x.data) {}
	VectorConstIterator(VectorConstIterator<T> const & x) : data(x.data) {}
	virtual ~VectorConstIterator() {}
	VectorConstIterator &	operator=(VectorConstIterator<T> const & x) {
		this->data = x.data;
		return *this;
	}

	// Member Functions
	reference	operator*() const {
		return *(this->data);
	}
	pointer		operator->() const {
		return this->data;
	}
	VectorConstIterator<T> &		operator++() {
		this->data += 1;
		return (*this);
	}
	VectorConstIterator<T>		operator++(int) {
		VectorIterator<T>		temp = *this;

		this->data += 1;
		return (temp);
	}
	VectorConstIterator<T> &		operator--() {
		this->data -= 1;
		return (*this);
	}
	VectorConstIterator<T>		operator--(int) {
		VectorConstIterator<T>		temp = *this;

		this->data -= 1;
		return (temp);
	}
	VectorConstIterator<T>	operator+(difference_type n) {
		return VectorConstIterator<T>(this->data + n);
	}
	// Friend used to allow non binary operations
	inline friend VectorConstIterator<T>	operator+(difference_type n
			, VectorConstIterator<T> const & x) {
		return VectorConstIterator<T>(x.data + n);
	}
	VectorConstIterator<T>	operator-(difference_type const & n) {
		return VectorConstIterator<T>(this->data - n);
	}
	VectorConstIterator<T>	operator-(VectorConstIterator<T> const & x) {
		return VectorConstIterator<T>(this->data - x.data);
	}
	bool	operator<(VectorConstIterator<T> const & x) const {
		return this->data < x.data;
	}
	bool	operator>(VectorConstIterator<T> const & x) const {
		return this->data > x.data;
	}
	bool	operator<=(VectorConstIterator<T> const & x) const {
		return this->data <= x.data;
	}
	bool	operator>=(VectorConstIterator<T> const & x) const {
		return this->data >= x.data;
	}
	VectorConstIterator<T>	operator+=(difference_type const & n) {
		this->data += n;
		return *this;
	}
	VectorConstIterator<T>	operator-=(difference_type const & n) {
		this->data -= n;
		return *this;
	}
	reference	operator[](difference_type const & n) {
		return *(this->data + n);
	}
	// Friend used to allow non binary operations
	inline friend bool	operator==(VectorConstIterator<T> const & x
			, VectorConstIterator<T> const & y) {
		return x.data == y.data;
	}
	inline friend bool	operator!=(VectorConstIterator<T> const & x
			, VectorConstIterator<T> const & y) {
		return x.data != y.data;
	}
};

/*
 * Vector Class
 * /usr/include/c++/9/bits/stl_vector.h if using 42 VM
 * https://www.cplusplus.com/reference/vector/
*/
template < class T, class Alloc = std::allocator<T> >
class Vector : public VectorData<T>
{
public:
	// Member Typedefs
	typedef T													value_type;
	typedef Alloc												allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
	typedef VectorIterator<T>									iterator;
	typedef VectorConstIterator<T>								const_iterator;
	typedef reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef size_t												size_type;

	// Canonic Class
	explicit Vector(const allocator_type & alloc = allocator_type())
			: _data(VectorData<T>()), _alloc(alloc) {}
	explicit Vector(size_type n, const value_type & val = value_type(),
                 const allocator_type & alloc = allocator_type())
			: _data(VectorData<T>()), _alloc(alloc) {
		this->_data = this->_createAlloc(n);
		this->_data.end = this->_data.start + n;
		for (size_type i = 0; i < n; i++) {
			*(this->_data.start + i) = val;
		}
	}
	template <class InputIterator>
	Vector(InputIterator first, InputIterator last,
			const allocator_type & alloc = allocator_type()
			, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
				: _alloc(alloc) {
		size_type		n = &(*last) - &(*first);

		this->_data = this->_createAlloc(n);
		this->_data.end = this->_data.start + n;
		n = 0;
		while (first != last) {
			*(this->_data.start + n) = *first;
			first++;
			n++;
		}
	}
	Vector(Vector<T> const & x) { *this = x; }
	virtual ~Vector() {
		this->_destroyAlloc(this->_data);
	}
	Vector<T> &	operator=(Vector<T> const & src) {
		this->_destroyAlloc(this->_data);
		this->_data = this->_createAlloc(src.size());
		this->_copyAlloc(src._data);
		return *this;
	}
	// Member Iterator Functions
	iterator			begin() { return iterator(this->_data.start); }
	const_iterator		begin() const { return const_iterator(this->_data.start); }
	iterator			end() { return iterator(this->_data.end); }
	const_iterator		end() const { return const_iterator(this->_data.end); }
	reverse_iterator		rbegin() {
		if (this->empty())
			return reverse_iterator(this->_data.start);
		return reverse_iterator(this->_data.end - 1);
	}
	const_reverse_iterator	rbegin() const {
		if (this->empty())
			return const_reverse_iterator(this->_data.start);
		return const_reverse_iterator(this->_data.end - 1);
	}
	reverse_iterator		rend() {
		if (this->empty())
			return reverse_iterator(this->_data.start);
		return reverse_iterator(this->_data.start - 1);
	}
	const_reverse_iterator	rend() const {
		if (this->empty())
			return const_reverse_iterator(this->_data.start);
		return const_reverse_iterator(this->_data.start - 1);
	}

	// Member Capacity Functions
	size_type	size() const { return this->_data.end - this->_data.start; }
	size_type	max_size() const { return this->_alloc.max_size(); }
	void		resize(size_type n, value_type val = value_type()) {
		VectorData<T>	temp = this->_data;

		if (n < this->size()) {
			for (size_type i = n; i < this->capacity(); i++) {
				this->_alloc.destroy(this->_data.start + i);
			}
			this->_data.end = this->_data.start + n;
		}
		else if (n < this->capacity()) {
			for (size_type i = this->size(); i < n; i++) {
				this->insert(this->end(), val);
			}
		}
		else {
			this->_reAlloc(n);
			for (size_type i = this->size(); i < n; i++) {
				this->insert(this->end(), val);
			}
		}
	}
	size_type	capacity() const { return this->_data.end_storage - this->_data.start; }
	bool		empty() const { return this->_data.end == this->_data.start; }
	void reserve (size_type n) {
		VectorData<T>	temp = this->_data;

		if (n < this->capacity())
			return;
		this->_data = this->_createAlloc(n);
		this->_copyAlloc(temp);
		this->_destroyAlloc(temp);
	}

	// Member Element Access Functions
	reference			operator[](size_type n) {
		return *(this->_data.start + n);
	}
	const_reference		operator[](size_type n) const {
		return *(this->_data.start + n);
	}
	reference			at(size_type n) {
		if (n >= this->size())
			throw std::out_of_range(this->_errorStr(n));
		return *(this->_data.start + n);
	}
	const_reference		at(size_type n) const {
		if (n >= this->size())
			throw std::out_of_range(this->_errorStr(n));
		return *(this->_data.start + n);
	}
	reference			front() {
		return *(this->_data.start);
	}
	const_reference		front() const {
		return *(this->_data.start);
	}
	reference			back() {
		return *(this->_data.end - 1);
	}
	const_reference		back() const {
		return *(this->_data.end - 1);
	}

	// Member Modifier Functions
	template <class InputIterator>
	void		assign(InputIterator first, InputIterator last
			, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL) {
		for (size_type i = 0; i < this->capacity(); i++) {
			this->_alloc.destroy(this->_data.start + i);
		}
		this->_data.end = this->_data.start;
		this->reserve(static_cast<unsigned>(&(*last) - &(*first)));
		while (first != last) {
			this->insert(this->end(), *first);
			first++;
		}
	}
	void		assign(size_type n, const value_type& val) {
		for (size_type i = 0; i < this->capacity(); i++) {
			this->_alloc.destroy(this->_data.start + i);
		}
		this->_data.end = this->_data.start;
		this->reserve(n);
		while (n > 0) {
			this->insert(this->end(), val);
			n--;
		}
	}
	void push_back (const value_type & val) {
		this->insert(this->end(), val);
	}
	void	pop_back() {
		this->_data.end -= 1;
		this->_alloc.destroy(this->_data.end);
	}
	iterator	insert(iterator position, const value_type & val) {
		size_type	i = &(*position) - this->_data.start;

		this->_reAlloc(this->size() + 1);
		position = this->begin();
		for (size_type j = 0; j < i; j++) {
			position++;
		}
		this->_shiftRight(position, val);
		return (position);
	}
	void	insert(iterator position, size_type n, const value_type & val) {
		size_type	i = &(*position) - this->_data.start;

		this->_reAlloc(this->size() + n);
		position = this->begin();
		for (size_type j = 0; j < i; j++) {
			position++;
		}
		while (n > 0) {
			this->_shiftRight(position, val);
			n--;
		}
	}
	template <class InputIterator>
    void	insert(iterator position, InputIterator first, InputIterator last
			, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL) {
		size_type		i = &(*position) - this->_data.start;
		InputIterator	temp = first;
		size_type		n = 0;

		while (temp++ != last)
			n++;
		this->_reAlloc(this->size() + n);
		position = this->begin();
		for (size_type j = 0; j < i; j++) {
			position++;
		}
		while (first != last) {
			this->_shiftRight(position, *first);
			first++;
		}
	}
	iterator	erase(iterator position) {
		this->_shiftLeft(position);
		return position;
	}
	iterator	erase(iterator first, iterator last) {
		while (first != last) {
			this->_shiftLeft(first);
			last--;
		}
		return first;
	}
	void	swap(Vector & x) {
		VectorData<T>	swap(x._data);

		x._data = this->_data;
		this->_data = swap;
	}
	void	clear() {
		for (T * cur = this->_data.start; cur != this->_data.end_storage; cur++) {
			this->_alloc.destroy(cur);
		}
		this->_data.end = this->_data.start;
	}

private:
	VectorData<T> 			_data;
	allocator_type			_alloc;

	VectorData<T>	_createAlloc(size_type const & n) {
		T *				array = this->_alloc.allocate(n);

		for (size_type i = 0; i < n; i++) {
			this->_alloc.construct(array + i, T());
		}
		VectorData<T>	created(array, array, array + n);
		return created;
	}
	void			_destroyAlloc(VectorData<T> x) {
		size_type	n = x.end_storage - x.start;

		for (size_type i = 0; i < n; i++) {
			this->_alloc.destroy(x.start + i);
		}
		this->_alloc.deallocate(x.start, x.end_storage - x.start);
	}
	void			_copyAlloc(VectorData<T> const & x) {
		T *			data = x.start;
		size_type	n = x.end - x.start;
		
		for (size_type i = 0; i < n; i++) {
			*(this->_data.start + i) = *(data + i);
		}
		this->_data.end = this->_data.start + n;
	}
	void		_reAlloc(size_type const & n) {
		VectorData<T>	temp = this->_data;

		if (n <= this->capacity())
			return ;
		else if (n <= this->size() * 2)
			this->_data = this->_createAlloc(this->size() * 2);
		else
			this->_data = this->_createAlloc(n);
		this->_copyAlloc(temp);
		this->_destroyAlloc(temp);
		
	}
	void		_shiftRight(iterator position, value_type val) {
		value_type	val_cur = val;
		value_type	val_next;

		this->_data.end += 1;
		while (position != this->end()) {
			val_next = *position;
			*position = val_cur;
			val_cur = val_next;
			position++;
		}
	}
	void		_shiftLeft(iterator position) {
		value_type	data;

		for (iterator it = position; it != this->end(); it++) {
			position++;
			data = *position;
			*it = data;
		}
		this->_data.end -= 1;
	}
	std::string	_errorStr(size_type n) const {
		std::string		err("vector::_M_range_check: __n (which is ");
		char			nb_char[50];

		std::sprintf(nb_char, "%lu", n);
		err += nb_char;
		err += ") >= this->size() (which is ";
		std::sprintf(nb_char, "%lu", this->size());
		err += nb_char;
		err += ")";
		return err;
	}
};

// Relational Operators
template <class T, class Alloc>
bool operator==(Vector<T, Alloc> const & lhs, Vector<T, Alloc> const & rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!=(Vector<T, Alloc> const & lhs, Vector<T, Alloc> const & rhs) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<(Vector<T, Alloc> const & lhs, Vector<T, Alloc> const & rhs) {
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator<=(Vector<T, Alloc> const & lhs, Vector<T, Alloc> const & rhs) {
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) ||
		equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator>(Vector<T, Alloc> const & lhs, Vector<T, Alloc> const & rhs) {
	return !(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) ||
			equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator>=(Vector<T, Alloc> const & lhs, Vector<T, Alloc> const & rhs) {
	return !lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

// Non Member Function Overloads
template <class T, class Alloc>
void	swap(Vector<T, Alloc> & x, Vector<T, Alloc> & y) {
	x.swap(y);
}

}

#endif
