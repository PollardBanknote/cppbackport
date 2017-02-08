#include <iostream>
#include <string>
#include <vector>

#include "variant.h"

int main()
{
	cpp::variant< int, std::string > v(3);
	v = "Hello";
	std::cout << cpp::get< std::string >(v) << std::endl;
	std::cout << cpp::get< 1 >(v) << std::endl;
}
