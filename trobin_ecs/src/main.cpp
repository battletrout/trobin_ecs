// trobin_ecs.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "main.h"
#include "engine/Logger.h"
#include "engine/Timer.h"
#include "engine/Profiler.h"
#include "test/TstTimer.h"
//using namespace std;

struct cat {
	uint32_t meow{ 0 };

};

int main()
{
	PROFILE_FUNCTION();
	timerTest();

	return 0;
}
