#ifndef PBL_CPP_TRAITS_REMOVE_REFERENCE_H
#define PBL_CPP_TRAITS_REMOVE_REFERENCE_H

namespace cpp11
{
template< class T >
struct remove_reference {typedef T type;};
template< class T >
struct remove_reference< T& >{typedef T type;};
}
#endif // PBL_CPP_TRAITS_REMOVE_REFERENCE_H
