#include <iostream>

#include "memory.h"

cpp::unique_ptr< int > f()
{
	return cpp::unique_ptr< int >(new int(123456789));
}

void test_unique_pointer()
{
	cpp::unique_ptr< int > v = f();

	cpp::unique_ptr< int[] > w(new int[5]);

	for ( int i = 0; i < 5; ++i )
	{
		w[i] = 6 * i;
	}

	std::cout << *v << std::endl;
	std::cout << w[2] << std::endl;
}

void test_shared_pointer()
{
	cpp::shared_ptr< int > x(new int(21048204));

	cpp::shared_ptr< int > y = x;

	std::cout << *y << std::endl;
}

int main()
{
	test_unique_pointer();
	return 0;
}
