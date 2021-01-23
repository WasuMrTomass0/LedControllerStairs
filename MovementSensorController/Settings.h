#pragma once
// // // // // // // // // // // // // // // // // // // // // // 

#ifndef _MSC_VER
#include "Arduino.h"
#endif // !_MSC_VER


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
	constexpr unsigned S2_DIS_ECHO = 11;
	constexpr unsigned S2_DIS_OUT_PIN = 12;

	// Dataset Creation
	constexpr unsigned DS_TRIG_BUTT = 3; // Defines write to mem periods
	constexpr unsigned DS_DIR_BUTT = 4;  // Defines Ground Truth direction
	constexpr unsigned DS_BUZZER = 5;    // Buzzer pin

}

namespace CONFIG {
	constexpr bool ENABLE_STAIRS = true;
	constexpr bool DISABLE_STAIRS = false;
}

// // // // // // // // // // // // // // // // // // // // // // 

#ifdef _MSC_VER 
// Arduino based variables/functions/etc
constexpr bool HIGH = true;
constexpr bool LOW = false;
// Forward declarations
void digitalWrite(unsigned, bool);
bool digitalRead(unsigned);
TYPE::time millis();
void delay(unsigned);
void delayMicroseconds(unsigned);
TYPE::distance pulseIn(unsigned, bool);
void pinMode(unsigned, unsigned);

constexpr unsigned OUTPUT = 1;
constexpr unsigned INPUT = 2;
constexpr unsigned INPUT_PULLUP = 3;
//int abs(int d);

#include <cstdlib>
#include <iostream>
#include <string>
class CSerial
{
public:
	void begin(unsigned) {};
	void println(int x) { std::cout << x << '\n'; };
	void print(int x) { std::cout << x; };
	void println(std::string x) { std::cout << x << '\n'; };
	void print(std::string x) { std::cout << x; };
};

extern CSerial Serial;
#endif // _MSC_VER  


