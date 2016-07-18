#ifndef PBL_CPP_TRAITS_IS_VOLATILE_H
#define PBL_CPP_TRAITS_IS_VOLATILE_H

#include "integral_constant.h"

namespace cpp11
{
template< class T >
struct is_volatile
	: false_type {};
template< class T >
struct is_volatile< volatile T >
	: true_type {};
}
#endif // PBL_CPP_TRAITS_IS_VOLATILE_H
