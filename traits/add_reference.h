#ifndef PBL_CPP_TRAITS_ADD_REFERENCE_H
#define PBL_CPP_TRAITS_ADD_REFERENCE_H

namespace cpp11
{

template< typename T >
struct add_lvalue_reference
{
	typedef T& type;
};

template< typename T >
struct add_lvalue_reference< T& >
{
	typedef T& type;
};

template< >
struct add_lvalue_reference< void >
{
	typedef void type;
};

template< >
struct add_lvalue_reference< const void >
{
	typedef const void type;
};

template< >
struct add_lvalue_reference< volatile void >
{
	typedef volatile void type;
};

template< >
struct add_lvalue_reference< const volatile void >
{
	typedef const volatile void type;
};

}

#endif // PBL_CPP_TRAITS_ADD_REFERENCE_H
