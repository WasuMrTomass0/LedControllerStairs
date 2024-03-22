#ifndef DISTANCE_CONTROLLER_H
#define DISTANCE_CONTROLLER_H

#include <stdint.h>
#include <Arduino.h>


class DistanceController
{
public:
    // Destructor
    ~DistanceController();

    // Return distance
    virtual uint16_t get_distance_m()  = 0;
    virtual uint16_t get_distance_cm() = 0;
    virtual uint16_t get_distance_mm() = 0;
};

#endif  // DISTANCE_CONTROLLER_H
