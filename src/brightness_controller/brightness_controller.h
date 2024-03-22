#ifndef BRIGHTNESS_CONTROLLER_H
#define BRIGHTNESS_CONTROLLER_H

#include <stdint.h>


class BrightnessController
{
protected:
    uint16_t *m_data_br;     // Brightness data
    uint16_t *m_data_ac;     // Activation data
    const uint16_t C_NUM_LEDS;

    const uint16_t C_12BIT_MAX = 0x0FFF; 
    uint16_t m_br_max;
    uint16_t m_br_min;

public:
    // Constructor
    BrightnessController(uint16_t *ptr_bc, uint16_t *ptr_ac, const uint16_t num_leds);

    // Destructor
    ~BrightnessController();

    // Main logic
    virtual void main() = 0;

    // Settings control
    void set_max_brightness(uint16_t val);
    void set_min_brightness(uint16_t val);
};

#endif  // BRIGHTNESS_CONTROLLER_H
