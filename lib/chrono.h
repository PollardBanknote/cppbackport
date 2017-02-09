/* Copyright (c) 2016, Pollard Banknote Limited
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.

   3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef PBL_CPP_CHRONO_H
#define PBL_CPP_CHRONO_H

#include "version.h"

#ifdef CPP11
#include <chrono>
#else
#include <ctime>
#include "ratio.h"
#include "traits/common_type.h"

namespace cpp11
{
namespace detail
{
template< typename Period1, typename Period2 >
struct duration_cast_helper
{
	static const cpp::intmax_t d1 = cpp11::detail::gcd< Period1::num, Period2::num >::value;
	static const cpp::intmax_t d2 = cpp11::detail::gcd< Period1::den, Period2::den >::value;

	static const cpp::intmax_t p = ( Period1::num / d1 ) * ( Period2::den / d2 );
	static const cpp::intmax_t q = ( Period2::num / d1 ) * ( Period1::den / d2 );
};

}
namespace chrono
{
template< class Rep, class Period = cpp11::ratio< 1 > >
class duration
{
public:
	typedef Rep rep;
	typedef Period period;

	duration()
		: r(0)
	{
	}

	template< typename Rep2 >
	explicit duration(const Rep2& r_)
		: r(r_)
	{
	}

	template< typename Rep2, typename Period2 >
	explicit duration(const duration< Rep2, Period2 >& d)
	{
		typedef detail::duration_cast_helper< Period, Period2 > Helper;

		r = d.count() * Helper::q / Helper::p;
	}

	rep count() const
	{
		return r;
	}

private:
	rep r;
};
}

// Specialization of common_type for durations
template< typename Rep1, typename Period1, typename Rep2, typename Period2 >
struct common_type< chrono::duration< Rep1, Period1 >, chrono::duration< Rep2, Period2 > >
{
	typedef chrono::duration< typename common_type< Rep1, Rep2 >::type,
	                          ratio< detail::gcd< Period1::num, Period2::num >::value, detail::lcm< Period1::den, Period2::den >::value > > type;
};

template< typename Rep, typename Period >
struct common_type< chrono::duration< Rep, Period >, chrono::duration< Rep, Period > >
{
	typedef chrono::duration< Rep, Period > type;
};

namespace chrono
{
template< class Rep1, class Period1, class Rep2, class Period2 >
typename common_type< duration< Rep1, Period1 >, duration< Rep2, Period2 > >::type operator+(
	const duration< Rep1, Period1 >& a,
	const duration< Rep2, Period2 >& b
)
{
	typedef typename common_type< duration< Rep1, Period1 >, duration< Rep2, Period2 > >::type Duration3;

	return Duration3(Duration3(a).count() + Duration3(b).count());
}

template< class Rep1, class Period1, class Rep2, class Period2 >
typename common_type< duration< Rep1, Period1 >, duration< Rep2, Period2 > >::type operator-(
	const duration< Rep1, Period1 >& a,
	const duration< Rep2, Period2 >& b
)
{
	typedef typename common_type< duration< Rep1, Period1 >, duration< Rep2, Period2 > >::type Duration3;

	return Duration3(Duration3(a).count() - Duration3(b).count());
}

template< class Rep1, class Period1, class Rep2, class Period2 >
bool operator<(
	const duration< Rep1, Period1 >& a,
	const duration< Rep2, Period2 >& b
)
{
	typedef typename common_type< duration< Rep1, Period1 >, duration< Rep2, Period2 > >::type Duration3;

	return Duration3(a).count() < Duration3(b).count();
}

template< class Rep1, class Period1, class Rep2, class Period2 >
bool operator>(
	const duration< Rep1, Period1 >& a,
	const duration< Rep2, Period2 >& b
)
{
	typedef typename common_type< duration< Rep1, Period1 >, duration< Rep2, Period2 > >::type Duration3;

	return Duration3(a).count() > Duration3(b).count();
}

typedef duration< long long, cpp11::nano > nanoseconds;
typedef duration< long long, cpp11::micro > microseconds;
typedef duration< long long, cpp11::milli > milliseconds;
typedef duration< long long > seconds;
typedef duration< long, cpp11::ratio< 60 > > minutes;
typedef duration< long, cpp11::ratio< 3600 > > hours;

template< typename To, class Rep, class Period >
To duration_cast(const duration< Rep, Period >& d)
{
	typedef detail::duration_cast_helper< typename To::period, Period > Helper;

	return To(d.count() * Helper::q / Helper::p);
}

template< typename Clock, typename Duration = typename Clock::duration >
class time_point
{
public:
	typedef Clock clock;
	typedef Duration duration;
	typedef typename Duration::rep rep;
	typedef typename Duration::period period;

	time_point()
		: d()
	{
	}

	explicit time_point(const duration& d_)
		: d(d_)
	{
	}

	duration time_since_epoch() const
	{
		return d;
	}

	friend duration operator-(
		const time_point& t1,
		const time_point& t2
	)
	{
		return t1.d - t2.d;
	}

private:
	duration d;
};

// wall time, millisecond resolution
class system_clock
{
public:
	typedef milliseconds duration;
	typedef duration::rep rep;
	typedef duration::period period;
	typedef cpp11::chrono::time_point< system_clock > time_point;

	static time_point now();

	static std::time_t to_time_t(const time_point&);
	static time_point from_time_t(std::time_t);
private:
};

// monotonic, nanosecond resolution
class steady_clock
{
public:
	typedef nanoseconds duration;
	typedef duration::rep rep;
	typedef duration::period period;
	typedef cpp::chrono::time_point< steady_clock > time_point;

	static time_point now();
};

typedef steady_clock high_resolution_clock;
}
}
#endif // ifndef CPP11
#endif // PBL_CPP_CHRONO_H
