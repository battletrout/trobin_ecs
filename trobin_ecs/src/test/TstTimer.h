#pragma once
#include "../engine/Profiler.h"
#include "../engine/Timer.h"



auto printCount(auto p_count)
{//tricking the compiler to run the timer test
	std::cout << p_count;
}

auto timerTest(auto p_x) {
	PROFILE_FUNCTION();
	Timer t;

	uint32_t start_state = 0xACE1;  
	uint32_t lfsr = start_state;
	uint32_t bit = p_x;
	//unsigned period = 0;

	size_t count{ 0 };

	auto elapsed = t.elapsed();
	//while (elapsed < 3'000'000) {
	//	elapsed = t.elapsed();
	//}

	t.start();
	for (size_t i = 0; i < (1024 * 1024 * 1024); i++) {
		bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & (0b1);
		lfsr = (lfsr >> 1) | (bit << 15) ;
		if (lfsr == start_state)
			//std::cout << lfsr << "\n";
			//co_yield lfsr;
			count++;
	}
	elapsed = t.elapsed();
	if (p_x != 0) { printCount(count); };
	//std::cout << elapsed << "\n";
	return (elapsed);
}

void runTimerTest() {
	size_t x{};
	std::cout << "Input a value";
	std::cin >> x;
	for (size_t i = 0; i < 21; i++) {
		std::cout << timerTest(x) << "\n";
	}
}