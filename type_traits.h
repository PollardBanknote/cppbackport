/** @file type_traits.h
 * @brief Implementation of C++11 type_traits header
 */
#ifndef PBL_CPP_TYPE_TRAITS_H
#define PBL_CPP_TYPE_TRAITS_H

#include "version.h"

#ifdef CPP11
#include <type_traits>
#endif

// Always include these as they have extensions above C++11
#include "traits/alignment.h"
#include "traits/integral_constant.h"

#ifndef CPP11
#include "traits/add_cv.h"
#include "traits/add_pointer.h"
#include "traits/add_reference.h"
#include "traits/common_type.h"
#include "traits/conditional.h"
#include "traits/decay.h"
#include "traits/declval.h"
#include "traits/enable_if.h"
#include "traits/extent.h"
#include "traits/is_arithmetic.h"
#include "traits/is_array.h"
#include "traits/is_base_of.h"
#include "traits/is_compound.h"
#include "traits/is_const.h"
#include "traits/is_convertible.h"
#include "traits/is_enum.h"
#include "traits/is_floating_point.h"
#include "traits/is_function.h"
#include "traits/is_fundamental.h"
#include "traits/is_integral.h"
#include "traits/is_member_pointer.h"
#include "traits/is_null_pointer.h"
#include "traits/is_object.h"
#include "traits/is_pointer.h"
#include "traits/is_reference.h"
#include "traits/is_same.h"
#include "traits/is_scalar.h"
#include "traits/is_signed.h"
#include "traits/is_unsigned.h"
#include "traits/is_void.h"
#include "traits/is_volatile.h"
#include "traits/make_signed.h"
#include "traits/make_unsigned.h"
#include "traits/rank.h"
#include "traits/remove_cv.h"
#include "traits/remove_extent.h"
#include "traits/remove_pointer.h"
#include "traits/remove_reference.h"
#include "traits/result_of.h"
#endif // if __cplusplus >= 201102L
#endif // PBL_CPP_TYPE_TRAITS_H
