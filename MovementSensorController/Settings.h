#pragma once

#include <cstdlib>

typedef unsigned data_t; // Measure data type
typedef unsigned time_type; // Measure time type

constexpr unsigned measureFreq = 50;	//[Hz]  -  Minimum 50
constexpr unsigned dataCapacity = 50;	// How many measurements are stored, how many are used for slopeFactor calculation

// To test
constexpr int SLOPEFACTOR_MIN_DIFF = 1;
constexpr float SLOPEFACTOR_MIN_SLOPE = 0.5;
//

// Config
constexpr unsigned LEFT_TRIG = 10;
constexpr unsigned LEFT_ECHO = 10;

constexpr unsigned RIGHT_TRIG = 10;
constexpr unsigned RIGHT_ECHO = 10;

constexpr unsigned OUT_PIN = 10;
// end Config


constexpr bool LOW = false;
constexpr bool HIGH = true;

// Forward declarations
void digitalWrite(unsigned, bool);
void digitalRead(unsigned);
unsigned millis();
void delay(unsigned);
void delayMicroseconds(unsigned);
data_t pulseIn(unsigned, bool);
//int abs(int d);
