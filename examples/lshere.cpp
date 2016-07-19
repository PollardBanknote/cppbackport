#include <iostream>

#include "filesystem.h"

namespace fs = cpp::filesystem;

int main()
{
	fs::path here = fs::current_path();

	for ( fs::directory_iterator it(here), last; it != last; ++it )
	{
		std::cout << it->filename() << std::endl;
	}
}
