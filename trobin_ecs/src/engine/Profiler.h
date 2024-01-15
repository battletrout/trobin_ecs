/*
Creates an output file for profiling "results.json" in the 
Open Chrome://tracing on google chrome, then drag and drop the file in to view the results
*/

#pragma once
#include <fstream>
#include <chrono>
#include <string>
#include <thread>
#include <algorithm>
#include <mutex>
#include <iostream>



//C++ Macro for profiling calls
//Ensures unique profile timer names for a given timer by  
#define PROFILING 1 //Comment out this line if we don't want profiling
#ifdef PROFILING
	#define PROFILE_SCOPE(name) \
			ProfileTimer timer##__LINE__(name)
	#define PROFILE_FUNCTION() \
			PROFILE_SCOPE(__FUNCTION__)
#else
	#define PROFILE_SCOPE(name)
#endif

//Singleton class Profiler for outputting performance profile to single result file

struct ProfileResult {
	std::string name = "Default";
	long long start = 0;
	long long end = 0;
	size_t threadID = 0; 

};

class Profiler {
	std::string _outputFile = "results.json";
	size_t _profileCount = 0;
	std::ofstream _outputStream;
	std::mutex _lock;
	
	
	Profiler() {
		//Write JSON header
		_outputStream = std::ofstream(_outputFile);
		writeHeader();
		std::cout << "Profiler Created\n";
	}
	
	void writeHeader() { _outputStream << "{\"otherData\": {},\"traceEvents\":["; }
	void writeFooter() { _outputStream << "]}"; }


public:
	static Profiler& Instance()
	{
		static Profiler instance;
		return instance;
	}
	
	void writeProfile(const ProfileResult & p_result) {
		//write profile result JSON
		std::lock_guard<std::mutex> lock(_lock);

		if (_profileCount++ > 0) { _outputStream << ","; }

		std::string name = p_result.name;
		std::replace(name.begin(), name.end(), '"', '\'');

		_outputStream << "\n{";
		_outputStream << "\"cat\":\"function\",";
		_outputStream << "\"dur\":" << (p_result.end - p_result.start) << ',';
		_outputStream << "\"name\":\"" << name << "\",";
		_outputStream << "\"ph\":\"X\",";
		_outputStream << "\"pid\":0,";
		_outputStream << "\"tid\":" << p_result.threadID << ",";
		_outputStream << "\"ts\":" << p_result.start;
		_outputStream << "}";

	}
	~Profiler() {
		//write JSON footer when destructing (when program exits)
		writeFooter();
	}
};
//when Timer stops, call Profiler::Instance().writeProfile



class ProfileTimer {

	typedef std::chrono::time_point<std::chrono::high_resolution_clock> ClockType;

	ProfileResult _result;
	bool _stopped = false;
	ClockType _startTimePoint;
	//Starting Time Point

public:
	ProfileTimer(const std::string& p_name)
		: _result({p_name,0,0,0})
	{

		// Start timer when constructed
		start();
	}

	~ProfileTimer() { stop(); }


	void start() {
		//static var to store last start time recorded
		static long long lastStartTime = 0;

		//get actual start time
		_startTimePoint = std::chrono::high_resolution_clock::now();
		_result.start = std::chrono::time_point_cast<std::chrono::microseconds>
			(_startTimePoint).time_since_epoch().count();

		// if same as prev start time, add 1 to it due to chrome://tracing bug to avoid identical start times
		_result.start += (_result.start == lastStartTime ? 1 : 0);

		//record fixed time as prev start time
		lastStartTime = _result.start;
		_stopped = false;
	}

	void stop()
	{
		// Stop timer when deconstructed, automatically write to profiler
		using namespace std::chrono;

		if (_stopped) { return; }
		_stopped = true;

		auto endTimePoint = high_resolution_clock::now();
		_result.start = time_point_cast<microseconds>(_startTimePoint).time_since_epoch().count();
		_result.end = time_point_cast<microseconds>(endTimePoint).time_since_epoch().count();
		_result.threadID = std::hash < std::thread::id>{}(std::this_thread::get_id());

		Profiler::Instance().writeProfile(_result);
	}


};