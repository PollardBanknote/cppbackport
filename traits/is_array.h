#ifndef PBL_CPP_TRAITS_IS_ARRAY_H
#define PBL_CPP_TRAITS_IS_ARRAY_H

#include "integral_constant.h"

namespace cpp11
{
template< class T >
struct is_array
	: false_type {};

template< class T >
struct is_array< T[] >
	: true_type {};

template< class T, std::size_t N >
struct is_array< T[N] >
	: true_type {};
}
#endif // PBL_CPP_TRAITS_IS_ARRAY_H
