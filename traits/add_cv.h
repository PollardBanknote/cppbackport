#ifndef PBL_CPP_TRAITS_ADD_CV_H
#define PBL_CPP_TRAITS_ADD_CV_H

namespace cpp11
{
template< class T >
struct add_const {typedef const T type;};

template< class T >
struct add_volatile {typedef volatile T type;};

template< class T >
struct add_cv
{
	typedef typename add_volatile< typename add_const< T >::type >::type type;
};

}

#endif // PBL_CPP_TRAITS_ADD_CV_H
