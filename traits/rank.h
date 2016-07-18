#ifndef PBL_CPP_TRAITS_RANK_H
#define PBL_CPP_TRAITS_RANK_H

#include "integral_constant.h"
namespace cpp11
{
template< class T >
struct rank
	: public integral_constant< std::size_t, 0 >{};

template< class T >
struct rank< T[] >
	: public integral_constant< std::size_t, rank< T >::value + 1 >{};

template< class T, std::size_t N >
struct rank< T[N] >
	: public integral_constant< std::size_t, rank< T >::value + 1 >{};
}

#endif // PBL_CPP_TRAITS_RANK_H
