// Settings
#ifndef SETTINGS_SETTINGS_H
#define SETTINGS_SETTINGS_H

#define WINDOWS	// If defined, Windows mode is activated
#define DEBUG

//	//	//	//	//	//	//	//	//	//
//#if !defined(WINDOWS)
#ifndef WINDOWS
#include "Arduino.h"
#else
// Only in VS
#define LOW false
#define HIGH true

bool digitalRead(unsigned);
void digitalWrite(unsigned, bool);
unsigned millis();
void delay(unsigned);
#endif
//	//	//	//	//	//	//	//	//	//

#define SETT_STEPS 16


#endif // SETTINGS_SETTINGS_H