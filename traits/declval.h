#ifndef PBL_CPP_TRAITS_DECLVAL_H
#define PBL_CPP_TRAITS_DECLVAL_H

#include "add_reference.h"

namespace cpp11
{

template< typename T >
typename add_lvalue_reference< T >::type declval();

}

#endif // PBL_CPP_TRAITS_DECLVAL_H
