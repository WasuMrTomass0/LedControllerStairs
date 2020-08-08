#ifndef GENERAL_GENERAL_H
#define GENERAL_GENERAL_H

#include "Settings.h"

void digitalWrite(unsigned, bool);

namespace pin {
    const unsigned RCLK = 11;
    const unsigned SRCLK = 11;
    const unsigned SER = 11;
}

namespace pwm_sett {
    const unsigned pwmLevels = 20;
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

void updateRegisters(bool*);

bool* pwmState;
void PWM(int*);


#endif // GENERAL_GENERAL_H

