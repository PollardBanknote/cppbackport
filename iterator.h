/** @file iterator.h
 * @brief Implementation of C++11 iterator header
 */
#ifndef PBL_CPP_ITERATOR_H
#define PBL_CPP_ITERATOR_H

#include "version.h"

#include <iterator>

#ifndef CPP11
namespace cpp11
{
template< typename T >
typename T::iterator begin(T& c)
{
	return c.begin();
}

/** @brief Get a beginning iterator to a container
 * @param c A container
 * @returns c.begin()
 */
template< typename T >
typename T::const_iterator begin(const T& c)
{
	return c.begin();
}

template< typename T >
typename T::iterator end(T& c)
{
	return c.end();
}

/** @brief Get an end iterator to a container
 * @param c A container
 * @returns c.end()
 */
template< typename T >
typename T::const_iterator end(const T& c)
{
	return c.end();
}

template< typename T, std::size_t N >
T* begin(T(&a)[N])
{
	return a;
}

/** @brief Get a beginning iterator to an array
 * @param a An array
 * @returns Pointer to the first element of a
 */
template< typename T, std::size_t N >
const T* begin(const T(&a)[N])
{
	return a;
}

template< typename T, std::size_t N >
T* end(T(&a)[N])
{
	return a + N;
}

/** @brief Get an end iterator to an array
 * @param a An array
 * @returns Pointer to the past-the-last elemnt of a
 */
template< typename T, std::size_t N >
const T* end(const T(&a)[N])
{
	return a + N;
}

template< typename InputIterator >
InputIterator next(
	InputIterator                                                   it,
	typename std::iterator_traits< InputIterator >::difference_type n = 1
)
{
	std::advance(it, n);

	return it;
}

template< typename BidirectionalIterator >
BidirectionalIterator prev(
	BidirectionalIterator                                                   it,
	typename std::iterator_traits< BidirectionalIterator >::difference_type n = 1
)
{
	std::advance(it, -n);

	return it;
}

}
#endif // ifndef CPP11

#ifndef CPP14
namespace cpp14
{

template< typename T >
typename T::const_iterator cbegin(const T& c)
{
	return c.begin();
}

template< typename T, std::size_t N >
const T* cbegin(const T(&a)[N])
{
	return a;
}

template< typename T >
typename T::const_iterator cend(const T& c)
{
	return c.end();
}

template< typename T, std::size_t N >
const T* cend(const T(&a)[N])
{
	return a + N;
}

}
#endif // ifndef CPP14

#ifndef CPP17
namespace cpp17
{
template< typename T, std::size_t N >
std::size_t size(const T(&)[N])
{
	return N;
}

}
#endif // ifndef CPP17

#endif // PBL_CPP__ITERATOR_H
