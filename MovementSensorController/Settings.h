#pragma once

#include <cstdlib>

// // // // // // // // // // // // // // // // // // // // // // 

namespace TYPE {  // TODO Choose correct types
	typedef unsigned time;
	typedef unsigned distance;
}

namespace PINOUT {
	// Sensor no 1
	constexpr unsigned S1_LEFT_TRIG = 10;
	constexpr unsigned S1_LEFT_ECHO = 10;

	constexpr unsigned S1_RIGHT_TRIG = 10;
	constexpr unsigned S1_RIGHT_ECHO = 10;

	constexpr unsigned S1_OUT_PIN = 10;

	// Sensor no 2
	constexpr unsigned S2_DIS_TRIG = 10;
	constexpr unsigned S2_DIS_ECHO = 10;
	constexpr unsigned S2_DIS_OUT_PIN = 10;
}

namespace CONFIG {
	constexpr bool ENABLE_STAIRS = true;
	constexpr bool DISABLE_STAIRS = false;
}

// // // // // // // // // // // // // // // // // // // // // // 

// Arduino based variables/functions/etc
constexpr bool HIGH = true;
constexpr bool LOW = false;
// Forward declarations
void digitalWrite(unsigned, bool);
void digitalRead(unsigned);
unsigned millis();
void delay(unsigned);
void delayMicroseconds(unsigned);
unsigned long pulseIn(unsigned, bool);
//int abs(int d);
