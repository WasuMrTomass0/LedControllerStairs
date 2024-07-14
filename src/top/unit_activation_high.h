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
DC_HC_SR04* ptr_dc;
const int DC_PIN_TRIG_C = 7;
const int DC_PIN_ECHO_C = 9;
const unsigned long DS_TIMEOUT_C = 100000;

// Input activation controllers
IC_DistanceBasic* ptr_ic;
const uint16_t IC_THR_MIN_CM_C = 0;
const uint16_t IC_THR_MAX_CM_C = 100;
const bool IC_INVERTED_C = false;

// Filter
FilterUpDn *ptr_fltr;
const uint8_t FILTR_MIN_C = 0;
const uint8_t FLTR_MAX_C = 5;
const bool FLTR_INVERTED_C = false;

// Output controller
OutputController* ptr_oc;
const int OC_PIN_C = 12;
const int OC_ACTIVE_STATE_C = true;
const int OC_INTERVAL_ON_MS_C = 100;
const int OC_INTERVAL_OFF_MS_C = 100;

// Distance measurement
uint16_t dist;
// Input activation verdict
bool is_active;
// Filtered verdict
bool out_state;
// Timer restriction to read distance once per 20ms
// and not use delay(20) function
const int DELAY_MS_C = 25;
unsigned long last_measurement_ts = 0;


void setup()
{
#ifdef DEBUG
    Serial.begin(115200);
    Serial.println("Setup start");
#endif

    // Create objects
    // Distance sensors
    ptr_dc = new DC_HC_SR04(DC_PIN_TRIG_C, DC_PIN_ECHO_C, DS_TIMEOUT_C);
    // Activation controllers
    ptr_ic = new IC_DistanceBasic(IC_THR_MIN_CM_C, IC_THR_MAX_CM_C, IC_INVERTED_C);
    // Up and down filter
    ptr_fltr = new FilterUpDn(FILTR_MIN_C, FLTR_MAX_C, FLTR_INVERTED_C);
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

    // Check if specified time already passed
    if (Timer::is_time_elapsed_with_update(&last_measurement_ts, DELAY_MS_C))
    {
        // Get measurements
        dist = ptr_dc->get_distance_cm();
        // Upload measurements
        ptr_ic->upload_distance(dist);
        // Get states
        is_active = ptr_ic->get_state();
        // Update up and down filter
        ptr_fltr->update(is_active);
        // Update output controller
        ptr_oc->update_state( ptr_fltr->get_state() );
    }

#ifdef DEBUG
    Serial.print(dist);
    Serial.print(",");
    Serial.print(is_active);
    Serial.print(",");
    Serial.println(out_state);
#endif

}
