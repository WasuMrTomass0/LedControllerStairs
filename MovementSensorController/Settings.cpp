#ifdef _MSC_VER 
#include "Settings.h"

void digitalWrite(unsigned, bool) {}
bool digitalRead(unsigned) { return true; }
TYPE::time millis() { return 1098; }
void delay(unsigned) {}
void delayMicroseconds(unsigned) {}
void pinMode(unsigned, unsigned) {}
TYPE::distance pulseIn(unsigned, bool) { return 2210; }
//int abs(int d) { return d >= 0 ? d : -d; }

CSerial Serial;

#endif // _MSC_VER 
