# Plan

- indeks 0 - najniższy stopień
  - tablice - element o indeksie 0
  - int - bit o indeksie 0 (LSB)

## SW

1. Input Controller
   1. IC_GPIO
   2. IC_GPIO_UpDnFilter
2. Activation Controller
   1. AC_AllStepsAsOne
   2. AC_StepByStep
3. Brightness Controller
   1. BC_Binary
   2. BC_2XMultiplier
   3. BC_ConstDelta
4. PWM_Controller
   1. PC_PCA9685

- Opóźnienia czasowe - jak je zrealizować?
- Wykonanie instrukcji tylko kiedy to potrzeba. Maszyny stanów + Zwracania nie zera kiedy kolejny element powinien się uaktywnić?
  - Przykład: AC zmieniło stan stopnia -> wzwraca nie zero -> BC wie, że poza wewnętrznym stanem ma dodatkowy impuls do działania.


## Źródła

- Kontrolla PWM - https://www.youtube.com/watch?v=XVkHMbl1vz4
- Arduino I2C - https://docs.arduino.cc/learn/communication/wire/#wire-library
- Moduł PWM datasheet - https://cdn-shop.adafruit.com/datasheets/PCA9685.pdf
- Moduł PWM zdjęcie - https://allegro.pl/moje-allegro/zakupy/kupione/8c4ae64f-4243-3a77-855e-c55cff75d3cf/oferta/01759770-3098-11ee-bb85-e15a713c3ba0
- Arduino Nano pinout - https://docs.arduino.cc/static/a4d65079ebe3058e37153eb0f93890a8/2f891/pinout.png
- Arduino Timer Interrupt - https://www.arduino.cc/reference/en/libraries/timerinterrupt/
