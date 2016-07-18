#ifndef PBL_CPP_TRAITS_REMOVE_EXTENT_H
#define PBL_CPP_TRAITS_REMOVE_EXTENT_H

namespace cpp11
{
template< class T >
struct remove_extent {typedef T type;};

template< class T >
struct remove_extent< T[] >{typedef T type;};

template< class T, std::size_t N >
struct remove_extent< T[N] >{typedef T type;};

template< class T >
struct remove_all_extents {typedef T type;};

template< class T >
struct remove_all_extents< T[] >
{
	typedef typename remove_all_extents< T >::type type;
};

template< class T, std::size_t N >
struct remove_all_extents< T[N] >
{
	typedef typename remove_all_extents< T >::type type;
};
}
#endif // PBL_CPP_TRAITS_REMOVE_EXTENT_H
