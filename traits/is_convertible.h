#ifndef PBL_CPP_TRAITS_IS_CONVERTIBLE_H
#define PBL_CPP_TRAITS_IS_CONVERTIBLE_H

#include "declval.h"
#include "integral_constant.h"
#include "yesno.h"

namespace cpp11
{
namespace detail
{
// If a type U is convertible to T, it will match against yes f(T)
template< typename T >
struct is_convertible_helper
{
	static no f(...);
	static yes f(T);
};

}

// Can From convert to To
template< typename From, typename To >
struct is_convertible
	: cpp17::bool_constant< ( sizeof( detail::is_convertible_helper< To >::f(declval< From >( ))) == sizeof( detail::yes )) >
{
};

template< typename From >
struct is_convertible< From, void >
	: false_type
{
};

template< typename To >
struct is_convertible< void, To >
	: false_type
{
};

template< >
struct is_convertible< void, void >
	: false_type
{
};
}

#endif // PBL_CPP_TRAITS_IS_CONVERTIBLE_H
