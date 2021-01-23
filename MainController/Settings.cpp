#include "Settings.h"

#ifdef _MSC_VER
#include <time.h>
#include <ctime>

bool digitalRead(unsigned) { return true; };
void digitalWrite(unsigned u, bool b) {}

unsigned millis() {
	static std::clock_t start = std::clock();
	return static_cast<unsigned>(1000.0 * (std::clock() - start) / CLOCKS_PER_SEC);
}

void delay(unsigned p) {
	unsigned t = millis();
	while (t + p > millis()) {}
}
#endif // _MSC_VER
