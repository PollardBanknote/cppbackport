#ifndef PBL_CPP_TRAITS_ENABLE_IF_H
#define PBL_CPP_TRAITS_ENABLE_IF_H

namespace cpp11
{
template< bool B, class T = void >
struct enable_if {};

template< class T >
struct enable_if< true, T >
{
	typedef T type;
};
}

#endif // PBL_CPP_TRAITS_ENABLE_IF_H
