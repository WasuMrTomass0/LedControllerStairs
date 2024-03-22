#include "src/distance_controller/distance_controller.h"
#include "src/distance_controller/dc_hc_sr04.h"
#include "src/common/time_funcs.h"


// Sensor 1 pins
const int PIN_TRIG_1 = 12;
const int PIN_ECHO_1 = 11;
// Sensor 2 pins
const int PIN_TRIG_2 = 12;
const int PIN_ECHO_2 = 11;
// Sensor objects
DC_HC_SR04* ptr_hc_1;
DC_HC_SR04* ptr_hc_2;
// Thresholds
const uint16_t threshold_min;
const uint16_t threshold_max;


void setup()
{
  Serial.begin(115200);
  Serial.println("Setup start");

  ptr_hc_1 = new DC_HC_SR04(PIN_TRIG_1, PIN_ECHO_1);
  // ptr_hc_2 = new IC_HC_SR04(PIN_TRIG_2, PIN_ECHO_2);

  Serial.println("Setup done");
}

void loop()
{
  Serial.println(ptr_hc_1->get_distance_cm());
  delay(1000);
  
}
