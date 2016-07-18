#ifndef PBL_CPP_TRAITS_IS_OBJECT_H
#define PBL_CPP_TRAITS_IS_OBJECT_H

#include "integral_constant.h"
#include "is_scalar.h"
#include "is_class_or_union.h"
namespace cpp11
{
template< class T >
struct is_object
	: cpp::bool_constant<
		  cpp::is_scalar< T >::value
		  || cpp::is_array< T >::value
		  || cpp::detail::is_class_or_union< T >::value
	>
{};
}

#endif // PBL_CPP_TRAITS_IS_OBJECT_H
