#ifndef PBL_CPP_TRAITS_DECAY_H
#define PBL_CPP_TRAITS_DECAY_H

#include "remove_reference.h"
#include "conditional.h"
#include "is_array.h"
#include "remove_extent.h"
#include "add_pointer.h"
#include "remove_cv.h"
#include "is_function.h"

namespace cpp11
{
namespace detail
{
template< typename T, bool Function = is_function< T >::value >
struct decay_function
{
	typedef typename remove_cv< T >::type type;
};

template< typename T >
struct decay_function< T, true >
{
	typedef typename add_pointer< T >::type type;
};

template< typename T, bool Array = is_array< T >::value >
struct decay_helper
{
	typedef typename decay_function< T >::type type;
};

// decay array types
template< typename T >
struct decay_helper< T, true >
{
	typedef typename remove_extent< T >::type* type;
};

}

template< class T >
struct decay
{
	typedef typename detail::decay_helper< typename remove_reference< T >::type >::type type;
};

}
#endif // PBL_CPP_TRAITS_DECAY_H
