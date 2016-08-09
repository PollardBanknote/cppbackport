#include <iostream>
#include <ctime>

#include "chrono.h"

int main()
{
	cpp::chrono::system_clock::time_point now = cpp::chrono::system_clock::now();

	std::time_t t = cpp::chrono::system_clock::to_time_t(now);

	std::cout << std::ctime(&t) << std::endl;
}
