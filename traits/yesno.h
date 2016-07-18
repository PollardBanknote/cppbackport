#ifndef PBL_CPP_TRAITS_YESNO_H
#define PBL_CPP_TRAITS_YESNO_H

namespace cpp11
{
namespace detail
{
typedef char (& yes)[1];
typedef char (& no)[2];
}
}

#endif // PBL_CPP_TRAITS_YESNO_H
