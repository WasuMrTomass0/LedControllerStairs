#ifndef PWM_CONTROLLER_H
#define PWM_CONTROLLER_H

#include <stdint.h>


class PWMController
{
protected:
    uint16_t *m_data_br;     // Brightness data
    const uint16_t C_NUM_LEDS;
    bool m_invert_order = 0;    // Invert order of steps
    bool m_invert_state = 0;    // Invert values (0x00 -> 0xFF, etc)

public:
    // Constructor
    PWMController(uint16_t *ptr_bc, const uint16_t num_leds);

    // Destructor
    virtual ~PWMController();

    // Main logic
    virtual void main() = 0;

    // Set invert order
    void set_invert_order(bool value);
    
    // Set invert state
    void set_invert_state(bool value);

    // Get invert order
    bool get_invert_order();
    
    // Get invert state
    bool get_invert_state();
};

#endif  // PWM_CONTROLLER_H
