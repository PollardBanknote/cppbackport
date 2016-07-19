#include <iostream>
#include <string>

#include "random.h"

int main()
{
	const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cpp::default_random_engine                g;
	cpp::uniform_int_distribution< unsigned > u(0, 25);

	for ( int i = 0; i < 100; ++i )
	{
		std::cout << alphabet.at(u(g));
	}

	std::cout << std::endl;
}
