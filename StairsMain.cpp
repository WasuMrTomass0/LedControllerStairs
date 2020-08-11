/*
#include "Arduino.h"
#include "src/utilities/CStairsBasic.h"
#include "src/utilities/General.h"
*/

#include "CStairsBasic.h"
#include "General.h"

#define DEBUG

void setup() {  
}
unsigned int mode = 1;

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
        
        g_Controller->mainLoop(); // Remember to clear movement flags in all mainLoops!
        
        if (g_Controller->get_updateRegisters()) {

            std::cout << "\n\t" << millis() << " [ms]";
            std::cout << "\n\t";  g_Controller->printTab<bool>(ledState, false);
            std::cout << "\n\t";  g_Controller->printTab<int>(ledValues, false);
            std::cout << "\n";

            if (ledMode == PWMOff) {
                updateRegisters(ledState);
            } else PWM(ledValues);
        } 
    }
}

int main() {

    /*bool* tab = new bool[SETT_STEPS];
    for (unsigned i = 0; i < SETT_STEPS; i++) tab[i] = i % 3;

    std::cout << "\n"; for (unsigned i = 0; i < SETT_STEPS; i++) std::cout << tab[i] << " ";
    shiftTab(tab, SETT_STEPS, 1);
    std::cout << "\n"; for (unsigned i = 0; i < SETT_STEPS; i++) std::cout << tab[i] << " ";
    shiftTab(tab, SETT_STEPS, 0);
    std::cout << "\n"; for (unsigned i = 0; i < SETT_STEPS; i++) std::cout << tab[i] << " ";*/
    //template<typename T>
    //void shiftTab(T * tab, unsigned size, bool shiftUpByIndex)



    setup();
    //loop();
}