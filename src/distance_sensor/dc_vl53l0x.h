#ifndef DC_VL53L0X_H
#define DC_VL53L0X_H

#include <stdint.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "distance_sensor.h"


class DC_VL53L0X : public DistanceSensor
{
protected:
    // Config
    const uint8_t m_pin_scl;
    const uint8_t m_pin_sda;
    const unsigned long m_timeout;
    const unsigned long m_interval;
    const bool m_repeat_init_if_failure;
    const bool m_error_threshold = 8000;
    // Fields
    bool m_status;
    // Sensor handler
    VL53L0X m_sensor;

public:
    // Constructor
    DC_VL53L0X(uint8_t pin_scl, uint8_t pin_sda, unsigned long timeout, unsigned long interval, bool repeat_init);

    // Destructor
    ~DC_VL53L0X();

    // Initialize sensor
    bool init();

    // Status checker
    bool is_ok();

    // Return raw distance measurement
    uint16_t get_raw_distance();

    // Return distance in meters
    uint16_t get_distance_m() override;

    // Return distance in centimeters
    uint16_t get_distance_cm() override;

    // Return distance in milimeters
    uint16_t get_distance_mm() override;
};

#endif  // DC_VL53L0X
