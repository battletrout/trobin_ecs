#pragma once
#include "../engine/Profiler.h"
#include "../engine/Timer.h"
size_t timerTest() {
	PROFILE_FUNCTION();
	Timer t;

	uint32_t start_state = 0xACE1;  /* Any nonzero start state will work. */
	uint32_t lfsr = start_state;
	uint32_t bit;                    /* Must be 16-bit to allow bit<<15 later in the code */
	unsigned period = 0;

	size_t count{ 0 };

	auto elapsed = t.elapsed();
	//while (elapsed < 3'000'000) {
	//	elapsed = t.elapsed();
	//}

	t.start();
	for (size_t i = 0; i < 1024 * 1024 * 1024; i++) {
		bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 0b1;
		lfsr = (lfsr >> 1) | (bit << 15);
		if (lfsr == start_state)
			//std::cout << lfsr << "\n";
			//co_yield lfsr;
			count++;
	}
	elapsed = t.elapsed();
	std::cout << "Done, time: " << elapsed << "us (microseconds)\n";
	return elapsed;
}