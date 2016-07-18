/** @file cstdint.h
 * @brief Implementation of C++11 cstdint header
 *
 * @todo Supply stdint.h ourselves via templates
 */
#ifndef PBL_CPP_CSTDINT_H
#define PBL_CPP_CSTDINT_H

#include "version.h"

#ifdef CPP11
// Provided by C++11
#include <cstdint>
#define PBL_STDINT_H
#else
#if !defined( _WIN32 ) && ( defined( __unix__ ) || defined( __unix ) || ( defined( __APPLE__ ) && defined( __MACH__ )))
#include <unistd.h>
#if ( _POSIX_C_SOURCE >= 200112L )
// Provided by POSIX
#include <stdint.h>
#define PBL_STDINT_H
namespace cpp11
{
using ::int8_t;
using ::int16_t;
using ::int32_t;
using ::int64_t;
using ::uint8_t;
using ::uint16_t;
using ::uint32_t;
using ::uint64_t;
using ::int_least8_t;
using ::int_least16_t;
using ::int_least32_t;
using ::int_least64_t;
using ::uint_least8_t;
using ::uint_least16_t;
using ::uint_least32_t;
using ::uint_least64_t;
using ::int_fast8_t;
using ::int_fast16_t;
using ::int_fast32_t;
using ::int_fast64_t;
using ::uint_fast8_t;
using ::uint_fast16_t;
using ::uint_fast32_t;
using ::uint_fast64_t;
using ::intptr_t;
using ::uintptr_t;
using ::intmax_t;
using ::uintmax_t;
}

#endif // if ( _POSIX_C_SOURCE >= 200112L )
#endif // if !defined( _WIN32 ) && ( defined( __unix__ ) || defined( __unix ) || ( defined( __APPLE__ ) && defined( __MACH__ )))
#endif // ifdef CPP11

#ifndef PBL_STDINT_H
#ifdef __GLIBC__
#if ( __GLIBC__ > 2 || ( __GLIBC__ == 2 && __GLIBC_MINOR__ >= 1 ))
// Provided by glibc
#include <stdint.h>
#define PBL_STDINT_H
#endif
#endif
#endif

#ifndef PBL_STDINT_H
#include <climits>

/* This implementation isn't quite right... but it's close enough
 */
namespace cpp11
{
namespace detail
{
template< typename T >
struct larger;

template< >
struct larger< signed char >
{
	typedef short int value_type;
};

template< >
struct larger< short int >
{
	typedef int value_type;
};

template< >
struct larger< int >
{
	typedef long int value_type;
};

#ifdef HAS_LONG_LONG
template< >
struct larger< long int >
{
	typedef long long int value_type;
};
#endif

template< >
struct larger< unsigned char >
{
	typedef unsigned short value_type;
};

template< >
struct larger< unsigned short >
{
	typedef unsigned value_type;
};

template< >
struct larger< unsigned >
{
	typedef unsigned long value_type;
};

#ifdef HAS_LONG_LONG
template< >
struct larger< unsigned long >
{
	typedef unsigned long long value_type;
};
#endif

template< typename T, unsigned N, bool = ( N <= ( sizeof( T )* CHAR_BIT )) >
struct at_least;

template< typename T, unsigned N >
struct at_least< T, N, true >
{
	typedef T value_type;
};

template< typename T, unsigned N >
struct at_least< T, N, false >
{
	typedef typename at_least< typename larger< T >::value_type, N >::value_type value_type;
};

template< typename T, unsigned N, bool = (( sizeof( T )* CHAR_BIT ) == N ) >
struct exactly;

template< typename T, unsigned N >
struct exactly< T, N, true >
{
	typedef T value_type;
};

template< typename T, unsigned N >
struct exactly< T, N, false >
{
	typedef void value_type;
};
}

typedef detail::at_least< unsigned char, 8 >::value_type uint_least8_t;
typedef detail::at_least< uint_least8_t, 16 >::value_type uint_least16_t;
typedef detail::at_least< uint_least16_t, 32 >::value_type uint_least32_t;
#ifdef HAS_LONG_LONG
typedef detail::at_least< uint_least32_t, 64 >::value_type uint_least64_t;
#endif

typedef detail::at_least< signed char, 8 >::value_type int_least8_t;
typedef detail::at_least< int_least8_t, 16 >::value_type int_least16_t;
typedef detail::at_least< int_least16_t, 32 >::value_type int_least32_t;
#ifdef HAS_LONG_LONG
typedef detail::at_least< int_least32_t, 64 >::value_type int_least64_t;
#endif

typedef uint_least8_t uint_fast8_t;
typedef uint_least16_t uint_fast16_t;
typedef uint_least32_t uint_fast32_t;
#ifdef HAS_LONG_LONG
typedef uint_least64_t uint_fast64_t;
#endif

typedef int_least8_t int_fast8_t;
typedef int_least16_t int_fast16_t;
typedef int_least32_t int_fast32_t;
#ifdef HAS_LONG_LONG
typedef int_least64_t int_fast64_t;
#endif

typedef detail::exactly< uint_least8_t, 8 >::value_type uint8_t;
typedef detail::exactly< uint_least16_t, 16 >::value_type uint16_t;
typedef detail::exactly< uint_least32_t, 32 >::value_type uint32_t;
#ifdef HAS_LONG_LONG
typedef detail::exactly< uint_least64_t, 64 >::value_type uint64_t;
#endif

typedef detail::exactly< int_least8_t, 8 >::value_type int8_t;
typedef detail::exactly< int_least16_t, 16 >::value_type int16_t;
typedef detail::exactly< int_least32_t, 32 >::value_type int32_t;
#ifdef HAS_LONG_LONG
typedef detail::exactly< int_least64_t, 64 >::value_type int64_t;
#endif

#ifdef HAS_LONG_LONG
typedef long long int intmax_t;
typedef unsigned long long uintmax_t;
#else
typedef long int intmax_t;
typedef unsigned long uintmax_t;
#endif
}
#else
#undef PBL_STDINT_H
#endif // ifndef PBL_STDINT_H


#endif // PBL_CPP_CSTDINT_H
