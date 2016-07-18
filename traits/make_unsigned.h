#ifndef PBL_CPP_TRAITS_MAKE_UNSIGNED_H
#define PBL_CPP_TRAITS_MAKE_UNSIGNED_H

#include "config/arch.h"

namespace cpp11
{
// std::make_unsigned
template< typename T >
struct make_unsigned
{
};

template< >
struct make_unsigned< char >
{
	typedef unsigned char type;
};

template< >
struct make_unsigned< signed char >
{
	typedef unsigned char type;
};

template< >
struct make_unsigned< unsigned char >
{
	typedef unsigned char type;
};

template< >
struct make_unsigned< signed short int >
{
	typedef unsigned short int type;
};

template< >
struct make_unsigned< unsigned short int >
{
	typedef unsigned short int type;
};

template< >
struct make_unsigned< signed int >
{
	typedef unsigned int type;
};

template< >
struct make_unsigned< unsigned int >
{
	typedef unsigned int type;
};

template< >
struct make_unsigned< signed long int >
{
	typedef unsigned long int type;
};

template< >
struct make_unsigned< unsigned long int >
{
	typedef unsigned long int type;
};

#ifdef HAS_LONG_LONG
template< >
struct make_unsigned< signed long long int >
{
	typedef unsigned long long int type;
};

template< >
struct make_unsigned< unsigned long long int >
{
	typedef unsigned long long int type;
};
#endif

// const -----------------------------------------------------------------------
template< >
struct make_unsigned< const char >
{
	typedef const unsigned char type;
};

template< >
struct make_unsigned< const signed char >
{
	typedef const unsigned char type;
};

template< >
struct make_unsigned< const unsigned char >
{
	typedef const unsigned char type;
};

template< >
struct make_unsigned< const signed short int >
{
	typedef const unsigned short int type;
};

template< >
struct make_unsigned< const unsigned short int >
{
	typedef const unsigned short int type;
};

template< >
struct make_unsigned< const signed int >
{
	typedef const unsigned int type;
};

template< >
struct make_unsigned< const unsigned int >
{
	typedef const unsigned int type;
};

template< >
struct make_unsigned< const signed long int >
{
	typedef const unsigned long int type;
};

template< >
struct make_unsigned< const unsigned long int >
{
	typedef const unsigned long int type;
};

#ifdef HAS_LONG_LONG
template< >
struct make_unsigned< const signed long long int >
{
	typedef const unsigned long long int type;
};

template< >
struct make_unsigned< const unsigned long long int >
{
	typedef const unsigned long long int type;
};
#endif
// volatile --------------------------------------------------------------------
template< >
struct make_unsigned< volatile char >
{
	typedef volatile unsigned char type;
};

template< >
struct make_unsigned< volatile signed char >
{
	typedef volatile unsigned char type;
};

template< >
struct make_unsigned< volatile unsigned char >
{
	typedef volatile unsigned char type;
};

template< >
struct make_unsigned< volatile signed short int >
{
	typedef volatile unsigned short int type;
};

template< >
struct make_unsigned< volatile unsigned short int >
{
	typedef volatile unsigned short int type;
};

template< >
struct make_unsigned< volatile signed int >
{
	typedef volatile unsigned int type;
};

template< >
struct make_unsigned< volatile unsigned int >
{
	typedef volatile unsigned int type;
};

template< >
struct make_unsigned< volatile signed long int >
{
	typedef volatile unsigned long int type;
};

template< >
struct make_unsigned< volatile unsigned long int >
{
	typedef volatile unsigned long int type;
};

#ifdef HAS_LONG_LONG
template< >
struct make_unsigned< volatile signed long long int >
{
	typedef volatile unsigned long long int type;
};

template< >
struct make_unsigned< volatile unsigned long long int >
{
	typedef volatile unsigned long long int type;
};
#endif

// const volatile --------------------------------------------------------------
template< >
struct make_unsigned< const volatile char >
{
	typedef const volatile unsigned char type;
};

template< >
struct make_unsigned< const volatile signed char >
{
	typedef const volatile unsigned char type;
};

template< >
struct make_unsigned< const volatile unsigned char >
{
	typedef const volatile unsigned char type;
};

template< >
struct make_unsigned< const volatile signed short int >
{
	typedef const volatile unsigned short int type;
};

template< >
struct make_unsigned< const volatile unsigned short int >
{
	typedef const volatile unsigned short int type;
};

template< >
struct make_unsigned< const volatile signed int >
{
	typedef const volatile unsigned int type;
};

template< >
struct make_unsigned< const volatile unsigned int >
{
	typedef const volatile unsigned int type;
};

template< >
struct make_unsigned< const volatile signed long int >
{
	typedef const volatile unsigned long int type;
};

template< >
struct make_unsigned< const volatile unsigned long int >
{
	typedef const volatile unsigned long int type;
};

#ifdef HAS_LONG_LONG
template< >
struct make_unsigned< const volatile signed long long int >
{
	typedef const volatile unsigned long long int type;
};

template< >
struct make_unsigned< const volatile unsigned long long int >
{
	typedef const volatile unsigned long long int type;
};
#endif
}

#endif // PBL_CPP_TRAITS_MAKE_UNSIGNED_H
