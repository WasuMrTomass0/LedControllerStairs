#include "../distance_sensor/distance_sensor.h"
#include "../distance_sensor/dc_hc_sr04.h"
#include "../input_controller/input_controller.h"
#include "../input_controller/ic_distance_basic.h"
#include "../common/filter_up_dn.h"
#include "../timer/timer.h"


// Output pin
const int PIN_OUT = 13;
// Sensor 1 pins
const int PIN_TRIG_1 = 5;
const int PIN_ECHO_1 = 6;
// Sensor 2 pins
const int PIN_TRIG_2 = 11;
const int PIN_ECHO_2 = 12;
// Sensor objects
DC_HC_SR04* ptr_hc_1;
DC_HC_SR04* ptr_hc_2;
// Thresholds
const uint16_t ic_thr_min_cm = 0;
const uint16_t ic_thr_max_cm = 85;
const uint16_t ic_thr_max_cm_3 = 90;
const bool ic_inverted = false;
const unsigned long DS_TIMEOUT_C = 200;
// Input activation controllers
IC_DistanceBasic* ptr_ic_1;  // Each sensor
IC_DistanceBasic* ptr_ic_2;  // Each sensor
IC_DistanceBasic* ptr_ic_3;  // Average of distances (to cover middle)
// Filter
FilterUpDn *ptr_fltr;
const uint8_t fltr_min = 0;
const uint8_t fltr_max = 5;
const bool fltr_inverted = false;

// Distance measurement
uint16_t dist_1;
uint16_t dist_2;
// Input activation verdict - from single measurement
bool active_1;
bool active_2;
bool active_3;
bool activation;
// Filtered verdict
bool out_state;


void setup()
{
    // // Debug
    // Serial.begin(115200);
    // Serial.println("Setup start");

    // Create objects
    // Distance sensors
    ptr_hc_1 = new DC_HC_SR04(PIN_TRIG_1, PIN_ECHO_1, DS_TIMEOUT_C);
    ptr_hc_2 = new DC_HC_SR04(PIN_TRIG_2, PIN_ECHO_2, DS_TIMEOUT_C);
    // Activation controllers
    ptr_ic_1 = new IC_DistanceBasic(ic_thr_min_cm, ic_thr_max_cm, ic_inverted);
    ptr_ic_2 = new IC_DistanceBasic(ic_thr_min_cm, ic_thr_max_cm, ic_inverted);
    ptr_ic_3 = new IC_DistanceBasic(ic_thr_min_cm, ic_thr_max_cm, ic_inverted);
    // Up and down filter
    ptr_fltr = new FilterUpDn(fltr_min, fltr_max, fltr_inverted);
    // Set up pins
    pinMode(PIN_OUT, OUTPUT);

    // Default output value
    digitalWrite(PIN_OUT, LOW);
    out_state = false;

    // // Debug
    // Serial.println("Setup done");
}

void loop()
{
    // Get measurements
    dist_1 = ptr_hc_1->get_distance_cm();
    delay(15);
    dist_2 = ptr_hc_2->get_distance_cm();
    // Upload measurements
    ptr_ic_1->upload_distance(dist_1);
    ptr_ic_2->upload_distance(dist_2);
    ptr_ic_3->upload_distance( (dist_1 + dist_2) >> 1 );
    // Get states
    active_1 = ptr_ic_1->get_state();
    active_2 = ptr_ic_2->get_state();
    active_3 = ptr_ic_3->get_state();
    // Create master flag
    activation = active_1 || active_2 || active_3;
    // Update up and down filter
    ptr_fltr->update(activation);
    // Drive outputs
    if (out_state ^ ptr_fltr->get_state())
    {
        out_state = !out_state;
        digitalWrite(PIN_OUT, out_state);
    }

    // Serial.print(dist_1);
    // Serial.print(",");
    // Serial.print(dist_2);
    // Serial.print(",");
    // Serial.print(active_1);
    // Serial.print(",");
    // Serial.print(active_2);
    // Serial.print(",");
    // Serial.println(out_state);
}
