#pragma once

#include <Archetype.h>

/*
Singleton ArchetypeManager
Building from devNotesArchitypes:
	Inputs:
		- Tuple of types, these will be the components present in the architype
		- Maximum Memory Block Size

	Actions:
		- Add up the sizes of each of the individual component types
			- this will be the total size of a single entity with one block of each type
		- Calculate the maximum number of entities that can be held in a single memory block of this architype
		- Allocate arrays

	Return:
		- 64-bit
*/
