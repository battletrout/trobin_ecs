#pragma once

#include <chrono>
using namespace std::chrono;

class Timer {
	/*
	Timer for profiling built from Dave Churchill's Comp4300 class lecture videos
	returns 8-byte long long microseconds since start time
	*/
	long long _start = 0, _end = 0;

	//starting time point
	time_point<high_resolution_clock> _stp;

public:
	Timer()	{ 
		start(); 
	}

	void start() { 
		_stp = high_resolution_clock::now(); 
	}

	long long elapsed() //return time elapsed in microseconds
	{
		auto etp = high_resolution_clock::now();
		_start = time_point_cast<microseconds>(_stp).time_since_epoch().count();
		_end = time_point_cast<microseconds>(etp).time_since_epoch().count();
		return _end - _start;
	}

};