// Settings
#ifndef SETTINGS_SETTINGS_H
#define SETTINGS_SETTINGS_H

#define WINDOWS	// If defined, Windows mode is activated


//	//	//	//	//	//	//	//	//	//
//#if !defined(WINDOWS)
#ifndef WINDOWS
#include "Arduino.h"
#else
// Only in VS
bool digitalRead(unsigned);
void digitalWrite(unsigned, bool);
unsigned millis();
void delay(unsigned);
#endif
//	//	//	//	//	//	//	//	//	//



#define SETT_STEPS 16
#define LOW false
#define HIGH true

#define DEBUG

#endif // SETTINGS_SETTINGS_H