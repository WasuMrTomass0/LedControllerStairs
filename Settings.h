// Settings

#ifndef SETTINGS_SETTINGS_H
#define SETTINGS_SETTINGS_H

#define SETT_STEPS 16

void digitalWrite(unsigned, bool);
unsigned millis();
void delay(unsigned);

// PWM Config
namespace pwm {
    const unsigned allLevels = 20;

    const unsigned freq = 50; // Hz
    const unsigned framePeriod = 1000 / freq / allLevels;
    const unsigned level = 255 / allLevels;

    bool* pwmState = new bool[SETT_STEPS];
    unsigned timeStamp = 0;
    unsigned pwmLevel = 0;
}

namespace pin {
    const unsigned RCLK = 10;
    const unsigned SRCLK = 10;
    const unsigned SER = 10;
}

#define LOW false
#define HIGH true

#define DEBUG


#endif // SETTINGS_SETTINGS_H