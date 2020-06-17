#include "Stopwatch.h"

void Stopwatch::begin()
{	
	t1 = std::chrono::high_resolution_clock::now();
}

void Stopwatch::end()
{	
	t2 = std::chrono::high_resolution_clock::now();
}

long long Stopwatch::elapsed_time()
{	
	return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}