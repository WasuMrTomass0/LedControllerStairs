#include "../distance_sensor/distance_sensor.h"
#include "../distance_sensor/dc_hc_sr04.h"
#include "../input_controller/input_controller.h"
#include "../output_controller/output_controller.h"
#include "../output_controller/oc_gpio.h"
#include "../input_controller/ic_distance_basic.h"
#include "../filters/filter_up_dn.h"
#include "../timer/timer.h"

// #define DEBUG

// Sensor objects
DC_HC_SR04* ptr_hc_1;
DC_HC_SR04* ptr_hc_2;
const unsigned long DS_TIMEOUT_C = 50000;
// Sensor 1 pins
const int DC_PIN_TRIG_1 = 5;
const int DC_PIN_ECHO_1 = 6;
// Sensor 2 pins
const int DC_PIN_TRIG_2 = 11;
const int DC_PIN_ECHO_2 = 12;

// Input activation controllers
IC_DistanceBasic* ptr_ic_1;  // Each sensor
IC_DistanceBasic* ptr_ic_2;  // Each sensor
IC_DistanceBasic* ptr_ic_3;  // Average of distances (to cover middle)
const bool IC_INVERTED_C = false;
// Thresholds
const uint16_t IC_THR_MIN_CM_C = 0;
const uint16_t IC_THR_MAX_CM_C = 85;

// Filter
FilterUpDn *ptr_fltr;
const uint8_t FLTR_MIN_C = 0;
const uint8_t FLTR_MAX_C = 5;
const bool FLTR_INVERTED_C = false;

// Output controller
OutputController* ptr_oc;
const int OC_PIN_C = 13;
const int OC_ACTIVE_STATE_C = true;
const int OC_INTERVAL_ON_MS_C = 100;
const int OC_INTERVAL_OFF_MS_C = 100;

// Distance measurement
uint16_t dist_1;
uint16_t dist_2;
// Input activation verdict - from single measurement
bool is_active_1;
bool is_active_2;
bool is_active_3;
bool is_activated;
// Timer restriction to read distance once per 20ms
// and not use delay(15) function
const int DELAY_MS_C = 15;
unsigned long last_measurement_ts = 0;
uint8_t last_measurement_id = 0;


void setup()
{
#ifdef DEBUG
    Serial.begin(115200);
    Serial.println("Setup start");
#endif

    // Create objects
    // Distance sensors
    ptr_hc_1 = new DC_HC_SR04(DC_PIN_TRIG_1, DC_PIN_ECHO_1, DS_TIMEOUT_C);
    ptr_hc_2 = new DC_HC_SR04(DC_PIN_TRIG_2, DC_PIN_ECHO_2, DS_TIMEOUT_C);
    // Activation controllers
    ptr_ic_1 = new IC_DistanceBasic(IC_THR_MIN_CM_C, IC_THR_MAX_CM_C, IC_INVERTED_C);
    ptr_ic_2 = new IC_DistanceBasic(IC_THR_MIN_CM_C, IC_THR_MAX_CM_C, IC_INVERTED_C);
    ptr_ic_3 = new IC_DistanceBasic(IC_THR_MIN_CM_C, IC_THR_MAX_CM_C, IC_INVERTED_C);
    // Up and down filter
    ptr_fltr = new FilterUpDn(FLTR_MIN_C, FLTR_MAX_C, FLTR_INVERTED_C);
    // Output controller
    ptr_oc = new OC_GPIO(OC_PIN_C, OC_ACTIVE_STATE_C, OC_INTERVAL_ON_MS_C, OC_INTERVAL_OFF_MS_C);

#ifdef DEBUG
    Serial.println("Setup done");
#endif
}

void loop()
{
    // Update field storing current timestamp
    Timer::update_time();

    // Check if specified time already passed from other measurement
    if (last_measurement_id != 1 && Timer::is_time_elapsed_with_update(&last_measurement_ts, DELAY_MS_C))
    {
        // Get measurement - id 1
        dist_1 = ptr_hc_1->get_distance_cm();
        last_measurement_id = 1;
    }

    // Check if specified time already passed from other measurement
    if (last_measurement_id != 2 && Timer::is_time_elapsed_with_update(&last_measurement_ts, DELAY_MS_C))
    {
        // Get measurement - id 2
        dist_1 = ptr_hc_2->get_distance_cm();
        last_measurement_id = 2;
    }

    // Process easurements
    if (last_measurement_id == 2)
    {
        // Clear measurement
        last_measurement_id = 0;
        // Upload measurements
        ptr_ic_1->upload_distance(dist_1);
        ptr_ic_2->upload_distance(dist_2);
        ptr_ic_3->upload_distance( (dist_1 + dist_2) >> 1 );
        // Get states
        is_active_1 = ptr_ic_1->get_state();
        is_active_2 = ptr_ic_2->get_state();
        is_active_3 = ptr_ic_3->get_state();
        // Create master flag
        is_activated = is_active_1 || is_active_2 || is_active_3;
        // Update up and down filter
        ptr_fltr->update(is_activated);
        // Update output controller
        ptr_oc->update_state( ptr_fltr->get_state() );
    }

#ifdef DEBUG
    Serial.print(dist_1);
    Serial.print(",");
    Serial.print(is_active_1);
    Serial.print(",");
    Serial.println(out_state);
#endif

}
