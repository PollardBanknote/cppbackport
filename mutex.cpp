#include "mutex.h"

#ifndef CPP11

#include <stdexcept>

namespace cpp11
{

#ifdef POSIX_THREADS

mutex::mutex()
{
	int r = pthread_mutex_init(&mut, 0);

	if ( r != 0 )
	{
		throw std::runtime_error("Could not construct POSIX mutex.");
	}
}

mutex::~mutex()
{
	pthread_mutex_destroy(&mut);
}

void mutex::lock()
{
	pthread_mutex_lock(&mut);
}

void mutex::unlock()
{
	pthread_mutex_unlock(&mut);
}

bool mutex::trylock()
{
	return pthread_mutex_trylock(&mut) == 0;
}

mutex::native_handle_type mutex::native_handle()
{
	return &mut;
}

#elif defined( OS_WINDOWS )

mutex::mutex()
{
	InitializeCriticalSection(&mut);
}

mutex::~mutex()
{
	DeleteCriticalSection(&mut);
}

void mutex::lock()
{
	EnterCriticalSection(&mut);
}

void mutex::unlock()
{
	LeaveCriticalSection(&mut);
}

bool mutex::trylock()
{
	return TryEnterCriticalSection(&mut);
}

mutex::native_handle_type mutex::native_handle()
{
	return &mut;
}

#endif // ifdef POSIX_THREADS
}
#endif // ifndef CPP11
