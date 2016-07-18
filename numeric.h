#ifndef PBL_CPP_NUMERIC_H
#define PBL_CPP_NUMERIC_H

#include <numeric>

#include "version.h"
#ifndef CPP11

namespace cpp11
{
template< class ForwardIterator, class T >
void iota(
	ForwardIterator first,
	ForwardIterator last,
	T               value
)
{
	while ( first != last )
	{
		*first++ = value;
		++value;
	}
}

}
#endif

#endif // PBL_CPP_NUMERIC_H
