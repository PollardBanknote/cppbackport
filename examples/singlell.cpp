#include <iostream>
#include <cstdlib>
#include <climits>
#include <stdexcept>
#include "forward_list.h"

int main()
{
	cpp::forward_list< int > list;

	for ( int i = 0; i < 100; ++i )
	{
		list.push_front(rand());
	}

	list.sort();
	list.reverse();

	for ( cpp::forward_list< int >::iterator it = list.begin(); it != list.end(); ++it )
	{
		std::cout << *it << std::endl;
	}
}
