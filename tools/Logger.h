#pragma once
#include <fstream>

// Singleton class Logger than can be called anywhere to produce log to a single log file

class Logger {
	std::ofstream _outFile = std::ofstream("log.txt");

public:
	static Logger& Instance()
	{
		static Logger instance;
		return instance;
	}
	void log(const std::string& str) { _outFile << str << "\n"; }
};

//Outside use:
//Logger::Instance().log("Hello there how are you");