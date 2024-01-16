#pragma once
#include <iostream>

// First programming metafunction: find out if a tuple contains a given type

//Declare an if_ for our programming metafunction.
template<bool condition, typename THEN, typename ELSE>
struct if_;

template<typename THEN, typename ELSE>
struct if_<true, THEN, ELSE> {
	using type = THEN;
};

template<typename THEN, typename ELSE>
struct if_<false, THEN, ELSE> {
	using type = ELSE;
};

///We will resolve to either std::false_type and std::true_type in our metaprograms, which are just
//static constexpr of bool = false or true.

//Type to search for, tuple to search in, if statements
//If statements are different in template metafunctions


template<typename SEARCH, typename TUPLE, size_t start_from = 0>
struct contains_type :
	if_ < //IF the type of tuple element t is the same as the type we're searching for
	//This is the logical test
	std::is_same<std::tuple_element_t<start_from, TUPLE>, SEARCH>::value,
	//THEN
	std::true_type,
	//ELSE
	typename if_ < //if we have reached the end of the tuple, return false
	//"typename" is necessary because if_ is a dependent name.
	//The type returned is dependent on the template parameter, as the resulting type may have a method::type that returns a value.
	//We need to say that if_ will always return a typename.
	(start_from == std::tuple_size<TUPLE>::value - 1),
	//THEN
	std::false_type,
	//ELSE, recurse; we inherit from 
	contains_type<SEARCH, TUPLE, start_from + 1>
	>::type
	>::type
{};

// Specialization if the tuple is empty-- return false_type
template<typename SEARCH>
struct contains_type<SEARCH, std::tuple<>, 0> : std::false_type {};
/*
bool contains_type(const std::string& SEARCH, const std::vector<std::string>& v, size_t start_from = 0) {
	if (v[start_from] == SEARCH) {
		return true;
	}
	else {
		if (start_from == v.size() - 1) {
			return false;
		}
		else {
			return contains_type(SEARCH, v, start_from + 1);
		}
	}
}
*/

int containsTypeTest() {
	//	boolalpha takes a bool value and outputs it as true or false.
//		is_same we are using to compare the ::type of the if_ to uint32_t

// Test the if_ template
	std::cout << std::boolalpha << std::is_same < uint32_t, if_<(10 < 5), uint32_t, char>::type>::value << "\n";

	// Test the contains_type function
	std::tuple<int, bool, float> tuple;

	std::cout << std::boolalpha << contains_type<bool, decltype(tuple)>::value << "\n";
	std::cout << std::boolalpha << contains_type<double, decltype(tuple)>::value << "\n";
	std::cout << std::boolalpha << contains_type<double, std::tuple<>>::value << "\n";
	return 0;
}