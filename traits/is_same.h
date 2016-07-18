#ifndef PBL_CPP_TRAITS_IS_SAME_H
#define PBL_CPP_TRAITS_IS_SAME_H

#include "integral_constant.h"

namespace cpp11
{
template< class T, class U >
struct is_same
	: false_type {};

template< class T >
struct is_same< T, T >
	: true_type {};

}
#endif // PBL_CPP_TRAITS_IS_SAME_H
