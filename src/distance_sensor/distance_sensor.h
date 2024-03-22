#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <stdint.h>
#include <Arduino.h>


class DistanceSensor
{
public:
    // Destructor
    ~DistanceSensor();

    // Return distance
    virtual uint16_t get_distance_m()  = 0;
    virtual uint16_t get_distance_cm() = 0;
    virtual uint16_t get_distance_mm() = 0;
};

#endif  // DISTANCE_SENSOR_H
