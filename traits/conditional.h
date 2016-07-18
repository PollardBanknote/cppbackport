#ifndef PBL_CPP_TRAITS_CONDITIONAL_H
#define PBL_CPP_TRAITS_CONDITIONAL_H

namespace cpp11
{

template< bool B, class T, class F >
struct conditional {typedef T type;};

template< class T, class F >
struct conditional< false, T, F >{typedef F type;};

}

#endif // PBL_CPP_TRAITS_CONDITIONAL_H
