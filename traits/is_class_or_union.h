#ifndef PBL_CPP_IS_CLASS_OR_UNION
#define PBL_CPP_IS_CLASS_OR_UNION

#include "integral_constant.h"
#include "yesno.h"

namespace cpp11
{
namespace detail
{
template< class T >
yes is_class_or_union_helper(int T::*);
template< class T >
no is_class_or_union_helper(...);

template< typename T >
struct is_class_or_union
	: cpp17::bool_constant< sizeof( is_class_or_union_helper< T >( 0 )) == sizeof( yes ) >
{
};
}
}

#endif // IS_CLASS_OR_UNION
