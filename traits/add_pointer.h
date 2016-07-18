#ifndef PBL_CPP_TRAITS_ADD_POINTER_H
#define PBL_CPP_TRAITS_ADD_POINTER_H

#include "remove_reference.h"

namespace cpp11
{
template< class T >
struct add_pointer
{
	typedef typename remove_reference< T >::type* type;
};
}
#endif // PBL_CPP_TRAITS_ADD_POINTER_H
