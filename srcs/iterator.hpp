#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{

/*
 * Category Definitions
 * Only the 2 following categories are required for the containers to implement
 * https://www.cplusplus.com/reference/iterator/iterator/
*/
struct bidirectional_iterator_tag {};
struct random_access_iterator_tag {};

/*
 * Iterator Base Class Template
 * https://www.cplusplus.com/reference/iterator/iterator/
*/
template <class Category, class T, class Distance = std::ptrdiff_t
	, class Pointer = T*, class Reference = T&>
struct iterator {
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

/*
 * Iterator Traits Class
 * Define properties of the iterator (2 specializations)
 * /usr/include/c++/9/bits/stl_iterator_base_types.h if using 42 VM
 * https://www.cplusplus.com/reference/iterator/iterator_traits/
*/

template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::value_type				value_type;
	typedef typename Iterator::difference_type			difference_type;
	typedef typename Iterator::pointer					pointer;
	typedef typename Iterator::reference				reference;
	typedef typename Iterator::iterator_category		iterator_category;
};

template <class T>
struct iterator_traits<T*>
{
	typedef T									value_type;
	typedef std::ptrdiff_t						difference_type;
	typedef T *									pointer;
	typedef T &									reference;
	typedef random_access_iterator_tag			iterator_category;
};

template <class T>
struct iterator_traits<T const *>
{
	typedef T									value_type;
	typedef std::ptrdiff_t						difference_type;
	typedef T const *							pointer;
	typedef T const &							reference;
	typedef random_access_iterator_tag			iterator_category;
};

/*
 * Reverse Iterator Class
 * /usr/include/c++/9/bits/stl_iterator.h if using 42 VM
 * https://www.cplusplus.com/reference/iterator/reverse_iterator/
*/
template <class Iterator>
class reverse_iterator : public iterator
		<typename iterator_traits<Iterator>::iterator_category,
		typename iterator_traits<Iterator>::value_type,
		typename iterator_traits<Iterator>::difference_type,
		typename iterator_traits<Iterator>::pointer,
		typename iterator_traits<Iterator>::reference>
{
protected:
	Iterator							_cur;

	typedef iterator_traits<Iterator>	_traits_type;

public:
	// Member Typedefs
	typedef Iterator									iterator_type;
	typedef typename _traits_type::difference_type		difference_type;
	typedef typename _traits_type::pointer				pointer;
	typedef typename _traits_type::reference			reference;

	// Canonic Class
	reverse_iterator() : _cur() {}
	explicit reverse_iterator (iterator_type x) : _cur(x) {}
	template <class It>
	reverse_iterator(reverse_iterator<It> const & x) : _cur(x.base()) {}
	reverse_iterator &	operator=(reverse_iterator const & x) {
		this->_cur = x._cur;
		return *this;
	}
	virtual ~reverse_iterator() {}

	// Member Functions
	iterator_type base() const { return this->_cur; }
	reference	operator*() const {
		Iterator	tmp = this->_cur;
		return *tmp;
	}
	pointer	operator->() const {
		Iterator	tmp = this->_cur;
		return tmp;
	}
	reverse_iterator &	operator++() {
		--this->_cur;
		return *this;
	}
	reverse_iterator	operator++(int) {
		reverse_iterator	tmp = *this;
		--this->_cur;
		return tmp;
	}
	reverse_iterator &	operator--() {
		++this->_cur;
		return *this;
	}
	reverse_iterator	operator--(int) {
		reverse_iterator	tmp = *this;
		++this->_cur;
		return tmp;
	}
	reverse_iterator	operator+(difference_type n) const {
		return (reverse_iterator(this->_cur - n));
	}
	reverse_iterator &	operator+=(difference_type n) {
		this->_cur -= n;
		return *this;
	}
	reverse_iterator	operator-(difference_type n) const {
		return (reverse_iterator(this->_cur + n));
	}
	reverse_iterator &	operator-=(difference_type n) {
		this->_cur += n;
		return *this;
	}
	reference	operator[](difference_type n) const {
		return *(*this - n);
	}
};

/*
 * Reverse Iterator Non Member Function Overloads
 * 4 Definitions each time for comparison between rev_it and const_rev_it
 * /usr/include/c++/9/bits/stl_iterator.h if using 42 VM
 * https://www.cplusplus.com/reference/iterator/reverse_iterator/
*/

// == comparison
template <typename Iterator>
inline bool		operator==(reverse_iterator<Iterator> const & x
		, reverse_iterator<Iterator> const & y) {
	return x.base() == y.base();
}

template <typename Iterator1, typename Iterator2>
inline bool		operator==(reverse_iterator<Iterator1> const & x
		, reverse_iterator<Iterator2> const & y) {
	return x.base() == y.base();
}

// != comparison
template <typename Iterator>
inline bool		operator!=(reverse_iterator<Iterator> const & x
		, reverse_iterator<Iterator> const & y) {
	return !(x == y);
}

template <typename Iterator1, typename Iterator2>
inline bool		operator!=(reverse_iterator<Iterator1> const & x
		, reverse_iterator<Iterator2> const & y) {
	return !(x == y);
}

// < comparison
template <typename Iterator>
inline bool		operator<(reverse_iterator<Iterator> const & x
		, reverse_iterator<Iterator> const & y) {
	return y.base() < x.base();
}

template <typename Iterator1, typename Iterator2>
inline bool		operator<(reverse_iterator<Iterator1> const & x
		, reverse_iterator<Iterator2> const & y) {
	return y.base() < x.base();
}

// > comparison
template <typename Iterator>
inline bool		operator>(reverse_iterator<Iterator> const & x
		, reverse_iterator<Iterator> const & y) {
	return y < x;
}

template <typename Iterator1, typename Iterator2>
inline bool		operator>(reverse_iterator<Iterator1> const & x
		, reverse_iterator<Iterator2> const & y) {
	return y < x;
}

// <= comparison
template <typename Iterator>
inline bool		operator<=(reverse_iterator<Iterator> const & x
		, reverse_iterator<Iterator> const & y) {
	return !(y < x);
}

template <typename Iterator1, typename Iterator2>
inline bool		operator<=(reverse_iterator<Iterator1> const & x
		, reverse_iterator<Iterator2> const & y) {
	return !(y < x);
}

// >= comparison
template <typename Iterator>
inline bool		operator>=(reverse_iterator<Iterator> const & x
		, reverse_iterator<Iterator> const & y) {
	return !(x < y);
}

template <typename Iterator1, typename Iterator2>
inline bool		operator>=(reverse_iterator<Iterator1> const & x
		, reverse_iterator<Iterator2> const & y) {
	return !(x < y);
}

template <typename Iterator>
inline typename	reverse_iterator<Iterator>::difference_type	operator-(
		reverse_iterator<Iterator> const & x, reverse_iterator<Iterator> const & y) {
	return y.base() - x.base();
}

template <typename Iterator1, typename Iterator2>
inline typename	reverse_iterator<Iterator1>::difference_type	operator-(
		reverse_iterator<Iterator1> const & x, reverse_iterator<Iterator2> const & y) {
	return y.base() - x.base();
}

template <typename Iterator>
inline typename	reverse_iterator<Iterator>::difference_type	operator+(
		typename reverse_iterator<Iterator>::difference_type n
		, reverse_iterator<Iterator> const & x) {
	return reverse_iterator<Iterator>(x.base() - n);
}

}

#endif
