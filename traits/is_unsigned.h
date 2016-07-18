#ifndef PBL_CPP_TRAITS_IS_UNSIGNED_H
#define PBL_CPP_TRAITS_IS_UNSIGNED_H

#include <limits>
#include "integral_constant.h"
#include "is_arithmetic.h"

namespace cpp11
{
namespace detail
{
template< typename T, bool = is_arithmetic< T >::value >
struct is_unsigned
	: cpp17::bool_constant< !( std::numeric_limits< typename remove_cv< T >::type >::is_signed ) >{};

template< typename T >
struct is_unsigned< T, false >
	: false_type {};
}   // namespace detail

template< typename T >
struct is_unsigned
	: detail::is_unsigned< T >::type {};
}

#endif // PBL_CPP_TRAITS_IS_UNSIGNED_H
