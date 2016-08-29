#include <iostream>
#include <string>
#include <map>

#include "random.h"

int main()
{
	std::map< int, int > hist;

	cpp::random_device rd;
	cpp::mt19937       gen(rd());

	cpp::uniform_int_distribution< int > dist(0, 9);

	for ( int n = 0; n < 20000; ++n )
	{
		++hist[dist(gen)];
	}

	for ( std::map< int, int >::const_iterator it = hist.begin(); it != hist.end(); ++it )
	{
		std::cout << it->first << " : " << std::string(it->second / 100, '*') << '\n';
	}
}
