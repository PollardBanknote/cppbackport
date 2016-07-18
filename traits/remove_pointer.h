#ifndef PBL_CPP_TRAITS_REMOVE_POINTER_H
#define PBL_CPP_TRAITS_REMOVE_POINTER_H

namespace cpp11
{
template< class T >
struct remove_pointer {typedef T type;};
template< class T >
struct remove_pointer< T* >{typedef T type;};
template< class T >
struct remove_pointer< T* const >{typedef T type;};
template< class T >
struct remove_pointer< T* volatile >{typedef T type;};
template< class T >
struct remove_pointer< T* const volatile >{typedef T type;};
}
#endif // PBL_CPP_TRAITS_REMOVE_POINTER_H
