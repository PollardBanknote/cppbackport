#ifndef PBL_CPP_TRAITS_IS_POINTER_H
#define PBL_CPP_TRAITS_IS_POINTER_H

#include "integral_constant.h"
#include "remove_cv.h"

namespace cpp11
{
namespace detail
{
template< class T >
struct is_pointer_helper
	: false_type
{};

template< class T >
struct is_pointer_helper< T* >
	: true_type
{};
}

template< class T >
struct is_pointer
	: cpp17::bool_constant< detail::is_pointer_helper< typename remove_cv< T >::type >::value >
{};
}
#endif // PBL_CPP_TRAITS_IS_POINTER_H
