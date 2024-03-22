#include "brightness_controller.h"


BrightnessController::BrightnessController(uint16_t *ptr_bc, uint16_t *ptr_ac, const uint16_t num_leds)
    : C_NUM_LEDS(num_leds)
{
    m_data_br = ptr_bc;
    m_data_ac = ptr_ac;
    // Defaults
    m_br_max = 0xFFFF;
    m_br_min = 0x0;
}

BrightnessController:: ~BrightnessController()
{

}

void BrightnessController::set_max_brightness(uint16_t val)
{
    // Minimum out of val and C_12BIT_MAX
    m_br_max = C_12BIT_MAX > val ? val : C_12BIT_MAX;
}

void BrightnessController::set_min_brightness(uint16_t val)
{
    // Minimum out of val and C_12BIT_MAX
    m_br_min = C_12BIT_MAX > val ? val : C_12BIT_MAX;
    // TODO: What if val is greater than m_br_max?
}
