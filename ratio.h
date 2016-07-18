#ifndef PBL_CPP_RATIO_H
#define PBL_CPP_RATIO_H

#include "version.h"

#ifdef CPP11
#include <ratio>
#else
#include "cstdint.h"

namespace cpp11
{
namespace detail
{
template< cpp::intmax_t X >
struct sign
{
	static const cpp::intmax_t value = ( X >= 0 ? 1 : -1 );
};

template< cpp::intmax_t X >
struct abs
{
	static const cpp::intmax_t value = ( X >= 0 ? X : -X );
};

template< cpp::intmax_t P, cpp::intmax_t Q >
struct gcd
{
	static const cpp::intmax_t value = gcd< abs< Q >::value, abs< P >::value % abs< Q >::value >::value;
};

template< cpp::intmax_t P >
struct gcd< P, 0 >
{
	static const cpp::intmax_t value = abs< P >::value;
};

template< cpp::intmax_t Q >
struct gcd< 0, Q >
{
	static const cpp::intmax_t value = abs< Q >::value;
};

}

template< cpp::intmax_t Num, cpp::intmax_t Denom = 1 >
class ratio
{
public:

	static const intmax_t num = detail::sign< Num >::value * detail::sign< Denom >::value
	                            * detail::abs< Num >::value / detail::gcd< Num, Denom >::value;

	static const intmax_t den = detail::abs< Denom >::value / detail::gcd< Num, Denom >::value;

	typedef ratio< num, den > type;
};

typedef ratio< 1000000000L, 1 > giga;
typedef ratio< 1000000L, 1 > mega;
typedef ratio< 1000, 1 > kilo;
typedef ratio< 100, 1 > hecto;
typedef ratio< 10, 1 > deca;
typedef ratio< 1, 10 > deci;
typedef ratio< 1, 100 > centi;
typedef ratio< 1, 1000 > milli;
typedef ratio< 1, 1000000L > micro;
typedef ratio< 1, 1000000000L > nano;
}
#endif // ifndef CPP11
#endif // PBL_CPP_RATIO_H
