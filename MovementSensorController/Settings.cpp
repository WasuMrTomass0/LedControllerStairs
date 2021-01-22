#include "Settings.h"

void digitalWrite(unsigned, bool) {}
void digitalRead(unsigned) {}
unsigned millis() { return 2; }
void delay(unsigned) {}
void delayMicroseconds(unsigned) {}
unsigned long pulseIn(unsigned, bool) { return 2; }
//int abs(int d) { return d >= 0 ? d : -d; }