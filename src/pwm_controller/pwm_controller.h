#ifndef PWM_CONTROLLER_H
#define PWM_CONTROLLER_H

#include <stdint.h>


class PWMController
{
protected:
    uint16_t *m_data_br;     // Brightness data
    const uint16_t C_NUM_LEDS;

public:
    // Constructor
    PWMController(uint16_t *ptr_bc, const uint16_t num_leds);

    // Destructor
    virtual ~PWMController();

    // Main logic
    virtual void main() = 0;
};

#endif  // PWM_CONTROLLER_H
