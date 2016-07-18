#ifndef PBL_CPP_TRAITS_ALIGNMENT_H
#define PBL_CPP_TRAITS_ALIGNMENT_H

#include <cstddef>

namespace cpp11
{
#if !( __cplusplus >= 201103L )
template< class T >
class alignment_of
{
	struct dummy {char a;T b;};
public:
	static const std::size_t value = offsetof(dummy, b);
};
#endif

#if !( __cplusplus >= 201103L ) || ( __GLIBCXX__ < 20150422L )
template< std::size_t Len, typename T >
struct aligned_union
{
	static const std::size_t alignment_value = cpp::alignment_of< T >::value;

	// This is actually over-aligned, but since we expect to completely remove
	// this in favour of C++11, we don't really care.
	struct type
	{
		char data[Len > sizeof( T ) ? Len : sizeof( T )];
	} __attribute__(( aligned ));
};
#endif
}

/* Manually inject aligned_union into cpp namespace. Earlier versions of libstdc++
 * are missing aligned_union, even though C++11 is indicated.
 */
#if __cplusplus >= 201103L && __GLIBCXX__ < 20150422L
namespace cpp
{
using ::cpp11::aligned_union;
}
#endif

#endif // PBL_CPP_TRAITS_ALIGNMENT_H
