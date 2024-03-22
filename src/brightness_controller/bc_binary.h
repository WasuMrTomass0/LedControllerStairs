#ifndef BC_BINARY_H
#define BC_BINARY_H

#include <stdint.h>
#include "brightness_controller.h"


class BC_Binary : public BrightnessController
{
protected:

public:
    // Constructor
    BC_Binary(uint16_t *ptr_bc, uint16_t *ptr_ac, const uint16_t num_leds);

    // Destructor
    ~BC_Binary();

    // Main logic
    virtual void main();
};

#endif  // BC_BINARY_H
