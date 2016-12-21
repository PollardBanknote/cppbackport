#include <iostream>

#include "filesystem.h"

namespace fs = cpp::filesystem;

int main()
{
	typedef fs::recursive_directory_iterator iterator;
	// typedef fs::directory_iterator iterator;

	// List all files in the working directory
	for ( iterator it("."), last; it != last; ++it )
	{
		const std::string r = it->path();
		const fs::path    s = fs::absolute(r);

		std::cout << "Relative path:\t" << r << std::endl;
		std::cout << it->status() << std::endl;
		std::cout << "Absolute path:\t" << s << std::endl;
		std::cout << "Basename:     \t" << s.filename() << std::endl;
		std::cout << "Dirname:      \t" << s.parent_path() << std::endl;
		std::cout << "Simplified:   \t" << fs::cleanpath(s) << std::endl;

		std::cout << std::endl;
	}
}
