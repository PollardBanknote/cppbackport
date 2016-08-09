#include <iostream>
#include <string>

#include "thread.h"

void f(const std::string& s)
{
	for ( int i = 0; i < 10; ++i )
	{
		std::cout << ( s + "\n" );
		cpp::this_thread::sleep_for(cpp::chrono::milliseconds(10));
	}
}

int main()
{
	std::string a = "Thread 1";
	std::string b = "Thread 2";

	cpp::thread t1(f, a);
	cpp::thread t2(f, b);
	t1.join();
	t2.join();
}
