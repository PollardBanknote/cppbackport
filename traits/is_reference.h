#ifndef PBL_CPP_TRAITS_IS_REFERENCE_H
#define PBL_CPP_TRAITS_IS_REFERENCE_H

#include "integral_constant.h"

namespace cpp11
{
template< typename T >
struct is_lvalue_reference
	: false_type {};

template< typename T >
struct is_lvalue_reference< T& >
	: true_type {};

template< typename T >
struct is_rvalue_reference
	: false_type {};

template< class T >
struct is_reference
	: cpp17::bool_constant< ( is_lvalue_reference< T >::value || is_rvalue_reference< T >::value ) >
{
};

}
#endif // PBL_CPP_TRAITS_IS_REFERENCE_H
