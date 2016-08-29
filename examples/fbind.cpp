#include <iostream>
#include <string>
#include "functional.h"

class Foo
{
public:
	explicit Foo(const std::string& s_)
		: s(s_)
	{
	}

	void hello() const
	{
		std::cout << "My name is " << s << std::endl;
	}

private:
	std::string s;
};

int main()
{
	Foo foo("herpderp");
	::cpp::function< void() > f = ::cpp::bind(&Foo::hello, &foo);

	foo = Foo("new guy");
	f();
}
