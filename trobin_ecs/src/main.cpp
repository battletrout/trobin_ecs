// trobin_ecs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <map>


#include "main.h"
#include "engine/Logger.h"
#include "engine/Timer.h"

// DEBUG {


#include "engine/Profiler.h"
#include "test/TstTimer.h"

// } DEBUG

//Practice {
#include <type_traits>
//#include "practice/MemoryPool.h"

#include <array>
// } Practice

//using namespace std;

/*
//When multiple specializations are provided, the most specific one is chosen
template<typename KEY, typename DATA>
struct Qmap {
	//default implementation
	Qmap() { std::cout << "Qmap default\n"; }

	
		Qmap(KEY a, DATA b)
	{
		std::cout << "Qmap default\n";
	}


};

template<typename DATA>
struct Qmap<int, DATA> {
	Qmap(int a, DATA b) {
		std::cout << typename(KEY) << " " << KEY << "; "
			<< typename(DATA) << " " << DATA
	}
};
	auto default_ = Qmap<int, bool>{};
	auto default1 = Qmap{ 5, 3 };
*/

template<typename A, typename B, typename C>
void print3(A a, B b, C c) {
	std::cout << "a: " << a << "; "
		<< "b: " << b << "; "
		<< "c: " << c << "\n";
}

int main()
{
	//PROFILE_FUNCTION();
	
	print3(1, 2, 3);
	std::string hello = "catbird";
	print3(hello, 4, hello);
;

	return 0;
}
