#pragma once

#include "esphome/core/component.h"

// #define DEBUG

namespace esphome {
namespace empty_component {


class LedControllerStairs : public Component
{

protected:
    /* data */

public:
    LedControllerStairs();

    ~LedControllerStairs();

    void setup() override;

    void loop() override;

    void dump_config() override;

};

} // namespace empty_component
} // namespace esphome
