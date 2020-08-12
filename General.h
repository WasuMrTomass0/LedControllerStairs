#ifndef GENERAL_GENERAL_H
#define GENERAL_GENERAL_H

#include "Settings.h"

#include <string>
#include <iostream>
#include <Windows.h>

// PWM Config
namespace pwm {
    extern const unsigned allLevels;

    extern const unsigned freq;
    extern const unsigned framePeriod;
    extern const unsigned level;

    extern bool* pwmState;
    extern unsigned timeStamp;
    extern unsigned pwmLevel;
    //extern int pwmLevel; // Preffered for comparision with ledValues[s] in "void PWM"
}

namespace pin {
    extern const unsigned RCLK;
    extern const unsigned SRCLK;
    extern const unsigned SER;
}

// --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- //

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

void turnOnLeds(unsigned, bool);

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

