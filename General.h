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


inline bool inputUpstairs() {
    return (GetKeyState('M') & 0x8000/*Check if high-order bit is set (1 << 15)*/);

    /*std::string a;
    std::cout << "\inputUpstairs: ";
    std::cin >> a;
    return a != "0";
    return true;*/
}

inline bool inputDownstairs() {
    return false;
    // return digitalRead();
}

inline bool readManualMode() {
    return false;
    //return (DigitalRead(xx, XX));
}

void turnOnLeds(unsigned, bool);

void blink(unsigned, unsigned);

void updateRegisters(bool*);

void PWM(int*);

bool didTimePass(unsigned*, const unsigned, bool);
inline bool didTimePass(unsigned* time, const unsigned period) { return *time + period < millis(); }

#endif // GENERAL_GENERAL_H

