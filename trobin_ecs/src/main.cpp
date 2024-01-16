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


////////////////////////////////////////////
// NOTE THESE VARIADIC TEMPLATES PASS BYVAL WHICH IS INEFFICIENT. WE NEED TO IMPLEMENT PERFECT FORWARDING.


///////////////////////////////////////////////////////
//VARIADIC TEMPLATES 1
//printn function: take an arbitrary number of inputs, print them all
///////////////////////////////////////////////////////

// Edge case where printn is given no args (doesn't need template because it's receiving no args)
void printn() {
	std::cout << "\n";
}

// For the case where it's our last element.
// This must be declared before the recursive call, because once the compiler enters the recursive function,
// it only looks for specializations that have been declared up to that point.
template<typename LAST>
void printn(LAST t) {
	std::cout << t << "\n";
}



//printn function: take an arbitrary number of inputs, print them all
//ellipsis indicates any number of types, rest is all the remaining args
// ...T1toN means variable # of elements
// rest... means expand name to a list of all elements it represents
// T1toN ... rest means rest is a list of params given by T1toN
template<typename T0, typename ... T1toN>	
void printn(T0 t, T1toN ... rest) {
	std::cout << t << ", ";
	printn(rest...);
}

///////////////////////////////////////////////////////
//VARIADIC TEMPLATES 2
//print_tuple function: take a tuple of arbitraty length, print all elements
///////////////////////////////////////////////////////

template<typename TUPLE, std::size_t ... indices>
void print_tuple_impl(TUPLE t, std::index_sequence<indices...>) {
	// 
	printn(std::get <indices>(t)...); // printn(std::get<0>(t), std::get<1>(t), ...);
}

template<typename TUPLE>
void print_tuple(TUPLE t) {
	// we pass in a sequence of indices, then print_tuple_impl will run printn() for get<0..N>
	print_tuple_impl(t, std::make_index_sequence<std::tuple_size<TUPLE>::value>{});
}


int main()
{
	printn(9, "hello");
	
	auto t = std::make_tuple(1, 4, "hello", 4.3f);
	print_tuple(t);

	return 0;
}
