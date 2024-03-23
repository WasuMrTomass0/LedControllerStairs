#include "pwm_controller.h"


// Constructor
PWMController::PWMController(uint16_t *ptr_bc, const uint16_t num_leds)
    : C_NUM_LEDS(num_leds)
{
    m_data_br = ptr_bc;
}

// Destructor
PWMController::~PWMController()
{
    
}

// Set invert order
void PWMController::set_invert_order(bool value)
{
    m_invert_order = value;
}

// Set invert state
void PWMController::set_invert_state(bool value)
{
    m_invert_state = value;
}

// Get invert order
bool PWMController::get_invert_order()
{
    return m_invert_order;
}

// Get invert state
bool PWMController::get_invert_state()
{
    return m_invert_state;
}
