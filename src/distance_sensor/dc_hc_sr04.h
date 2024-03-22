#ifndef DC_HC_SR04_H
#define DC_HC_SR04_H

#include <stdint.h>
#include "distance_sensor.h"


class DC_HC_SR04 : public DistanceSensor
{
protected:
    // Config
    const uint8_t m_pin_trig;
    const uint8_t m_pin_echo;
    // Measurement variables
    float m_duration;
    // Const values
    const float CONV_M_C  = 0.001715;
    const float CONV_CM_C = 0.01715;
    const float CONV_MM_C = 0.1715;

    void update_duration();

public:
    // Constructor
    DC_HC_SR04(uint8_t pin_trig, uint8_t pin_echo);

    // Destructor
    ~DC_HC_SR04();

    // Return distance in meters
    uint16_t get_distance_m() override;

    // Return distance in centimeters
    uint16_t get_distance_cm() override;

    // Return distance in milimeters
    uint16_t get_distance_mm() override;
};

#endif  // DC_HC_SR04_H
