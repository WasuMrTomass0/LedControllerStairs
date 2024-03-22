#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <stdint.h>
#include <Arduino.h>


class InputController
{
public:
    // Destructor
    ~InputController();

    // Return state - true=activated
    virtual bool get_state() = 0;
};

#endif  // INPUT_CONTROLLER_H
