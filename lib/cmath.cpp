#include "cmath.h"

#ifdef PBL_CPP_CMATH_LGAMMA
namespace cpp11
{
namespace detail
{
/* Fallback implementation for lgamma, if it isn't available from environment
 *
 * See "Numerical Recipes 3e", Press et al., p 257
 */
long double lgamma_implementation(long double z)
{
	static const long double cof[14] =
	{
	        57.1562356658629235l,
	        -59.5979603554754912l,
	        14.1360979747417471l,
	        -0.491913816097620199l,
	        0.339946499848118887e-4l,
	        0.465236289270485756e-4l,
	        -0.983744753048795646e-4l,
	        0.158088703224912494e-3l,
	        -0.210264441724104883e-3l,
	        0.217439618115212643e-3l,
	        -0.164318106536763890e-3l,
	        0.844182239838527433e-4l,
	        -0.261908384015814087e-4l,
	        0.368991826595316234e-5l
	};

	long double x   = z;
	long double y   = z;
	long double tmp = x + ( 671.0L / 128 );

	tmp = ( x + 0.5 ) * std::log(tmp) - tmp;
	long double ser = 0.999999999999997092L;

	for ( std::size_t j = 0; j < 14; ++j )
	{
		y   += 1;
		ser += cof[j] / y;
	}

	return tmp + std::log(2.5066282746310005L * ser / x);
}
}
}
#endif
