#pragma once
#include <iostream>

//Template that accepts three variables of any type that can be printed
template<typename A, typename B, typename C>
void print3(A a, B b, C c) {
	std::cout << "a: " << a << "; "
		<< "b: " << b << "; "
		<< "c: " << c << "\n";
}

//
template<typename KEY_Type, typename DATA_Type>
struct Qmap {
	Qmap() { std::cout << "Qmap\n"; }
	Qmap(KEY_Type a, DATA_Type b) { std::cout << "Qmap\n"; }
	//default implementation
};

template<typename DATA_Type>
struct Qmap<int, DATA_Type> {
	Qmap() { std::cout << "Qmap<int,DATA_Type>\n"; }
	// optimization for int-based keys
};

template<>
struct Qmap<int, int> {
	Qmap() { std::cout << "Qmap<int,int>\n"; }
};

int templateTest()
{
	//PROFILE_FUNCTION();

	print3(1, 2, 3);
	std::string hello = "catbird";
	print3(hello, 4, hello);

	auto default_ = Qmap<float, bool>{};
	auto partial_specialization = Qmap<int, bool>{};
	auto full_specialization = Qmap<int, int>{};

	auto default_1 = Qmap{ 0.4f,true };

	return 0;
}