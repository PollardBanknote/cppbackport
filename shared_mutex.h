#ifndef PBL_CPP_SHARED_MUTEX
#define PBL_CPP_SHARED_MUTEX

#include "version.h"

#ifdef CPP17
#include <shared_mutex>
#else
#include "os.h"
#include "mutex.h"

namespace cpp17
{
/** @todo See N3569 re: upgrade_mutex. Also https://github.com/HowardHinnant/upgrade_mutex
 * has a public domain implementation
 */
class shared_mutex
{
public:
	typedef ::pbl::os::shared_mutex_type* native_handle_type;

	shared_mutex();
	~shared_mutex();

	void lock();
	bool try_lock();
	void unlock();

	void lock_shared();
	bool try_lock_shared();
	void unlock_shared();

	native_handle_type native_handle();
private:
	shared_mutex(const shared_mutex&);
	shared_mutex& operator=(const shared_mutex&);

	::pbl::os::shared_mutex_type mut;
};

template< class Mutex >
class shared_lock
{
public:
	typedef Mutex mutex_type;

	shared_lock()
		: pm(0), owns(false)
	{
	}

	explicit shared_lock(mutex_type& m)
		: pm(&m), owns(true)
	{
		m.lock_shared();
	}

	shared_lock(
		mutex_type& m,
		cpp::defer_lock_t
	)
		: pm(&m), owns(false)
	{
	}

	shared_lock(
		mutex_type& m,
		cpp::try_to_lock_t
	)
		: pm(&m), owns(m.try_lock_shared())
	{
	}

	shared_lock(
		mutex_type& m,
		cpp::adopt_lock_t
	)
		: pm(&m), owns(true)
	{
	}

	~shared_lock()
	{
		if ( owns )
		{
			pm->unlock_shared();
		}
	}

	void lock()
	{
		if ( pm )
		{
			pm->lock_shared();
			owns = true;
		}
	}

	bool try_lock()
	{
		if ( pm )
		{
			owns = pm->try_lock_shared();
		}

		return owns;
	}

	void unlock()
	{
		if ( pm && owns )
		{
			pm->unlock_shared();
		}

		owns = false;
	}

	void swap(shared_lock& m)
	{
		std::swap(owns, m.owns);
		std::swap(pm, m.pm);
	}

	bool owns_lock() const
	{
		return owns;
	}

	mutex_type* mutex() const
	{
		return pm;
	}

private:
	shared_lock(const shared_lock&);            // non-copyable
	shared_lock& operator=(const shared_lock&); // non-copyable

	mutex_type* pm;
	bool        owns;
};

}
#endif // ifdef CPP17

#endif // SHARED_MUTEX
