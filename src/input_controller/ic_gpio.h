#ifndef IC_GPIO_H
#define IC_GPIO_H

#include <stdint.h>
#include "input_controller.h"


class IC_GPIO : public InputController
{
protected:
    const uint8_t m_pin;

public:
    // Constructor
    IC_GPIO(uint8_t pin);

    // Destructor
    ~IC_GPIO();

    // Return state - true=activated
    bool get_state() override;
};

#endif  // IC_GPIO_H
