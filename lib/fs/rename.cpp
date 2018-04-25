#include "rename.h"

#include <cstdio>

#include "copyfile.h"
#include "remove.h"

namespace cpp17
{
namespace filesystem
{
/// @bug This is just a quick and dirty implementation
void rename(const path& from, const path& to)
{
	if (std::rename(from.c_str(), to.c_str()) != 0)
	{
		if (copy_file(from, to))
			cpp17::filesystem::remove(from);
	}
}
}
}

