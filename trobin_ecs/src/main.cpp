// trobin_ecs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <map>
#include <tuple>

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

//template<typename SEARCH, typename TUPLE, size_t start_from=0>
//struct contains_type :
//	if_< //IF
//		std::is_same<std::tuple_element_t<start_from, TUPLE>, SEARCH>::value,
//		//THEN
//		https://www.youtube.com/watch?v=_yqIdYBdyPo&t=69s

bool contains_type(const std::string& SEARCH, const std::vector<std::string>& v, size_t start_from = 0) {
	if (v[start_from] == SEARCH) {
		return true;
	}
	//else {

	//}
}

int main()
{
	std::vector<std::string> t{ "int", "bool", "float" };

	return 0;
}
