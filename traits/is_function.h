#ifndef PBL_CPP_TRAITS_IS_FUNCTION_H
#define PBL_CPP_TRAITS_IS_FUNCTION_H

#include "integral_constant.h"
#include "yesno.h"

namespace cpp11
{
namespace detail
{
// relies on the fact that function pointers do not convert to void* (but
// everything else does)
no is_function_helper(const volatile void*);
yes is_function_helper(...);
}

template< class T >
struct is_function
	: cpp17::bool_constant< (( sizeof detail::is_function_helper((T*) 0)) == sizeof( detail::yes )) >
{
};

template< class T >
struct is_function< T& >
	: false_type
{
};

}

#endif // PBL_CPP_TRAITS_IS_FUNCTION_H
