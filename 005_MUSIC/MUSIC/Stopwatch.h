#pragma once
#include <chrono>

class Stopwatch {
public:
	void begin();
	void end();
	long long elapsed_time();
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> t1;
	std::chrono::time_point<std::chrono::high_resolution_clock> t2;
};

