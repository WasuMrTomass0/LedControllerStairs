#pragma once

#include <cstdlib>

// // // // // // // // // // // // // // // // // // // // // // 

namespace PINOUT {
	constexpr unsigned LEFT_TRIG = 10;
	constexpr unsigned LEFT_ECHO = 10;

	constexpr unsigned RIGHT_TRIG = 10;
	constexpr unsigned RIGHT_ECHO = 10;

	constexpr unsigned OUT_PIN = 10;
}

namespace CONFIG {
	constexpr bool ENABLE_STAIRS = true;
	constexpr bool DISABLE_STAIRS = false;
}

// // // // // // // // // // // // // // // // // // // // // // 

// Forward declarations
void digitalWrite(unsigned, bool);
void digitalRead(unsigned);
unsigned millis();
void delay(unsigned);
void delayMicroseconds(unsigned);
unsigned long pulseIn(unsigned, bool);
//int abs(int d);
