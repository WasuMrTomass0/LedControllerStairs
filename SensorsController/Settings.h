#pragma once

typedef unsigned data_t; // Measure data type
typedef unsigned time_t; // Measure time type

constexpr unsigned measureFreq = 50; //[Hz]  -  Minimum 50




constexpr bool LOW = false;
constexpr bool HIGH = true;

// Forward declarations
void digitalWrite(unsigned, bool);
void digitalRead(unsigned);
unsigned millis(unsigned);
void delay(unsigned);
void delayMicroseconds(unsigned);
data_t pulseIn(unsigned, bool);