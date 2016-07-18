#include "chrono.h"

#ifndef CPP11

#include <ctime>

namespace cpp11
{
namespace chrono
{
time_point< system_clock > system_clock::now()
{
	timespec ts;

	if ( ::clock_gettime(CLOCK_REALTIME, &ts) == 0 )
	{
		#if 0
		seconds     s(ts.tv_sec);
		nanoseconds ns(ts.tv_nsec);

		return time_point(duration(s + ms));

		#else

		return time_point(duration(ts.tv_sec * 1000 + ( ts.tv_nsec / 1000000L )));

		#endif
	}

	return time_point();
}

std::time_t system_clock::to_time_t(const time_point& t)
{
	return static_cast< std::time_t >( t.time_since_epoch().count() / 1000 );
}

time_point< system_clock > system_clock::from_time_t(std::time_t t)
{
	return time_point(duration(t * 1000));
}

time_point< steady_clock > steady_clock::now()
{
	timespec ts;

	if ( ::clock_gettime(CLOCK_MONOTONIC, &ts) == 0 )
	{
		return time_point(duration(ts.tv_sec * 1000000000L + ts.tv_nsec));
	}

	return time_point();
}

}
}
#endif // ifndef CPP11
