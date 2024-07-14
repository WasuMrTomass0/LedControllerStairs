#include "oc_gpio.h"


// Constructor
OC_GPIO::OC_GPIO(uint8_t pin, bool active_state, unsigned long interval_on, unsigned long interval_off)
    : OutputController(active_state)
    , M_PIN_C(pin)
    , M_INTERVAL_ON_C(interval_on)
    , M_INTERVAL_OFF_C(interval_off)
{
    this->m_switch_on_ts  = 0;
    this->m_switch_off_ts = 0;
    pinMode(this->M_PIN_C, OUTPUT);
    this->clear();
}

// Destructor
OC_GPIO::~OC_GPIO()
{

}

// Update output state
void OC_GPIO::update_state(bool state)
{
    if (state)
    {
        set();
    }
    else
    {
        clear();
    }


}

// Set output state as inactive
void OC_GPIO::clear()
{
    // Check if change is needed
    if (this->m_state != !M_ACTIVE_STATE_C)
    {
        // Check if minimum time has passed
        if (Timer::is_time_elapsed_with_update(&this->m_switch_on_ts, this->M_INTERVAL_ON_C))
        {
            this->m_state = !M_ACTIVE_STATE_C;
            digitalWrite(this->M_PIN_C, this->m_state);
        }
    }
}

// Set output state as active
void OC_GPIO::set()
{
    // Check if change is needed
    if (this->m_state != M_ACTIVE_STATE_C)
    {
        // Check if minimum time has passed
        if (Timer::is_time_elapsed_with_update(&this->m_switch_off_ts, this->M_INTERVAL_OFF_C))
        {
            this->m_state = M_ACTIVE_STATE_C;
            digitalWrite(this->M_PIN_C, this->m_state);
        }
    }
}
