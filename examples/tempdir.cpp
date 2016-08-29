#include <iostream>
#include "filesystem.h"

int main()
{
	std::cout << cpp::filesystem::temp_directory_path() << std::endl;
}
