#include "ic_gpio_up_dn.h"


// Constructor
IC_GPIO_UP_DN::IC_GPIO_UP_DN(uint8_t pin, int min_val, int max_val, bool inverted)
    : m_pin(pin)
{
    pinMode(m_pin, INPUT);
    m_fltr = new FilterUpDn(min_val, max_val, inverted);
}

// Destructor
IC_GPIO_UP_DN::~IC_GPIO_UP_DN()
{

}

// Return state - true=activated
bool IC_GPIO_UP_DN::get_state()
{
    return m_fltr->update(digitalRead(m_pin));
}
