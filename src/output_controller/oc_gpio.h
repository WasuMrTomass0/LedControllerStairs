#ifndef OC_GPIO_H
#define OC_GPIO_H

#include <stdint.h>
#include <Arduino.h>
#include "output_controller.h"
#include "../timer/timer.h"


class OC_GPIO : public OutputController
{
protected:
    // GPIO pin driven
    const uint8_t M_PIN_C;
    // Output state field
    bool m_state;
    // Minimum time output stays ON
    const unsigned long M_INTERVAL_ON_C;
    // Timestamp for rising edge
    unsigned long m_switch_on_ts;
    // Minimum time output stays OFF
    const unsigned long M_INTERVAL_OFF_C;
    // Timestamp for falling edge
    unsigned long m_switch_off_ts;

public:
    // Constructor
    OC_GPIO(uint8_t pin, bool active_state, unsigned long interval_on, unsigned long interval_off);

    // Destructor
    ~OC_GPIO();

    // Modify state
    void update_state(bool state) override;
    // Set output state as active
    void clear() override;
    // Set output state as inactive
    void set() override;
};

#endif  // OC_GPIO_H
