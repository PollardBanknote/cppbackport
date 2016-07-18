#ifndef PBL_CPP_TRAITS_IS_COMPOUND_H
#define PBL_CPP_TRAITS_IS_COMPOUND_H

#include "is_fundamental.h"

namespace cpp11
{
template< class T >
struct is_compound
	: cpp17::bool_constant< !is_fundamental< T >::value >
{
};
}
#endif // PBL_CPP_TRAITS_IS_COMPOUND_H
