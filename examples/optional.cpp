#include <vector>
#include <iostream>
#include "optional.h"

typedef std::vector< int > test_type;

const test_type value(3, 5);

// set a value
void example1()
{
	std::cout << "Example 1" << std::endl;
	cpp::optional< test_type > y;

	if ( y )
	{
		std::cout << "y is set" << std::endl;
	}
	else
	{
		std::cout << "y is not set" << std::endl;
	}

	y = value;

	if ( y )
	{
		std::cout << "y is set" << std::endl;
		std::cout << "Size of vector is " << y->size() << std::endl;
	}
	else
	{
		std::cout << "y is not set" << std::endl;
	}

	std::cout << std::endl;
}

// clear a value
void example2()
{
	std::cout << "Example 2" << std::endl;
	cpp::optional< test_type > y(value);

	if ( y )
	{
		std::cout << "y is set" << std::endl;
	}
	else
	{
		std::cout << "y is not set" << std::endl;
	}

	y = cpp::none;

	if ( y )
	{
		std::cout << "y is set" << std::endl;
	}
	else
	{
		std::cout << "y is not set" << std::endl;
	}

	std::cout << std::endl;
}

int main()
{
	example1();
	example2();
}
