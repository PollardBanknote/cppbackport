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
#ifndef PBL_CPP_CHRONO
#define PBL_CPP_CHRONO

#include "version.h"

#ifdef CPP11
#include <chrono>
#else
#include <ctime>
#include "ratio.h"

namespace cpp11
{
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

	rep count() const
	{
		return r;
	}

private:
	rep r;
};

template< class Duration >
Duration operator-(
	const Duration& a,
	const Duration  b
)
{
	return Duration(a.count() - b.count());
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
	typedef typename To::period ToPeriod;

	const cpp::intmax_t d1 = cpp11::detail::gcd< ToPeriod::num, Period::num >::value;
	const cpp::intmax_t d2 = cpp11::detail::gcd< ToPeriod::den, Period::den >::value;

	const cpp::intmax_t p = ( ToPeriod::num / d1 ) * ( Period::den / d2 );
	const cpp::intmax_t q = ( Period::num / d1 ) * ( ToPeriod::den / d2 );

	return To(d.count() * q / p);
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
#endif // PBL_CPP_CHRONO
