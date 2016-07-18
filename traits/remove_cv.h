#ifndef PBL_CPP_TRAITS_REMOVE_CV_H
#define PBL_CPP_TRAITS_REMOVE_CV_H

namespace cpp11
{
template< class T >
struct remove_const {typedef T type;};
template< class T >
struct remove_const< const T >{typedef T type;};

template< class T >
struct remove_volatile {typedef T type;};
template< class T >
struct remove_volatile< volatile T >{typedef T type;};

template< class T >
struct remove_cv
{
	typedef typename remove_volatile< typename remove_const< T >::type >::type type;
};

}
#endif // PBL_CPP_TRAITS_REMOVE_CV_H
