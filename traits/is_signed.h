#ifndef PBL_CPP_TRAITS_IS_SIGNED_H
#define PBL_CPP_TRAITS_IS_SIGNED_H

#include <limits>
#include "integral_constant.h"
#include "is_arithmetic.h"

namespace cpp11
{
namespace detail
{
template< typename T, bool = is_arithmetic< T >::value >
struct is_signed
	: cpp17::bool_constant< std::numeric_limits< typename remove_cv< T >::type >::is_signed >
{};

template< typename T >
struct is_signed< T, false >
	: false_type
{};
}

template< typename T >
struct is_signed
	: detail::is_signed< T >::type {};
}

#endif // PBL_CPP_TRAITS_IS_SIGNED_H
