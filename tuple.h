#ifndef PBL_CPP_CPP_TUPLE_H
#define PBL_CPP_CPP_TUPLE_H

#include "version.h"

#ifdef CPP11
#include <tuple>
#else
#include <utility>

namespace cpp11
{
template< typename T, typename U >
std::pair< T&, U& > tie(
	T& t,
	U& u
)
{
	return std::pair< T&, U& >(t, u);
}

}
#endif

#endif // PBL_CPP_CPP_TUPLE_H
