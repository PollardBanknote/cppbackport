/* Allocate raw storage for a type
 */
#include <iostream>
#include "type_traits.h"

// A POD with high alignment
union maxalign
{
	unsigned long long x;
	long double y;
	void* z;
};

// a type that has 16 byte alignment
typedef int v4si __attribute__(( vector_size(16)));

int main()
{
	// The type we are checking
	typedef int test_type;

	// Various ways to check alignment.
	std::cout << "Alignment" << std::endl;

	// The GCC way. Non-portable, but definitive
	std::cout << "GCC:           " << __alignof__(test_type) << std::endl;

	// Our implementation of C++11's alignment_of
	std::cout << "alignment_of:  " << cpp::alignment_of< test_type >::value << std::endl;

	// Our implementaiton of C++11's aligned_union
	std::cout << "aligned_union: " << __alignof__(cpp::aligned_union< 1, test_type >::type) << std::endl;
	std::cout << std::endl;

	std::cout << "sizeof" << std::endl;
	std::cout << "type:        " << sizeof( test_type ) << std::endl;
	std::cout << "raw storage: " << sizeof( cpp::aligned_union< 1, test_type >::type ) << std::endl;

}
