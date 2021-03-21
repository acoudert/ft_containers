#ifndef STACK_HPP
# define STACK_HPP

#include "List.hpp"

namespace ft {

/*
 * Stack Class
 * /usr/include/c++/9/bits/stl_stack.h if using 42 VM
 * https://www.cplusplus.com/reference/stack/
*/
template<typename T, typename Sequence = List<T> >
class Stack
{
public:
	// Member Typedefs
	typedef typename Sequence::value_type			value_type;
	typedef typename Sequence::reference			reference;
	typedef typename Sequence::const_reference		const_reference;
	typedef typename Sequence::size_type			size_type;
	typedef Sequence								container_type;

	// Canonic Class
	explicit Stack(const container_type & ctnr = container_type()) : c(ctnr) {}
	explicit Stack(const Stack & x) : c(x.c) {}
	virtual ~Stack() {}
	Stack &	operator=(Stack const & x) {
		c = x.c;
		return *this;
	}

	// Member Functions
	bool				empty() const { return c.empty(); }
	size_type			size() const { return c.size(); }
	value_type &		top() { return c.back(); }
	const value_type &	top() const { return c.back(); }
	void				push(const value_type & val) { c.push_back(val); }
	void				pop() { c.pop_back(); }

protected:
	Sequence	c;

private:
	// Friend to alloc protected data access
	template <class _T, class _Container>
	friend inline bool operator==(const Stack<_T, _Container> & lhs
			, const Stack<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator!=(const Stack<_T, _Container> & lhs
			, const Stack<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator<(const Stack<_T, _Container> & lhs
			, const Stack<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator<=(const Stack<_T, _Container> & lhs
			, const Stack<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator>(const Stack<_T, _Container> & lhs
			, const Stack<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator>=(const Stack<_T, _Container> & lhs
			, const Stack<_T, _Container> & rhs);

};

// Relational Operators
template <class T, class Container>
inline bool operator==(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs) {
	return lhs.c == rhs.c;
}
template <class T, class Container>
inline bool operator!=(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs) {
	return lhs.c != rhs.c;
}
template <class T, class Container>
inline bool operator<(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs) {
	return lhs.c < rhs.c;
}
template <class T, class Container>
inline bool operator<=(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs) {
	return lhs.c <= rhs.c;
}
template <class T, class Container>
inline bool operator>(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs) {
	return lhs.c > rhs.c;
}
template <class T, class Container>
inline bool operator>=(const Stack<T, Container> & lhs, const Stack<T, Container> & rhs) {
	return lhs.c >= rhs.c;
}

}

#endif
