#ifndef PBL_CPP_TRAITS_INTEGRAL_CONSTANT_H
#define PBL_CPP_TRAITS_INTEGRAL_CONSTANT_H

#ifndef CPP11
namespace cpp11
{
template< class T, T v >
struct integral_constant
{
	static const T value = v;
	typedef T value_type;
	typedef integral_constant type;

	operator value_type() const
	{
		return v;
	}

	value_type operator()() const
	{
		return v;
	}

};

typedef integral_constant< bool, true > true_type;
typedef integral_constant< bool, false > false_type;
}
#endif // ifndef CPP11

#ifndef CPP17
namespace cpp17
{
template< bool B >
struct bool_constant
	: cpp::integral_constant< bool, B >
{
};
}
#endif

#endif // PBL_CPP_TRAITS_INTEGRAL_CONSTANT_H
