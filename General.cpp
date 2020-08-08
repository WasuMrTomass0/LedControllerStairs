#include "General.h"

void updateRegisters(bool* ledState) {
    digitalWrite(pin::RCLK, LOW);
    for(int i = SETT_STEPS - 1; i >= 0; i--) {
        digitalWrite(pin::SRCLK, LOW);
        digitalWrite(pin::SER, ledState[i]);
        digitalWrite(pin::SRCLK, HIGH);
    }
    digitalWrite(pin::RCLK, HIGH);
}


void PWM(int*) {

}

void wlasny_PWM() {
    int i = 0;
    for (i = 0; i < SETT_PWMLVLS - 1; i++) {
        //    while(!czy_czas_minal(&tPWM_czas_wgrania, okres_wgrywania_pwm, true)); // Wstrzymanie sie na odpowiedni czas
        //    delay(1);
        //    delayMicroseconds(okres_wgrywania_pwm);
        for (int s = 0; s < SETT_STEPS; s++) {
            tPWM_chwilowy_stan[a] = (tPWM_progi_wypelnienia[a] > i || tPWM_progi_wypelnienia[a] == stopni_swiecenia - 1 ? true : false);
        }
        updateRegisters(tPWM_chwilowy_stan); // Wgranie danych
    }
}