/* Copyright (c) 2016, Pollard Banknote Limited
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.

   3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** @file cstdint.h
 * @brief Implementation of C++11 cstdint header
 */
#ifndef PBL_CPP_CSTDINT_H
#define PBL_CPP_CSTDINT_H

#include "version.h"

#ifdef CPP11
// Provided by C++11
#include <cstdint>
#else

#include <climits>

// Steal some types from the implementation, if we can
#if !defined( _WIN32 ) && ( defined( __unix__ ) || defined( __unix ) || ( defined( __APPLE__ ) && defined( __MACH__ )))
#include <unistd.h>
#if ( _POSIX_C_SOURCE >= 200112L )
// Provided by POSIX
#include <stdint.h>
namespace cpp11
{
using ::intptr_t;
using ::uintptr_t;
}
#endif // POSIX
#endif // UNIX-LIKE

namespace cpp11
{
#define AT_LEAST_16_BITS_S(x) ((x) >= 32767)
#define AT_LEAST_32_BITS_S(x) ((x) >= 2147483647)
#define AT_LEAST_64_BITS_S(x) ((((((x) >> 15) >> 15) >> 15) >> 15) >= 7)
#define AT_LEAST_16_BITS_U(x) ((x) >= 65535)
#define AT_LEAST_32_BITS_U(x) (((x) >> 1) >= 2147483647)
#define AT_LEAST_64_BITS_U(x) ((((((x) >> 15) >> 15) >> 15) >> 15) >= 15)

#define EXACTLY_8_BITS_S(x) ((x) == 127)
#define EXACTLY_16_BITS_S(x) ((x) == 32767)
#define EXACTLY_32_BITS_S(x) ((x) == 2147483647)
#define EXACTLY_64_BITS_S(x) ((((((x) >> 15) >> 15) >> 15) >> 15) == 7)
#define EXACTLY_8_BITS_U(x) ((x) == 255)
#define EXACTLY_16_BITS_U(x) ((x) == 65535)
#define EXACTLY_32_BITS_U(x) (((x) >> 1) == 2147483647)
#define EXACTLY_64_BITS_U(x) ((((((x) >> 15) >> 15) >> 15) >> 15) == 15)

// int_least8_t
typedef signed char int_least8_t;
#define INT8_C(x) x
#define INT_LEAST8_MIN SCHAR_MIN
#define INT_LEAST8_MAX SCHAR_MAX

// int8_t
#if EXACTLY_8_BITS_S(INT_LEAST8_MAX)
#define INT8_MIN INT_LEAST8_MIN
#define INT8_MAX INT_LEAST8_MAX
typedef int_least8_t int8_t;
#endif

// int_least16_t
#if AT_LEAST_16_BITS_S(SCHAR_MAX)
typedef signed char int_least16_t;
#define INT_LEAST16_MIN SCHAR_MIN
#define INT_LEAST16_MAX SCHAR_MAX
#else
typedef short int int_least16_t;
#define INT_LEAST16_MIN SHRT_MIN
#define INT_LEAST16_MAX SHRT_MAX
#endif
#define INT16_C(x) x

// int16_t
#if EXACTLY_16_BITS_S(INT_LEAST8_MAX)
#define INT16_MIN INT_LEAST16_MIN
#defien INT16_MAX INT_LEAST16_MAX
typedef int_least16_t int16_t;
#endif

// int_least32_t
#if AT_LEAST_32_BITS_S(SCHAR_MAX)
typedef signed char int_least32_t
#define INT_LEAST32_MIN SCHAR_MIN
#define INT_LEAST32_MAX SCHAR_MAX
#define INT32_C(x) x
#elif AT_LEAST_32_BITS_S(SHRT_MAX)
typedef short int int_least32_t
#define INT_LEAST32_MIN SHRT_MIN
#define INT_LEAST32_MAX SHRT_MAX
#define INT32_C(x) x
#elif AT_LEAST_32_BITS_S(INT_MAX)
typedef int int_least32_t;
#define INT_LEAST32_MIN INT_MIN
#define INT_LEAST32_MAX INT_MAX
#define INT32_C(x) x
#else
typedef long int_least32_t;
#define INT_LEAST32_MIN LONG_MIN
#define INT_LEAST32_MAX LONG_MAX
#define INT32_C(x) x##l
#endif

// int32_t
#if EXACTLY_32_BITS_S(INT_LEAST32_MAX)
#define INT32_MIN INT_LEAST32_MIN
#define INT32_MAX INT_LEAST32_MAX
typedef int_least32_t int32_t;
#endif

// int_least64_t
#if AT_LEAST_64_BITS_S(SCHAR_MAX)
typedef signed char int_least64_t
#define INT_LEAST64_MIN SCHAR_MIN
#define INT_LEAST64_MAX SCHAR_MAX
#define INT64_C(x) x
#elif AT_LEAST_64_BITS_S(SHRT_MAX)
typedef short int_least64_t
#define INT_LEAST64_MIN SHRT_MIN
#define INT_LEAST64_MAX SHRT_MAX
#define INT64_C(x) x
#elif AT_LEAST_64_BITS_S(INT_MAX)
typedef int int_least64_t;
#define INT_LEAST64_MIN INT_MIN
#define INT_LEAST64_MAX INT_MAX
#define INT64_C(x) x
#elif AT_LEAST_64_BITS_S(LONG_MAX)
typedef long int_least64_t;
#define INT_LEAST64_MIN LONG_MIN
#define INT_LEAST64_MAX LONG_MAX
#define INT64_C(x) x##l
#else
#ifdef LLONG_MAX
typedef long long int_least64_t;
#define INT_LEAST64_MIN LLONG_MIN
#define INT_LEAST64_MAX LLONG_MAX
#define INT64_C(x) x##ll
#endif
#endif

// int64_t
#if EXACTLY_64_BITS_S(INT_LEAST64_MAX)
#define INT64_MIN INT_LEAST64_MIN
#define INT64_MAX INT_LEAST64_MAX
typedef int_least64_t int64_t;
#endif

// uint_least8_t
typedef unsigned char uint_least8_t;
#define UINT8_C(x) x
#define UINT_LEAST8_MAX UCHAR_MAX

// uint8_t
#if EXACTLY_8_BITS_U(UINT_LEAST8_MAX)
#define UINT8_MAX UINT_LEAST8_MAX
typedef uint_least8_t uint8_t;
#endif

// uint_least16_t
#if AT_LEAST_16_BITS_U(UCHAR_MAX)
typedef unsigned char uint_least16_t;
#define UINT_LEAST16_MAX UCHAR_MAX
#else
typedef unsigned short uint_least16_t;
#define UINT_LEAST16_MAX USHRT_MAX
#endif
#define UINT16_C(x) x

// uint16_t
#if EXACTLY_16_BITS_U(UINT_LEAST16_MAX)
#define UINT16_MAX UINT_LEAST16_MAX
typedef uint_least16_t uint16_t;
#endif

// uint_least32_t
#if AT_LEAST_32_BITS_U(UCHAR_MAX)
typedef unsigned char uint_least32_t
#define UINT_LEAST32_MAX UCHAR_MAX
#define UINT32_C(x) x
#elif AT_LEAST_32_BITS_U(USHRT_MAX)
typedef unsigned short uint_least32_t
#define UINT_LEAST32_MAX USHRT_MAX
#define UINT32_C(x) x
#elif AT_LEAST_32_BITS_U(UINT_MAX)
typedef unsigned uint_least32_t;
#define UINT_LEAST32_MAX UINT_MAX
#define UINT32_C(x) x
#else
typedef unsigned long uint_least32_t;
#define UINT_LEAST32_MAX ULONG_MAX
#define UINT32_C(x) x##l
#endif

// uint32_t
#if EXACTLY_32_BITS_U(UINT_LEAST32_MAX)
#define UINT32_MAX UINT_LEAST32_MAX
typedef uint_least32_t uint32_t;
#endif

// uint_least64_t
#if AT_LEAST_64_BITS_U(UCHAR_MAX)
typedef unsigned char uint_least64_t
#define UINT64_C(x) x
#define UINT_LEAST64_MAX UCHAR_MAX
#elif AT_LEAST_64_BITS_U(USHRT_MAX)
typedef unsigned short uint_least64_t
#define UINT64_C(x) x
#define UINT_LEAST64_MAX USHRT_MAX
#elif AT_LEAST_64_BITS_U(UINT_MAX)
typedef unsigned uint_least64_t;
#define UINT64_C(x) x
#define UINT_LEAST64_MAX UINT_MAX
#elif AT_LEAST_64_BITS_U(LONG_MAX)
typedef unsigned long uint_least64_t;
#define UINT64_C(x) x##l
#define UINT_LEAST64_MAX ULONG_MAX
#else
#ifdef ULLONG_MAX
typedef unsigned long long uint_least64_t;
#define UINT64_C(x) x##ll
#define UINT_LEAST64_MAX ULLONG_MAX
#endif
#endif

// uint64_t
#if EXACTLY_64_BITS_U(UINT_LEAST64_MAX)
#define UINT64_MAX UINT_LEAST64_MAX
typedef uint_least64_t uint64_t;
#endif

typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef long int_fast32_t;
typedef int_least64_t int_fast64_t;

typedef unsigned char uint_fast8_t;
typedef unsigned uint_fast16_t;
typedef unsigned long uint_fast32_t;
typedef uint_least64_t uint_fast64_t;

#ifdef LLONG_MAX
typedef long long intmax_t;
#define INTMAX_C(x) x##ll
#define INTMAX_MAX LLONG_MAX
#else
typedef long intmax_t;
#define INTMAX_C(x) x##l
#define INTMAX_MAX LONG_MAX
#endif

#ifdef ULLONG_MAX
typedef unsigned long long uintmax_t;
#define UINTMAX_C(x) x##ull
#define UINTMAX_MAX ULLONG_MAX
#else
typedef unsigned long uintmax_t;
#define UINTMAX_C(x) x##ul
#define UINTMAX_MAX ULONG_MAX
#endif

#undef EXACTLY_8_BITS_S
#undef EXACTLY_16_BITS_S
#undef EXACTLY_32_BITS_S
#undef EXACTLY_64_BITS_S
#undef EXACTLY_8_BITS_U
#undef EXACTLY_16_BITS_U
#undef EXACTLY_32_BITS_U
#undef EXACTLY_64_BITS_U

#undef AT_LEAST_16_BITS_S
#undef AT_LEAST_32_BITS_S
#undef AT_LEAST_64_BITS_S
#undef AT_LEAST_16_BITS_U
#undef AT_LEAST_32_BITS_U
#undef AT_LEAST_64_BITS_U
}

#endif // CPP11
#endif // PBL_CPP_CSTDINT_H

