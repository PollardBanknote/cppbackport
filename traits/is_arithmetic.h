#ifndef PBL_CPP_TRAITS_IS_ARITHMETIC_H
#define PBL_CPP_TRAITS_IS_ARITHMETIC_H

#include "integral_constant.h"
#include "is_integral.h"
#include "is_floating_point.h"

namespace cpp11
{
template< class T >
struct is_arithmetic
	: cpp17::bool_constant< is_integral< T >::value || is_floating_point< T >::value >
{};
}
#endif // PBL_CPP_TRAITS_IS_ARITHMETIC_H
