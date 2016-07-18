/* Fake rvalue references
 *
 * Objects that we can take a reference for, we do. Otherwise we copy the
 * object.
 */
#ifndef PBL_CPP_RVALUEREF_H
#define PBL_CPP_RVALUEREF_H

#include "version.h"

#ifndef CPP11
namespace cpp11
{
// A class to fake rvalue references
template< typename T >
struct rvalue_reference
{
	explicit rvalue_reference(T& value)
		: ref(value)
	{
	}

	T& ref;
};
}
#endif // ifndef CPP11

#endif // PBL_CPP_RVALUEREF_H
