// trobin_ecs.cpp : Defines the entry point for the application.
//

#include "main.h"

using namespace std;

struct cat {
	uint32_t meow{ 0 };

};

int main()
{
	uint32_t cat{ 0b1111'1111'1111'1111'1111'1111'1111'1111 };
	uint32_t dog{ 0b1111'1111'1111'1111'1111'1111'1111'1110 };

	const uint32_t result = cat ^ dog;

	cout << result << endl;
	return 0;
}
