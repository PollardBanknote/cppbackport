#ifndef PBL_CPP_LOCALE_H
#define PBL_CPP_LOCALE_H

#include <locale>

#if __cplusplus < 201103L || __GLIBCXX__ < 20150422L

#include <cctype>

namespace cpp11
{
template< typename Char >
bool isblank(Char, const std::locale & l);

template< >
inline bool isblank< char >(
	char c,
	const std::locale&
)
{
	return ::isblank(c);
}

template< >
inline bool isblank< wchar_t >(
	wchar_t c,
	const std::locale&
)
{
	return ::iswblank(c);
}

}

#endif // ifndef CPP11

/* Manually inject isblank into cpp namespace. Earlier versions of libstdc++
 * are missing isblank, even though C++11 is indicated.
 */
#if __cplusplus >= 201103L && __GLIBCXX__ < 20150422L
namespace cpp
{
using ::cpp11::isblank;
}
#endif

#endif // PBL_CPP_LOCALE_H
