#ifndef PBL_CPP_TRAITS_EXTENT_H
#define PBL_CPP_TRAITS_EXTENT_H

#include "integral_constant.h"

namespace cpp11
{
template< class T, unsigned N = 0 >
struct extent
	: integral_constant< std::size_t, 0 >{};

template< class T >
struct extent< T[], 0 >
	: integral_constant< std::size_t, 0 >{};

template< class T, unsigned N >
struct extent< T[], N >
	: integral_constant< std::size_t, extent< T, N - 1 >::value >{};

template< class T, std::size_t N >
struct extent< T[N], 0 >
	: integral_constant< std::size_t, N >{};

template< class T, std::size_t I, unsigned N >
struct extent< T[I], N >
	: integral_constant< std::size_t, extent< T, N - 1 >::value >{};
}
#endif // PBL_CPP_TRAITS_EXTENT_H
