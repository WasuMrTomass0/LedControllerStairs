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
