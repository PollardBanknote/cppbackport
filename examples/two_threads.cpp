// g++ -I.. thread.cpp ../cpp/thread.cpp -lpthread
#include <iostream>

#include "thread.h"

void f()
{
	for ( int i = 0; i < 1000; ++i )
	{
		std::cout << "Thread 2: " << i << std::endl;
	}
}

int main()
{
	cpp::thread t1(f);

	for ( int i = 0; i < 1000; ++i )
	{
		std::cout << "Thread main: " << i << std::endl;
	}

	t1.join();
}
