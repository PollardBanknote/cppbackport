#include <iostream>
#include <string>
#include <vector>

#include "variant.h"

int main()
{
	cpp::variant< int, std::string > v(3);
	v = "Hello";
	std::cout << v.index() << std::endl;
}
