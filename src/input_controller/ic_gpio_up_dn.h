#ifndef IC_GPIO_UP_DN_H
#define IC_GPIO_UP_DN_H

#include <stdint.h>
#include "input_controller.h"
#include "../common/filter_up_dn.h"


class IC_GPIO_UP_DN : public InputController
{
protected:
    const uint8_t m_pin;
    FilterUpDn *m_fltr;

public:
    // Constructor
    IC_GPIO_UP_DN(uint8_t pin, int min_val, int max_val, bool inverted);

    // Destructor
    ~IC_GPIO_UP_DN();

    // Return state - true=activated
    bool get_state() override;
};

#endif  // IC_GPIO_UP_DN_H
