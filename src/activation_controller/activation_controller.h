#ifndef ACTIVATION_CONTROLLER_H
#define ACTIVATION_CONTROLLER_H

#include <stdint.h>


class ActivationController
{
protected:
    uint16_t *m_data;
    const uint16_t C_MAX = 0xFFFF;
    const uint16_t C_MIN = 0x0;

public:
    // Constructor
    ActivationController(uint16_t *data_ptr);

    // Destructor
    ~ActivationController();

    // Main logic
    virtual void main(bool stateLow, bool stateHigh) = 0;
};

#endif  // ACTIVATION_CONTROLLER_H
