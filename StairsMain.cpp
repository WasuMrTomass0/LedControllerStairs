/*
#include "Arduino.h"
#include "src/utilities/CStairsBasic.h"
#include "src/utilities/General.h"
*/

#include "CStairsBasic.h"
#include "General.h"

void setup() {  
}
unsigned int mode = 0;

bool* ledState = new bool[SETT_STEPS];
int* ledValues = new int[SETT_STEPS];

PWMMode ledMode;
ManualMode manualMode = ManualOff;

IStairs* g_Controller;
CStairsBasic g_CBasicOff = CStairsBasic(PWMOff, ledState, ledValues);
CStairsBasic g_CBasicOn = CStairsBasic(PWMOn, ledState, ledValues);

void loop() {
    switch (mode) // Select PWMMode
    {
    case 0: 
        g_Controller = &g_CBasicOff;
        break;
    case 1:
        g_Controller = &g_CBasicOn;
        break;
    default:
        g_Controller = &g_CBasicOff;
        mode = 0;
        break;
    }    
    g_Controller->resetData();

    ledMode = g_Controller->get_ledMode();

    while (true) {
        // if (changeMode()) break;
        if (inputUpstairs())   {g_Controller->setMoveUpstairs();}
        if (inputDownstairs()) {g_Controller->setMoveDownstairs();}
        
        g_Controller->mainLoop();
        
        if (g_Controller->get_updateRegisters()) {
            if (ledMode == PWMOff) {
                updateRegisters(ledState);
            }
        } else PWM(ledValues);
    }
}

int main() {
}