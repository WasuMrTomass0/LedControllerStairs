#include "General.h"

namespace pwm {
    bool* pwmState = new bool[SETT_STEPS];
    unsigned timeStamp = 0;
    unsigned pwmLevel = 0;
}

void updateRegisters(bool* ledState) {

#ifdef DEBUG
#ifdef _MSC_VER
    for (unsigned i = 0; i < SETT_STEPS; ++i) std::cout << ledState[i] << ' ';
    std::cout << '\n';
#else
    for (unsigned i = 0; i < SETT_STEPS; ++i) Serial.print(ledState[i]); Serial.print(" ");
    Serial.println();
#endif // _MSC_VER
#endif // DEBUG


    digitalWrite(pin::RCLK, LOW);
    for(int i = SETT_STEPS - 1; i >= 0; i--) {
        digitalWrite(pin::SRCLK, LOW);
        digitalWrite(pin::SER, ledState[i]);
        digitalWrite(pin::SRCLK, HIGH);
    }
    digitalWrite(pin::RCLK, HIGH);
}

void PWM(int* ledValues) {
    for (unsigned i = 0; i < pwm::allLevels; i++) {
    //for (unsigned i = 0; i < pwm::allLevels-1; i++) { // Temporally fix. (pwm::allLevels-1)
        //  Fix: Po uaktualnieniu najnowszej wartosci PWMu (0-255) oceniane jest, czy mnalezy wgrywac PWM (warto�� x: 0 < x < 255)
        //  Nale�y:
        //      Gdy osiagnie sie warto�� 0 lub 255, jednorazowo wgra� dane na rejestry
        //
        //////pwm::timeStamp = millis();
        // pwm::pwmLevel = i * pwm::level;
        pwm::pwmLevel = (i * 255) / pwm::allLevels;
        for (unsigned s = 0; s < SETT_STEPS; s++) pwm::pwmState[s] = ledValues[s] > pwm::pwmLevel; // TODO Check if last frame is filled with HIGH state for 100% fillment PWM
        //////while (pwm::timeStamp + pwm::framePeriod > millis()) {}
        updateRegisters(pwm::pwmState);
    }
}

void turnOnLeds(unsigned n, bool upstairs = true) {
    for (unsigned i = 0; i < SETT_STEPS; i++) {
        if (upstairs) {
            pwm::pwmState[i] = i < n;
        }
        else {
            pwm::pwmState[i] = SETT_STEPS-i <= n;
        }
        //pwm::pwmState[i] = (upstairs ? (i > n) : (SETT_STEPS - i + 1<= n));
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

bool didTimePass(unsigned* time, const unsigned period, bool update_time) {
    if (*time + period < millis()) {
        if (update_time) { *time = millis(); }
        return true;
    }
    return false;
}

void shiftTab(bool* tab, const unsigned size, bool shiftUpByIndex) {
    if (shiftUpByIndex)
        for (unsigned i = size-1; i > 0; i--) tab[i] = tab[i-1];
    else 
        for (unsigned i = 0; i < size-1; i++) tab[i] = tab[i+1];    
}

bool isAllEqualTo(bool* tab, const unsigned size, bool state) {
    for (unsigned i = 0; i < size; i++) {
        if (tab[i] != state) return false;
    }
    return true;
}

void orBool(bool* tab1, bool* tab2, bool* result, const unsigned size) {
    for (unsigned i = 0; i < size; i++) result[i] = tab1[i] || tab2[i];
}

//template<typename T>
//void shiftTab(T* tab, unsigned size, bool shiftUpByIndex) {
//    if (shiftUpByIndex) 
//        for (unsigned i = size-2; i >= 0; i--) tab[i+1] = tab[i];
//    else 
//        for (unsigned i = 0; i < size-1; i++) tab[i] = tab[i+1];
//}

//template<typename T, unsigned N>
//void shiftArray(std::array<T, N> & arr, bool shiftUpByIndex) {
//    if (shiftUpByIndex)
//        for (unsigned i = arr.size() - 2; i >= 0; i--) arr[i + 1] = arr[i];
//    else 
//        for (unsigned i = 0; i < arr.size() - 1; i++) arr[i] = arr[i + 1];
//}
