#ifndef PBL_CPP_TRAITS_IS_CONST_H
#define PBL_CPP_TRAITS_IS_CONST_H

#include "integral_constant.h"

namespace cpp11
{
template< class T >
struct is_const
	: false_type {};
template< class T >
struct is_const< const T >
	: true_type {};
}

#endif // PBL_CPP_TRAITS_IS_CONST_H
