#ifndef PBL_CPP_IS_ENUM
#define PBL_CPP_IS_ENUM

#include "is_void.h"
#include "is_integral.h"
#include "is_floating_point.h"
#include "is_array.h"
#include "is_pointer.h"
#include "is_reference.h"
#include "is_member_pointer.h"
#include "is_function.h"
#include "is_class_or_union.h"

namespace cpp11
{
template< typename T >
struct is_enum
	: public cpp17::bool_constant<
		  !is_void< T >::value
		  && !is_integral< T >::value
		  && !is_floating_point< T >::value
		  && !is_array< T >::value
		  && !is_pointer< T >::value
		  && !is_reference< T >::value
		  && !is_member_pointer< T >::value
		  && !detail::is_class_or_union< T >::value
		  && !is_function< T >::value
	>
{
};
}

#endif // IS_ENUM
