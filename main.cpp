// trobin_ecs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <map>
#include <tuple>

#include "main.h"

#include "src/utils/MathUtils.h"

// DEBUG {
#include "tools/Logger.h"
#include "tools/Timer.h"

#include "tools/Profiler.h"
#include "tools/TstTimer.h"

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

///////////////////////////////////////////////////////
//VARIADIC TEMPLATES 3
//Typenames?: 
///////////////////////////////////////////////////////
//Template that accepts three variables of any type that can be printed
template<typename A, typename B, typename C>
void print3(A& a, B& b, C& c) {
	std::cout << "a: " << typeid(a).name() << "; "
		<< "b: " << typeid(b).name() << "; "
		<< "c: " << typeid(c).name() << "\n";
}

///////////////////////////////////////////////////////
//VARIADIC TEMPLATES 4
//total_size function: recursively total up the sizes of everything 
///////////////////////////////////////////////////////

// Edge case where printn is given no args (doesn't need template because it's receiving no args)
uint32_t total_size() {
	return 0;
}

// For the case where it's our last element.
// This must be declared before the recursive call, because once the compiler enters the recursive function,
// it only looks for specializations that have been declared up to that point.
template<typename LAST>
uint32_t total_size(LAST t) {
	return sizeof(t);
}



//printn function: take an arbitrary number of inputs, print them all
//ellipsis indicates any number of types, rest is all the remaining args
// ...T1toN means variable # of elements
// rest... means expand name to a list of all elements it represents
// T1toN ... rest means rest is a list of params given by T1toN
template<typename T0, typename ... T1toN>
uint32_t total_size(T0 t, T1toN ... rest) {
	return (sizeof(t) + total_size(rest...));
}

///////////////////////////////////////////////////////
//VARIADIC TEMPLATES 5
//size_tupe function: take a tuple of arbitraty length, return total size in bytes of all the elements
///////////////////////////////////////////////////////

template<typename TUPLE, std::size_t ... indices>
uint32_t size_tuple_impl(TUPLE t, std::index_sequence<indices...>) {
	// 
	return total_size(std::get <indices>(t)...); // printn(std::get<0>(t), std::get<1>(t), ...);
}

template<typename TUPLE>
uint32_t size_tuple(TUPLE t) {
	// Takes a tuple, returns the total size of all the elements in the tuple
	// we pass in a sequence of indices, then size_tuple_impl will run printn() for get<0..N>
	return size_tuple_impl(t, std::make_index_sequence<std::tuple_size<TUPLE>::value>{});
}


int main()
{
	printn(9, "hello");
	
	auto t = std::make_tuple(1, 4, "hello123123123123", 4.3f, 4.3f, uint16_t(12), long{}, long(1231), long(1231), long(1231), long(1231));
	print_tuple(t);


	auto u = size_tuple(t);
	printn(u);
	printn(sizeof(t));


	Vec2 cat{ 2.3,42.1 };
	std::string mouse{ "asdasd123aqweasdfgesadfse" };
	
	uint32_t bird{ 2 };

	print3(bird, cat, mouse);

	decltype(bird) cow{ 23 };
	return 0;
}
