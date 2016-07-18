/** @file string.h
 * @brief Implementation of C++11 string header
 * @todo Might be able to use std::num_put
 */
#ifndef PBL_CPP_STRING_H
#define PBL_CPP_STRING_H

#include <string>

#include "version.h"

#ifndef CPP11
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "config/arch.h"
namespace cpp11
{
namespace detail
{
template< typename I >
std::string arithmetic_to_string(I x)
{
	std::ostringstream ss;

	ss << x;

	return ss.str();
}

}

inline unsigned long stoul(
	const std::string& s,
	std::size_t*       pos = 0,
	int                base = 10
)
{
	char*       ptr;
	const char* s_  = s.c_str();
	const long  res = std::strtoul(s_, &ptr, base);

	if ( pos )
	{
		*pos = ptr - s_;
	}

	return res;
}

/// @todo Should throw if not convertible, or result is too large
inline long stol(
	const std::string& s,
	std::size_t*       pos = 0,
	int                base = 10
)
{
	char*       ptr;
	const char* s_  = s.c_str();
	const long  res = std::strtol(s_, &ptr, base);

	if ( pos )
	{
		*pos = ptr - s_;
	}

	return res;
}

/// @todo Should throw if not convertible, or result is too large
inline int stoi(
	const std::string& s,
	std::size_t*       pos = 0,
	int                base = 10
)
{
	return static_cast< int >( stol(s, pos, base));
}

/** @brief Get the string representation of an int
 * @param n An integer
 * @returns lexical_cast<std::string>(n)
 */
inline std::string to_string(int n)
{
	return detail::arithmetic_to_string(n);
}

inline std::string to_string(long n)
{
	return detail::arithmetic_to_string(n);
}

inline std::string to_string(unsigned n)
{
	return detail::arithmetic_to_string(n);
}

inline std::string to_string(unsigned long n)
{
	return detail::arithmetic_to_string(n);
}

inline std::string to_string(float n)
{
	return detail::arithmetic_to_string(n);
}

inline std::string to_string(double n)
{
	return detail::arithmetic_to_string(n);
}

inline std::string to_string(long double n)
{
	return detail::arithmetic_to_string(n);
}

#ifdef HAS_LONG_LONG
inline std::string to_string(long long n)
{
	return detail::arithmetic_to_string(n);
}

inline std::string to_string(unsigned long long n)
{
	return detail::arithmetic_to_string(n);
}

#endif

}
#endif // ifndef CPP11

#endif // PBL_CPP_STRING_H
