#ifndef PBL_CPP_UTILITY_H
#define PBL_CPP_UTILITY_H

#include "version.h"

#include <utility>

#ifndef CPP11
#include "rvalueref.h"

namespace cpp11
{
/// @todo If we cannot take T by reference, we should take by value
template< typename T >
rvalue_reference< T > move(T& value)
{
	return rvalue_reference< T >(value);
}

}

#endif // ifndef CPP11

#endif // PBL_CPP_UTILITY_H
