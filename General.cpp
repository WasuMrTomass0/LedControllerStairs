#include "General.h"

namespace pwm {
    // Led PWM levels
    const unsigned allLevels = 20;

    const unsigned freq = 50; // Frequency [Hz]
    const unsigned framePeriod = 1000 / freq / allLevels; // Single PWM frame preiod [ms]
    const unsigned level = 255 / allLevels;

    bool* pwmState = new bool[SETT_STEPS];
    unsigned timeStamp = 0;
    // unsigned pwmLevel = 0;
    unsigned pwmLevel = 0;
}

namespace pin {
    const unsigned RCLK = 10;
    const unsigned SRCLK = 10;
    const unsigned SER = 10;
}

void updateRegisters(bool* ledState) {
    digitalWrite(pin::RCLK, LOW);
    for(int i = SETT_STEPS - 1; i >= 0; i--) {
        digitalWrite(pin::SRCLK, LOW);
        digitalWrite(pin::SER, ledState[i]);
        digitalWrite(pin::SRCLK, HIGH);
    }
    digitalWrite(pin::RCLK, HIGH);
}

void PWM(int* ledValues) {
    for (size_t i = 0; i < pwm::allLevels; i++) {
        pwm::timeStamp = millis();
        // pwm::pwmLevel = i * pwm::level;
        pwm::pwmLevel = (i * 255) / pwm::allLevels;
        for (size_t s = 0; s < SETT_STEPS; s++) pwm::pwmState[s] = ledValues[s] > pwm::pwmLevel;
        while (pwm::timeStamp + pwm::framePeriod > millis()) {}
        updateRegisters(pwm::pwmState);
    }
}

void turnOnLeds(unsigned n, bool upstairs = true) {
    for (size_t i = 0; i < SETT_STEPS; i++) {
        pwm::pwmState[i] = (upstairs ? (i > n) : (SETT_STEPS - i <= n));
    }
    updateRegisters(pwm::pwmState);
}

void blink(unsigned times, unsigned period) {
    for (unsigned i = 0; i < times; i++) {
        turnOnLeds(SETT_STEPS);
        delay(period);
        turnOnLeds(0);
        delay(period);
    }
}