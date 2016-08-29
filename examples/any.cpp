#include <iostream>
#include "any.h"

int main()
{
	cpp::any x;

	x = 3;

	std::cout << "Get value out of an any: " << cpp::any_cast< int >(x) << std::endl;
	std::cout << std::endl;

	std::cout << "Get a pointer to the stored value: " << cpp::any_cast< int >(&x) << std::endl;
	std::cout << std::endl;

	std::cout << "Cause a bad cast" << std::endl;
	try
	{
		std::cout << cpp::any_cast< float >(x) << std::endl;
	}
	catch ( cpp::bad_any_cast& e )
	{
		std::cerr << "Error converting 'any' to type: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	x.reset();
	std::cout << "Get a pointer to a cleared value: " << cpp::any_cast< int >(&x) << std::endl;
	std::cout << std::endl;
}
