/// @todo Function pointer should be implemented in terms of
/// result_of< remove_pointer<F>::type >
#ifndef PBL_CPP_TRAITS_RESULT_OF_H
#define PBL_CPP_TRAITS_RESULT_OF_H

#include "is_convertible.h"
#include "enable_if.h"

namespace cpp11
{
template< typename F, typename = void >
struct result_of;

template< typename R >
struct result_of< R(&( ))( ) >
{
	typedef R type;
};

// Can I call F=R(F1) with argument A1
template< typename R, typename F1, typename A1 >
struct result_of< R(&( A1 ))( F1 ), typename enable_if< is_convertible< A1, F1 >::value >::type >
{
	typedef R type;
};

template< typename R, typename F1, typename F2, typename A1, typename A2 >
struct result_of< R(&( A1, A2 ))( F1, F2 ), typename enable_if< is_convertible< A1, F1 >::value&& is_convertible< A2, F2 >::value >::type >
{
	typedef R type;
};

template< typename R, typename F1, typename F2, typename F3, typename A1, typename A2, typename A3 >
struct result_of< R(&( A1, A2, A3 ))( F1, F2, F3 ), typename enable_if< is_convertible< A1, F1 >::value&& is_convertible< A2, F2 >::value&& is_convertible< A3, F3 >::value >::type >
{
	typedef R type;
};

template< typename R, typename F1, typename F2, typename F3, typename F4, typename A1, typename A2, typename A3, typename A4 >
struct result_of< R(&( A1, A2, A3, A4 ))( F1, F2, F3, F4 ), typename enable_if< is_convertible< A1, F1 >::value&& is_convertible< A2, F2 >::value&& is_convertible< A3, F3 >::value&& is_convertible< A4, F4 >::value >::type >
{
	typedef R type;
};

template< typename R, typename F1, typename F2, typename F3, typename F4, typename F5, typename A1, typename A2, typename A3, typename A4, typename A5 >
struct result_of< R(&( A1, A2, A3, A4, A5 ))( F1, F2, F3, F4, F5 ), typename enable_if< is_convertible< A1, F1 >::value&& is_convertible< A2, F2 >::value&& is_convertible< A3, F3 >::value&& is_convertible< A4, F4 >::value&& is_convertible< A5, F5 >::value >::type >
{
	typedef R type;
};

template< typename R >
struct result_of< R(*( ))( ) >
{
	typedef R type;
};

// Can I call F=R(F1) with argument A1
template< typename R, typename F1, typename A1 >
struct result_of< R(*( A1 ))( F1 ), typename enable_if< is_convertible< A1, F1 >::value >::type >
{
	typedef R type;
};

template< typename R, typename F1, typename F2, typename A1, typename A2 >
struct result_of< R(*( A1, A2 ))( F1, F2 ), typename enable_if< is_convertible< A1, F1 >::value&& is_convertible< A2, F2 >::value >::type >
{
	typedef R type;
};

template< typename R, typename F1, typename F2, typename F3, typename A1, typename A2, typename A3 >
struct result_of< R(*( A1, A2, A3 ))( F1, F2, F3 ), typename enable_if< is_convertible< A1, F1 >::value&& is_convertible< A2, F2 >::value&& is_convertible< A3, F3 >::value >::type >
{
	typedef R type;
};

template< typename R, typename F1, typename F2, typename F3, typename F4, typename A1, typename A2, typename A3, typename A4 >
struct result_of< R(*( A1, A2, A3, A4 ))( F1, F2, F3, F4 ), typename enable_if< is_convertible< A1, F1 >::value&& is_convertible< A2, F2 >::value&& is_convertible< A3, F3 >::value&& is_convertible< A4, F4 >::value >::type >
{
	typedef R type;
};

template< typename R, typename F1, typename F2, typename F3, typename F4, typename F5, typename A1, typename A2, typename A3, typename A4, typename A5 >
struct result_of< R(*( A1, A2, A3, A4, A5 ))( F1, F2, F3, F4, F5 ), typename enable_if< is_convertible< A1, F1 >::value&& is_convertible< A2, F2 >::value&& is_convertible< A3, F3 >::value&& is_convertible< A4, F4 >::value&& is_convertible< A5, F5 >::value >::type >
{
	typedef R type;
};

}
#endif // PBL_CPP_TRAITS_RESULT_OF_H
