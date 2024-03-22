#include "ic_gpio.h"


// Constructor
IC_GPIO::IC_GPIO(uint8_t pin)
    : m_pin(pin)
{
    pinMode(m_pin, INPUT);
}

// Destructor
IC_GPIO::~IC_GPIO()
{

}

// Return state - true=activated
bool IC_GPIO::get_state()
{
    return digitalRead(m_pin);
}
