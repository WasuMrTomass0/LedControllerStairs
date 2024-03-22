#include "../activation_controller/activation_controller.h"
#include "../activation_controller/ac_all_steps_as_one.h"
#include "../brightness_controller/brightness_controller.h"
#include "../brightness_controller/bc_binary.h"
#include "../input_controller/input_controller.h"
#include "../input_controller/ic_gpio.h"
#include "../input_controller/ic_gpio_up_dn.h"
#include "../pwm_controller/pwm_controller.h"
#include "../pwm_controller/pc_pca9685.h"
#include "../timer/timer.h"

// Config
const uint8_t NUM_STEPS = 16;
// Pins ESP32 DevKit1
// SCL - GPIO 22
// SDA - GPIO 21
const uint8_t PIN_IC_L = 23;    // Lowest step activation
const uint8_t PIN_IC_H = 19;   // Highest step activation
// // Pins Nodemcu v3
// const uint8_t PIN_IC_L = 13;    // D7   // Lowest step activation
// const uint8_t PIN_IC_H = 15;    // D8   // Highest step activation
// // Pins Nano
// const uint8_t PIN_IC_L = 2;    // D2   // Lowest step activation
//const uint8_t PIN_IC_H = 3;    // D3   // Highest step activation
// Globals
uint16_t ac_steps;              // Each bit represents one step
uint16_t bc_steps[NUM_STEPS];   // Each element represents one step
// Control objects
InputController*      ptr_ic_low;
InputController*      ptr_ic_high;
AC_AllStepsAsOne*     ptr_ac;
BrightnessController* ptr_bc;
PWMController*        ptr_pc;
// Timestamps per section - (ts timestamp)
unsigned long ts_ic = 0;
unsigned long ts_ac = 0;
unsigned long ts_bc = 0;
unsigned long ts_pc = 0;
// Periods per section 1sec / freq - (pd period)
const unsigned pd_ic = 1000 / 10;
const unsigned pd_ac = 1000 / 100;
const unsigned pd_bc = 1000 / 100;
const unsigned pd_pc = 1000 / 100;
// Objects settings
const unsigned long active_pd = 10 * 1000;  // Active LEDs period
// Other
bool ic_low;
bool ic_high;



void setup()
{
  // // Debug
  // Serial.begin(115200);
  // Serial.println("Setup start");

  ptr_ic_low  = new IC_GPIO(PIN_IC_L);
  ptr_ic_high = new IC_GPIO(PIN_IC_H);
  // ptr_ic_low  = new IC_GPIO_UP_DN(PIN_IC_L, 0, 10, false);
  // ptr_ic_high = new IC_GPIO_UP_DN(PIN_IC_H, 0, 10, false);
  ptr_ac      = new AC_AllStepsAsOne(&ac_steps, active_pd);
  ptr_bc      = new BC_Binary(bc_steps, &ac_steps, NUM_STEPS);
  ptr_pc      = new PC_PCA9685(bc_steps, NUM_STEPS);

  // Serial.println("Setting max brightness");
  ptr_bc->set_max_brightness(0x0FFF);

  // // Debug
  // Serial.println("Setup done");
}

void loop()
{
  
  // Update time variable
  Timer::update_time();
  
  // Inputs
  if (Timer::is_time_elapsed(ts_ic, pd_ic))
  {
    ic_low  = ptr_ic_low->get_state();
    ic_high = ptr_ic_high->get_state();
    Timer::update_timestamp(&ts_ic);
  }

  // Activation
  if (Timer::is_time_elapsed(ts_ac, pd_ac))
  {
    ptr_ac->main(ic_low, ic_high);
    Timer::update_timestamp(&ts_ac);
  }

  // Brigthness
  if (Timer::is_time_elapsed(ts_bc, pd_bc))
  {
    ptr_bc->main();
    Timer::update_timestamp(&ts_bc);
  }

  // PWM
  if (Timer::is_time_elapsed(ts_pc, pd_pc))
  {
    ptr_pc->main();
    Timer::update_timestamp(&ts_pc);
  }
}
