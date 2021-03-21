#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "List.hpp"

namespace ft {

/*
 * Queue Class
 * /usr/include/c++/9/bits/stl_queue.h if using 42 VM
 * https://www.cplusplus.com/reference/queue/
*/
template<typename T, typename Sequence = List<T> >
class Queue
{
public:
	// Member Typedefs
	typedef typename Sequence::value_type			value_type;
	typedef typename Sequence::reference			reference;
	typedef typename Sequence::const_reference		const_reference;
	typedef typename Sequence::size_type			size_type;
	typedef Sequence								container_type;

	// Canonic Class
	explicit Queue(const container_type & ctnr = container_type()) : c(ctnr) {}
	explicit Queue(const Queue & x) : c(x.c) {}
	virtual ~Queue() {}
	Queue &	operator=(Queue const & x) {
		c = x.c;
		return *this;
	}

	// Member Functions
	bool				empty() const { return c.empty(); }
	size_type			size() const { return c.size(); }
	value_type &		front() { return c.front(); }
	const value_type &	front() const { return c.front(); }
	value_type &		back() { return c.back(); }
	const value_type &	back() const { return c.back(); }
	void				push(const value_type & val) { c.push_back(val); }
	void				pop() { c.pop_front(); }

protected:
	Sequence	c;

private:
	// Friend to alloc protected data access
	template <class _T, class _Container>
	friend inline bool operator==(const Queue<_T, _Container> & lhs
			, const Queue<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator!=(const Queue<_T, _Container> & lhs
			, const Queue<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator<(const Queue<_T, _Container> & lhs
			, const Queue<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator<=(const Queue<_T, _Container> & lhs
			, const Queue<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator>(const Queue<_T, _Container> & lhs
			, const Queue<_T, _Container> & rhs);
	template <class _T, class _Container>
	friend inline bool operator>=(const Queue<_T, _Container> & lhs
			, const Queue<_T, _Container> & rhs);

};

// Relational Operators
template <class T, class Container>
inline bool operator==(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs) {
	return lhs.c == rhs.c;
}
template <class T, class Container>
inline bool operator!=(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs) {
	return lhs.c != rhs.c;
}
template <class T, class Container>
inline bool operator<(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs) {
	return lhs.c < rhs.c;
}
template <class T, class Container>
inline bool operator<=(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs) {
	return lhs.c <= rhs.c;
}
template <class T, class Container>
inline bool operator>(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs) {
	return lhs.c > rhs.c;
}
template <class T, class Container>
inline bool operator>=(const Queue<T, Container> & lhs, const Queue<T, Container> & rhs) {
	return lhs.c >= rhs.c;
}

}

#endif
