#include <iostream>

#include "filesystem.h"
#include "iterator.h"

namespace fs = cpp::filesystem;

void print_ancestors(const fs::path& p)
{
	for (fs::path::const_iterator it = p.begin(); it != p.end(); ++it)
		std::cout << "\t" << "'" << *it << "'";
	std::cout << std::endl;
}

void print_reverse(const fs::path& p)
{
	fs::path::const_iterator first = p.begin();
	fs::path::const_iterator it = p.end();

	while (it != first)
	{
		--it;
		std::cout << "\t" << "'" << *it << "'";
	}
	std::cout << std::endl;
}

const fs::path test[] = {
        "",
        "/",
        "///",
        "/absolute",
        "/absolute/",
        "/absolute/file",
        "/absolute/dir/",
        "relative",
        "relative/",
        "relative/file",
        "relative/dir/"
};

int main()
{
	for (const fs::path* it = cpp::begin(test), *last = cpp::end(test); it != last; ++it)
	{
		std::cout << "'" << *it << "'" << std::endl;
		print_ancestors(*it);
		print_reverse(*it);
	}
}
