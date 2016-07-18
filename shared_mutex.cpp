#include "shared_mutex.h"

#include <pthread.h>

namespace cpp17
{
shared_mutex::shared_mutex()
{
	::pthread_rwlock_init(&mut, NULL);
}

shared_mutex::~shared_mutex()
{
	::pthread_rwlock_destroy(&mut);
}

void shared_mutex::lock()
{
	::pthread_rwlock_wrlock(&mut);
}

bool shared_mutex::try_lock()
{
	return ::pthread_rwlock_trywrlock(&mut) == 0;
}

void shared_mutex::unlock()
{
	::pthread_rwlock_unlock(&mut);
}

void shared_mutex::lock_shared()
{
	::pthread_rwlock_rdlock(&mut);
}

bool shared_mutex::try_lock_shared()
{
	return ::pthread_rwlock_tryrdlock(&mut) == 0;
}

void shared_mutex::unlock_shared()
{
	::pthread_rwlock_unlock(&mut);
}

shared_mutex::native_handle_type shared_mutex::native_handle()
{
	return &mut;
}

}
