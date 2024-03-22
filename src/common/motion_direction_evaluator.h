#include <Arduino.h>

class MotionDirectionEvaluator {
private:
    const uint16_t minDistance = 100;        // Minimalna odległość w milimetrach
    const uint16_t maxDistance = 2000;       // Maksymalna odległość w milimetrach
    const uint16_t uncertainThreshold = 200; // Prog niepewności

public:
    enum MotionState {
        MovingCloser,
        MovingAway,
        Uncertain
    };

    MotionState evaluateDirection(uint16_t currentDistance, uint16_t previousDistance) {
        if (currentDistance < minDistance || currentDistance > maxDistance || previousDistance < minDistance || previousDistance > maxDistance) {
            return Uncertain; // Pomiar spoza zakresu, niepewność
        }

        uint16_t difference = abs(currentDistance - previousDistance);

        if (currentDistance < previousDistance && difference > uncertainThreshold) {
            return MovingCloser; // Zbliżanie się
        } else if (currentDistance > previousDistance && difference > uncertainThreshold) {
            return MovingAway; // Oddalanie się
        } else {
            return Uncertain; // Stan niepewności
        }
    }
};

// Przykładowe użycie
MotionDirectionEvaluator motionEvaluator;

void setup() {
    // Inicjalizacja czujników, portów wejściowych itp.
}

void loop() {
    // Pobranie aktualnego pomiaru odległości (w milimetrach)
    uint16_t currentDistance = ...; // Pobranie aktualnego pomiaru odległości z czujnika HC SR04
    static uint16_t previousDistance = currentDistance;

    // Czekanie na czas pomiędzy kolejnymi pomiarami (odpowiednio dla częstotliwości 10Hz - 20Hz)

    // Ocena kierunku ruchu
    MotionDirectionEvaluator::MotionState direction = motionEvaluator.evaluateDirection(currentDistance, previousDistance);

    // Wykonanie akcji na podstawie oceny kierunku ruchu (np. wyświetlenie na ekranie LCD, sterowanie silnikami itp.)

    // Aktualizacja poprzedniego pomiaru
    previousDistance = currentDistance;
}
