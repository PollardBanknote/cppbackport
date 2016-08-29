#include <iostream>
#include "cmath.h"

int main()
{
	int q = 0;

	std::cout << cpp::remainder(5, 1.5) << std::endl;
	std::cout << cpp::remquo(5, 1.5, &q) << std::endl;
	std::cout << q << std::endl;
	std::cout << cpp::fma(3., 4., 5.) << std::endl;
	std::cout << cpp::fmax(3, 4) << std::endl;
	std::cout << cpp::fmin(3, 4) << std::endl;
	std::cout << cpp::fdim(100, 66) << std::endl;
	std::cout << cpp::exp2(3) << std::endl;
}
