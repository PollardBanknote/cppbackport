#include "condition_variable.h"

#ifndef CPP11

namespace cpp11
{
condition_variable::condition_variable()
{
	pthread_cond_init(&cond, 0);
}

condition_variable::~condition_variable()
{
	pthread_cond_destroy(&cond);
}

void condition_variable::notify_one()
{
	pthread_cond_signal(&cond);
}

void condition_variable::notify_all()
{
	pthread_cond_broadcast(&cond);
}

void condition_variable::wait(unique_lock< mutex >& lock)
{
	pthread_cond_wait(&cond, lock.mutex()->native_handle());
}

condition_variable::native_handle_type condition_variable::native_handle()
{
	return &cond;
}

cv_status::cv_status condition_variable::wait_until(
	unique_lock< mutex >&                   lock,
	const chrono::system_clock::time_point& tp
)
{
	timespec ts;

	chrono::nanoseconds      d     = chrono::duration_cast< chrono::nanoseconds >(tp.time_since_epoch());
	chrono::nanoseconds::rep r     = d.count();
	long                     scale = 1000000000L;

	ts.tv_sec  = r / scale;
	ts.tv_nsec = r % scale;

	if ( pthread_cond_timedwait(&cond, lock.mutex()->native_handle(), &ts) == 0 )
	{
		return cv_status::no_timeout;
	}

	return cv_status::timeout;
}

}

#endif // ifndef CPP11
