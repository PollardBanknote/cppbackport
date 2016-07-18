#ifndef PBL_CPP_CSTDARG_H
#define PBL_CPP_CSTDARG_H

#include <cstdarg>

#include "version.h"
#ifndef CPP11

#ifndef va_copy
#ifdef __va_copy
/** @brief Workaround for va_copy macro
 *
 * va_copy was not standardized until C++11, but is usually available
 * as the non-standard __va_copy. In this case, a define is appropriate
 * because va_copy is *supposed* to be a macro
 */
#define va_copy(dest, src) __va_copy(dest, src)
#endif
#endif

#endif
#endif // PBL_CPP_CSTDARG_H
