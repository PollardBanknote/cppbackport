#ifndef PBL_CPP_TRAITS_IS_VOID_H
#define PBL_CPP_TRAITS_IS_VOID_H

#include "remove_cv.h"
#include "is_same.h"

namespace cpp11
{
template< class T >
struct is_void
	: is_same< void, typename remove_cv< T >::type >{};
}
#endif // PBL_CPP_TRAITS_IS_VOID_H
