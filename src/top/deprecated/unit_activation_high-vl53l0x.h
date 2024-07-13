#include "../distance_sensor/distance_sensor.h"
#include "../distance_sensor/dc_vl53l0x.h"
#include "../input_controller/input_controller.h"
#include "../input_controller/ic_distance_basic.h"
#include "../filters/filter_up_dn.h"
#include "../timer/timer.h"

#define DEBUG


// Output pin
const int PIN_OUT = 12;
// Sensor 1 pins
const int PIN_SCL = A5;  // Non editable
const int PIN_SDA = A4;  // Non editable
const int PIN_OUT_1 = 4;
// Sensor objects
DC_VL53L0X* ptr_ds_1;
const unsigned long DS_TIMEOUT_MS_C = 5000;
const unsigned long DS_INTERVAL_MS_C = 0;
const bool DS_REPEAT_INIT_C = true;
// Thresholds
const uint16_t ic_thr_min_cm = 0;
const uint16_t ic_thr_max_cm = 250;
const bool ic_inverted = false;
// Input activation controllers
IC_DistanceBasic* ptr_ic_1;  // Each sensor
// Filter
FilterUpDn *ptr_fltr;
const uint8_t fltr_min = 0;
const uint8_t fltr_max = 5;
const bool fltr_inverted = false;

// Distance measurement
uint16_t dist_1;
// Input activation verdict - from single measurement
bool active_1;
// Filtered verdict
bool out_state;


void setup()
{
#ifdef DEBUG
    // Debug
    Serial.begin(115200);
    Serial.println("Setup start");
#endif

    // Create objects
    // Distance sensors
    ptr_ds_1 = new DC_VL53L0X(PIN_SCL, PIN_SDA, DS_TIMEOUT_MS_C, DS_INTERVAL_MS_C, DS_REPEAT_INIT_C);
    // Activation controllers
    ptr_ic_1 = new IC_DistanceBasic(ic_thr_min_cm, ic_thr_max_cm, ic_inverted);
    // Up and down filter
    ptr_fltr = new FilterUpDn(fltr_min, fltr_max, fltr_inverted);
    // Set up pins
    pinMode(PIN_OUT, OUTPUT);

    // Default output value
    digitalWrite(PIN_OUT, LOW);
    out_state = false;

#ifdef DEBUG
    // Debug
    Serial.println("Setup done");
#endif
}

void loop()
{
    // Get measurements
    // dist_1 = ptr_ds_1->get_distance_cm();
    dist_1 = ptr_ds_1->get_raw_distance();
    // Upload measurements
    ptr_ic_1->upload_distance(dist_1);
    // Get states
    active_1 = ptr_ic_1->get_state();
    // Update up and down filter
    ptr_fltr->update(active_1);
    // Drive outputs
    if (out_state ^ ptr_fltr->get_state())
    {
        out_state = !out_state;
        digitalWrite(PIN_OUT, out_state);
    }

#ifdef DEBUG
    Serial.print(dist_1);
    Serial.print(",");
    Serial.print(active_1);
    Serial.print(",");
    Serial.println(out_state);
#endif
}
