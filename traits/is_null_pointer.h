#ifndef PBL_CPP_TRAITS_IS_NULL_POINTER_H
#define PBL_CPP_TRAITS_IS_NULL_POINTER_H

#ifndef CPP14
#include "integral_constant.h"

namespace cpp14
{
template< class T >
struct is_null_pointer
	: cpp::false_type
{
};
}
#endif
#endif // PBL_CPP_TRAITS_IS_NULL_POINTER_H
