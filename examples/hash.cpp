#include <iostream>
#include <string>
#include "unordered_set.h"
#include "unordered_map.h"

int main()
{
	cpp::unordered_set< int > h;

	h.insert(1);
	h.insert(99);

	for ( cpp::unordered_set< int >::iterator it = h.begin(); it != h.end(); ++it )
	{
		std::cout << *it << std::endl;
	}

	cpp::unordered_map< int, std::string > m;
	m[3] = "Hello";

	for ( cpp::unordered_map< int, std::string >::iterator it = m.begin(); it != m.end(); ++it )
	{
		std::cout << it->first << "," << it->second << std::endl;
	}
}
