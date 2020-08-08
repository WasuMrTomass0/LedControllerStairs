#ifndef GENERAL_GENERAL_H
#define GENERAL_GENERAL_H

#include "Settings.h"





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

