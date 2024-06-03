#pragma once

#include <iostream>
#include <map>
#include <tuple>

#include "ecs/utils/MathUtils.h"

// DEBUG {

// } DEBUG

/*
Define MetaTemplates that will be used to generate archetypes 
6-3-24: should I use a unique pointer to each Archetype Block? https://studiofreya.com/cpp/cpp-variadic-templates/#Variadic-templates



*/



////////////////////////////////////////////
// NOTE THESE VARIADIC TEMPLATES PASS BYVAL WHICH IS INEFFICIENT. WE NEED TO IMPLEMENT PERFECT FORWARDING.

template<typename COMPONENTS_TUPLE, size_t SIZE>
class Archetype {

public:
	template <typename COMPONENTS_TUPLE, size_t MAX_SIZE>
	inline Archetype<typename COMPONENTS_TUPLE, size_t MAX_SIZE>::Archetype(COMPONENTS_TUPLE, size_t cat)
	{
		max_size = Archetype::size_tuple(COMPONENTS_TUPLE);
		std::cout << max_size << "\n";
	}



private:

	size_t max_size;

	// Edge case where printn is given no args (doesn't need template because it's receiving no args)
	size_t total_size() {
		return 0;
	}

	// For the case where it's our last element.
	// This must be declared before the recursive call, because once the compiler enters the recursive function,
	// it only looks for specializations that have been declared up to that point.
	template<typename LAST>
	size_t total_size(LAST t) {
		return sizeof(t);
	}



	//printn function: take an arbitrary number of inputs, print them all
	//ellipsis indicates any number of types, rest is all the remaining args
	// ...T1toN means variable # of elements
	// rest... means expand name to a list of all elements it represents
	// T1toN ... rest means rest is a list of params given by T1toN
	template<typename T0, typename ... T1toN>
	size_t total_size(T0 t, T1toN ... rest) {
		return (sizeof(t) + total_size(rest...));
	}

	///////////////////////////////////////////////////////
	//VARIADIC TEMPLATES 5
	//size_tupe function: take a tuple of arbitraty length, return total size in bytes of all the elements
	///////////////////////////////////////////////////////

	template<typename TUPLE, std::size_t ... indices>
	size_t size_tuple_impl(TUPLE t, std::index_sequence<indices...>) {
		// 
		return total_size(std::get <indices>(t)...); // printn(std::get<0>(t), std::get<1>(t), ...);
	}

	template<typename TUPLE>
	size_t size_tuple(TUPLE t) {
		// Takes a tuple, returns the total size of all the elements in the tuple
		// we pass in a sequence of indices, then size_tuple_impl will run printn() for get<0..N>
		return size_tuple_impl(t, std::make_index_sequence<std::tuple_size<TUPLE>::value>{});
	}
};

// int main()
// {
// 	printn(9, "hello");

// 	auto t = std::make_tuple(1, 4, "hello123123123123", 4.3f, 4.3f, uint16_t(12), long{}, long(1231), long(1231), long(1231), long(1231));
// 	print_tuple(t);


// 	auto u = size_tuple(t);
// 	printn(u);
// 	printn(sizeof(t));

// 	Vec2 cat{ 2.3,42.1 };
// 	std::string mouse{ "asdasd123aqweasdfgesadfse" };

// 	print3(t, cat, mouse);

// 	return 0;
// }


