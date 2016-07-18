#ifndef PBL_CPP_TRAITS_IS_MEMBER_POINTER_H
#define PBL_CPP_TRAITS_IS_MEMBER_POINTER_H

#include "integral_constant.h"
#include "remove_cv.h"
#include "is_function.h"

namespace cpp11
{
namespace detail
{
template< class T >
struct is_member_pointer_helper
	: false_type
{
};

template< class T, class U >
struct is_member_pointer_helper< T U::* >
	: true_type
{
};

template< class T >
struct is_member_function_pointer_helper
	: false_type {};

template< class T, class U >
struct is_member_function_pointer_helper< T U::* >
	: is_function< T >{};
}

template< class T >
struct is_member_pointer
	: detail::is_member_pointer_helper< typename remove_cv< T >::type >
{
};

template< class T >
struct is_member_function_pointer
	: detail::is_member_function_pointer_helper< typename remove_cv< T >::type >
{
};

template< class T >
struct is_member_object_pointer
	: cpp17::bool_constant< is_member_pointer< T >::value&& !is_member_function_pointer< T >::value >
{};
}

#endif // PBL_CPP_TRAITS_IS_MEMBER_POINTER_H
