#include "chrono.h"

#include <iostream>

int main()
{
	std::time_t t = cpp::chrono::system_clock::to_time_t(cpp::chrono::system_clock::now());

	std::cout << std::ctime(&t) << std::endl;
}
