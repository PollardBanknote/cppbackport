#ifndef PBL_CPP_CSTDLIB_H
#define PBL_CPP_CSTDLIB_H

#include <cstdlib>

#include "version.h"
#ifndef CPP11
namespace cpp11
{
#if _XOPEN_SOURCE >= 600 || _ISOC99_SOURCE || _POSIX_C_SOURCE >= 200112L
void _Exit(int code) __attribute__(( noreturn ));

inline void _Exit(int code)
{
	::_Exit(code);
}

#endif
}
#endif

#endif // PBL_CPP_CSTDLIB_H
