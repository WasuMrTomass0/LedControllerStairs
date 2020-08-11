#include "Settings.h"

#include <time.h>
#include <ctime>

void digitalWrite(unsigned u, bool b) {}

unsigned millis() {
	//static time_t start = time(0);
	//return static_cast<unsigned>(difftime(time(0), start));
	static std::clock_t start = std::clock();
	return static_cast<unsigned>(1000.0 * (std::clock() - start) / CLOCKS_PER_SEC);
}

void delay(unsigned p) {}