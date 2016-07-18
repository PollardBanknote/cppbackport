#ifndef PBL_CPP_TRAITS_IS_SCALAR_H
#define PBL_CPP_TRAITS_IS_SCALAR_H

#include "integral_constant.h"
#include "is_arithmetic.h"
#include "is_enum.h"
#include "is_pointer.h"
#include "is_member_pointer.h"
#include "is_null_pointer.h"

namespace cpp11
{
template< class T >
struct is_scalar
	: cpp::bool_constant<
		  cpp::is_arithmetic< T >::value
		  || cpp::is_enum< T >::value
		  || cpp::is_pointer< T >::value
		  || cpp::is_member_pointer< T >::value
		  || cpp::is_null_pointer< T >::value >
{};
}
#endif // PBL_CPP_TRAITS_IS_SCALAR_H
