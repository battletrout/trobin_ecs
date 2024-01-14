#pragma once
#include <cstdint>
#include <map>
#include <list>
#include <array>
#include <string>

/*
Archetypes managed with :
	(1) Map of archetypes, where the key corresponds to the Archetype ID and the value is a pointer to :
		(1) list of :
			(many)arrays of classes that have given components

*/

//TEST
struct exampleEntity {
	uint32_t param1{ 5 };
	std::string name{ "meow" };

};
//TEST

struct EntityManager {

	uint32_t entityID{ 0 };

	std::map < uint32_t, std::list<std::array<exampleEntity,20>>> asd;




};