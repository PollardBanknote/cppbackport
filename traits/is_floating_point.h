#ifndef PBL_CPP_TRAITS_IS_FLOATING_POINT_H
#define PBL_CPP_TRAITS_IS_FLOATING_POINT_H

#include "integral_constant.h"
#include "is_same.h"
#include "remove_cv.h"

namespace cpp11
{
template< class T >
struct is_floating_point
	: cpp17::bool_constant<
		  is_same< float, typename remove_cv< T >::type >::value ||
		  is_same< double, typename remove_cv< T >::type >::value ||
		  is_same< long double, typename remove_cv< T >::type >::value
	>
{};
}
#endif // PBL_CPP_TRAITS_IS_FLOATING_POINT_H
