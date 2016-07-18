#ifndef PBL_CPP_SYSTEM_ERROR_H
#define PBL_CPP_SYSTEM_ERROR_H

#include "version.h"

#ifdef CPP11
#include <system_error>
#else
namespace cpp11
{
typedef int error_code;
}
#endif

#endif // PBL_CPP_SYSTEM_ERROR_H
