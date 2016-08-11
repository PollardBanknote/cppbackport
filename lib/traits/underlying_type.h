#ifndef UNDERLYING_TYPE_H
#define UNDERLYING_TYPE_H

#include "is_enum.h"

namespace cpp11
{
namespace details
{
template< typename, bool B >
struct underlying_type_helper
{
	typedef unsigned long type;
};

template< typename E >
struct underlying_type_helper< E, true >
{
	typedef long type;
};
}

template< typename E, typename Enable = void >
struct underlying_type;

template< typename E >
struct underlying_type< E, typename enable_if< is_enum< E >::value >::type >
{
	typedef typename details::underlying_type_helper < E, static_cast< E >( -1 ) < static_cast< E > (0) > ::type type;
};

}

#endif // UNDERLYING_TYPE_H
