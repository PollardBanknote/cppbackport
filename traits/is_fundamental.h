#ifndef PBL_CPP_TRAITS_IS_FUNDAMENTAL_H
#define PBL_CPP_TRAITS_IS_FUNDAMENTAL_H

#include "is_void.h"
#include "is_arithmetic.h"

namespace cpp11
{
template< class T >
struct is_fundamental
	: cpp17::bool_constant< is_arithmetic< T >::value || is_void< T >::value >
{};
}

#endif // PBL_CPP_TRAITS_IS_FUNDAMENTAL_H
