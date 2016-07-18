#include "random.h"

#ifndef CPP11
#include <stdexcept>
#include <climits>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace cpp11
{
random_device::random_device()
	: fd(-1)
{
	fd = ::open("/dev/urandom", O_RDONLY);
}

random_device::result_type random_device::operator()()
{
	if ( fd != -1 )
	{
		char buf[sizeof( result_type )];

		if ( ::read(fd, buf, sizeof( buf )) == sizeof( result_type ))
		{
			result_type x = 0;

			for ( std::size_t i = 0; i < sizeof( result_type ); ++i )
			{
				x += static_cast< result_type >( static_cast< unsigned char >( buf[i] )) << ( i * CHAR_BIT );
			}

			return x;
		}
	}

	throw std::runtime_error("Random device not available");
}

}
#endif // ifndef CPP11
