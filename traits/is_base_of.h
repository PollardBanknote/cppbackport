#ifndef PBL_CPP_TRAITS_IS_BASE_OF_H
#define PBL_CPP_TRAITS_IS_BASE_OF_H

#include "integral_constant.h"
#include "is_class_or_union.h"
#include "yesno.h"

namespace cpp11
{
namespace detail
{
template< typename B, typename D >
struct host
{
	operator B*() const;
	operator D*();
};

template< typename B, typename D >
struct is_base_of_impl
{
	template< typename T >
	static yes check(D*, T);

	static no check(B*, int);
};

template< typename B, typename D, bool = detail::is_class_or_union< B >::value&& detail::is_class_or_union< D >::value >
struct is_base_of_helper
	: cpp17::bool_constant< ( sizeof is_base_of_impl< B, D >::check(host< B, D >( ), int())) == sizeof( detail::yes ) >
{
};

/* Need some specializations to handle references because the detail structs
   form a pointer to reference. Might be able to work around it if the pointer
   to reference occurs in a SFINAE context.
 */
template< typename B, typename D >
struct is_base_of_helper< B, D, false >
	: false_type
{
};

}


template< typename B, typename D >
struct is_base_of
	: cpp17::bool_constant< detail::is_base_of_helper< B, D >::value >
{
};

}
#endif // PBL_CPP_TRAITS_IS_BASE_OF_H
