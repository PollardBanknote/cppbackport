#ifndef PBL_CPP_CONDITION_VARIABLE_H
#define PBL_CPP_CONDITION_VARIABLE_H

#include "version.h"

#ifdef CPP11
#include <condition_variable>
#else
#include "chrono.h"
#include "os.h"
#include "mutex.h"

namespace cpp11
{
namespace cv_status
{
enum cv_status {no_timeout, timeout};
}

class condition_variable
{
public:
	typedef ::pbl::os::condition_variable_type* native_handle_type;
	condition_variable();
	~condition_variable();
	void notify_one();
	void notify_all();
	void wait(unique_lock< mutex >&);
	native_handle_type native_handle();

	template< class Duration >
	cv_status::cv_status wait_for(
		unique_lock< mutex >& l,
		const Duration&       dt
	)
	{
		chrono::system_clock::time_point t = chrono::system_clock::now();

		t += chrono::duration_cast< chrono::system_clock::duration >(dt);

		return wait_until(l, t);
	}

	cv_status::cv_status wait_until(unique_lock< mutex >&, const chrono::system_clock::time_point&);
private:
	condition_variable(const condition_variable&);
	condition_variable& operator=(const condition_variable&);

	::pbl::os::condition_variable_type cond;
};

}

#endif // ifdef CPP11

#endif // PBL_CPP_CONDITION_VARIABLE_H
