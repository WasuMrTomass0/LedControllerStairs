// StairsVisualStudio.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include "CStairsBasic.h"
#include "General.h"
//#include "BitSet.h"

int main()
{
    /*CStairsBasic B(PWMOff);
    B.printTab<bool>(B.get_ledState());
    B.printTab<int>(B.get_ledValues());*/
    /*std::cout << "int " << sizeof(int) << '\n';
    std::cout << "bool " << sizeof(bool) << '\n';
    std::cout << "unsigned " << sizeof(unsigned) << '\n';
    std::cout << "BitSet " << sizeof(BitSet) << '\n';*/
}

void setup() {
    
}
unsigned int mode = 0;

bool* ledState = new bool[SETT_STEPS];
int* ledValues = new int[SETT_STEPS];

LedMode ledMode;
ManualMode manualMode = ManualOff;

IStairs* g_Controller;
CStairsBasic g_CBasicOff = CStairsBasic(PWMOff, ledState, ledValues);
CStairsBasic g_CBasicOn = CStairsBasic(PWMOn, ledState, ledValues);

void loop() {
    switch (mode) // Select LedMode
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

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
