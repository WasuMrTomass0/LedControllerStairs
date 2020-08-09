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
    //extern int pwmLevel; // Preffered for comparision with ledValues[s] in "void PWM"
}

namespace pin {
    extern const unsigned RCLK;
    extern const unsigned SRCLK;
    extern const unsigned SER;
}


inline bool inputUpstairs() {
    return true;
}

inline bool inputDownstairs() {
    return true;
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


#endif // GENERAL_GENERAL_H

