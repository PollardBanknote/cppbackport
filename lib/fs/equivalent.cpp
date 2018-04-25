#include "equivalent.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

namespace cpp17
{
namespace filesystem
{
bool equivalent(
	const path& p1,
	const path& p2
)
{
	struct stat s1;

	if ( ::stat(p1.c_str(), &s1) == 0 )
	{
		struct stat s2;

		if ( ::stat(p2.c_str(), &s2) == 0 )
		{
			return s1.st_ino == s2.st_ino && s1.st_dev == s2.st_dev;
		}
	}

	return false;
}

}
}
