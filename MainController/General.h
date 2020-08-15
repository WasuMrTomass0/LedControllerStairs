#ifndef GENERAL_GENERAL_H
#define GENERAL_GENERAL_H

#include "Settings.h"

#ifdef WINDOWS
#include <string>
#include <iostream>
#include <Windows.h>
#else
#include <Arduino.h>
#endif


// PWM Config
namespace pwm {
    constexpr unsigned allLevels = 20;  // Led PWM levels
    constexpr unsigned freq = 50;       // Frequency [Hz]
    constexpr unsigned framePeriod = 1000 / freq / allLevels; // Single PWM frame preiod [ms]
    constexpr unsigned level = 255 / allLevels;

    extern bool* pwmState;
    extern unsigned timeStamp;
    extern unsigned pwmLevel;
}

namespace pin {
    constexpr unsigned RCLK = 8;
    constexpr unsigned SRCLK = 7;
    constexpr unsigned SER = 13;
    constexpr unsigned IN_UPSTAIRS = 12;
    constexpr unsigned IN_DOWNSTAIRS = 10;
    constexpr unsigned IN_MANUAL = 11;
    constexpr unsigned IN_CHANGE_MODE = 11;  // Should be 9;
}

// --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- //

#ifdef WINDOWS
inline bool inputUpstairs() {
    return (GetKeyState('U') & 0x8000/*Check if high-order bit is set (1 << 15)*/);
}

inline bool inputDownstairs() {
    return (GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/);
}

inline bool readManualMode() {
    return (GetKeyState('M') & 0x8000/*Check if high-order bit is set (1 << 15)*/);
}

inline bool changeMode() {
    return (GetKeyState('C') & 0x8000/*Check if high-order bit is set (1 << 15)*/);
}
#else // WINDOWS
inline bool inputUpstairs() {
    return digitalRead(pin::IN_UPSTAIRS) == HIGH;
}

inline bool inputDownstairs() {
    return false; // TODO Change when second sensor is ready
    //return digitalRead(pin::IN_DOWNSTAIRS) == HIGH;
}

inline bool readManualMode() {
    return false;
    //return digitalRead(pin::IN_MANUAL) == HIGH;
}

inline bool changeMode() {
    return digitalRead(pin::IN_CHANGE_MODE) == HIGH;
}
#endif // not WINDOWS



void turnOnLeds(unsigned, bool);

inline void turnOnAllLeds()  { turnOnLeds(SETT_STEPS, true); }
inline void turnOffAllLeds() { turnOnLeds(0, true); }

void blink(unsigned, unsigned);

void updateRegisters(bool*);

void PWM(int*);

bool didTimePass(unsigned*, const unsigned, bool);
inline bool didTimePass(unsigned* time, const unsigned period) { return *time + period < millis(); }

void shiftTab(bool*, const unsigned, bool);

bool isAllEqualTo(bool*, const unsigned, bool);

void orBool(bool*, bool*, bool*, const unsigned);

//templateate <typename T>
//void shiftTab(T*, unsigned, bool);

//template<typename T, unsigned N>
//void shiftArray(std::array);

#endif // GENERAL_GENERAL_H

