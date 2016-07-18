#ifndef PBL_CPP_CSTDDEF_H
#define PBL_CPP_CSTDDEF_H

#include <cstddef>

#include "version.h"
#ifndef CPP11
namespace cpp11
{
struct max_align_t
{
	long double x;
} __attribute__(( aligned ));
}
#endif

#endif // PBL_CPP_CSTDDEF_H
