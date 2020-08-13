#include "Settings.h"

void digitalWrite(unsigned, bool) {}
void digitalRead(unsigned) {}
unsigned millis() { return 2; }
void delay(unsigned) {}
void delayMicroseconds(unsigned) {}
data_t pulseIn(unsigned, bool) { return 2; }