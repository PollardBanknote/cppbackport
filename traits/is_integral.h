#ifndef PBL_CPP_TRAITS_IS_INTEGRAL_H
#define PBL_CPP_TRAITS_IS_INTEGRAL_H

#include "integral_constant.h"
#include "config/arch.h"
#include "is_same.h"
#include "remove_cv.h"

namespace cpp11
{
template< class T >
struct is_integral
	: cpp17::bool_constant<
		  is_same< bool, typename remove_cv< T >::type >::value
		  || is_same< char, typename remove_cv< T >::type >::value
		  || is_same< signed char, typename remove_cv< T >::type >::value
		  || is_same< unsigned char, typename remove_cv< T >::type >::value
		  || is_same< wchar_t, typename remove_cv< T >::type >::value
		  || is_same< short, typename remove_cv< T >::type >::value
		  || is_same< unsigned short, typename remove_cv< T >::type >::value
		  || is_same< int, typename remove_cv< T >::type >::value
		  || is_same< unsigned int, typename remove_cv< T >::type >::value
		  || is_same< long, typename remove_cv< T >::type >::value
		  || is_same< unsigned long, typename remove_cv< T >::type >::value
		  #ifdef HAS_LONG_LONG
		  || is_same< long long, typename remove_cv< T >::type >::value
		  || is_same< unsigned long long, typename remove_cv< T >::type >::value
		  #endif
	>
{};
}

#endif // PBL_CPP_TRAITS_IS_INTEGRAL_H
