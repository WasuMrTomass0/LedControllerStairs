/*
#include "Arduino.h"
#include "src/utilities/CStairsBasic.h"
#include "src/utilities/General.h"
#include "src/utilities/CStairsSimpleWave.h"
*/

#include "General.h"
#include "CStairsBasic.h"
#include "CStairsSimpleWave.h"
//#include "CInputOneWire.h"

// #define DEBUG

void setup() {  
#ifndef WINDOWS
#ifdef DEBUG
    Serial.begin(115200);
    Serial.println("DEBUG MODE - Platform Arduino");
#endif // DEBUG

#endif // !WINDOWS



    blink(4, 500);
    delay(500);
    for (unsigned i = 1; i <= SETT_STEPS; ++i) {
        turnOnLeds(i, true); 
        delay(500);
    }
    for (unsigned i = 1; i <= SETT_STEPS; ++i) {
        turnOnLeds(i, false);
        delay(500);
    }
}
unsigned int mode = 3;

bool* ledState = new bool[SETT_STEPS];
int* ledValues = new int[SETT_STEPS];

PWMMode ledMode;
ManualMode manualMode = ManualOff;

IStairs* g_Controller;
CStairsBasic g_CBasicOff = CStairsBasic(PWMOff, ledState, ledValues);
CStairsBasic g_CBasicOn = CStairsBasic(PWMOn, ledState, ledValues);
CStairsSimpleWave g_CWaveOff = CStairsSimpleWave(PWMOff, ledState, ledValues);
CStairsSimpleWave g_CWaveOn = CStairsSimpleWave(PWMOn, ledState, ledValues);

// TODO
// Add energy save mode. When Input signal is constant longer than MAX_TIME, leds are turned of until input signal drops
//

void loop() {
    manualMode = readManualMode() ? ManualOn : ManualOff;
    if (manualMode == ManualOn) {
        turnOnLeds(SETT_STEPS, true);
        while (readManualMode()) {}
        return;
    }

    switch (mode){
    case 0: 
        g_Controller = &g_CBasicOff; break;
    case 1:
        g_Controller = &g_CBasicOn; break;
    case 2:
        g_Controller = &g_CWaveOff; break;
    case 3:
        g_Controller = &g_CWaveOn; break;
    default:
        mode = 0; return;
    }
    g_Controller->resetData();

    ledMode = g_Controller->get_ledMode();

    while (true) {
        if (readManualMode()) return;
        if (changeMode()) break;

        if (inputUpstairs())   {g_Controller->setMoveUpstairs();}
        if (inputDownstairs()) {g_Controller->setMoveDownstairs();}
        
        if (!g_Controller->mainLoop()) break; // Remember to clear movement flags in all mainLoops!
        
        if (g_Controller->get_updateRegisters()) {
            if (ledMode == PWMOff) updateRegisters(ledState);
            else PWM(ledValues); 
        } 
    }
    while (changeMode());
    mode++;
}

int main() {
    setup();
    while (true) loop();
}
