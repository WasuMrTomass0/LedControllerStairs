#ifndef GENERAL_GENERAL_H
#define GENERAL_GENERAL_H

#include "Settings.h"

// PWM Config
namespace pwm {
    extern const unsigned allLevels;

    extern const unsigned freq;
    extern const unsigned framePeriod;
    extern const unsigned level;

    extern bool* pwmState;
    extern unsigned timeStamp;
    extern unsigned pwmLevel;
}

namespace pin {
    extern const unsigned RCLK;
    extern const unsigned SRCLK;
    extern const unsigned SER;
}

// --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- // --- //

inline bool inputUpstairs() {
    return false;
}

inline bool inputDownstairs() {
    return false;
}

inline bool readManualMode() {
    return false;
}

inline bool changeMode() {
    return false;
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

#endif // GENERAL_GENERAL_H
