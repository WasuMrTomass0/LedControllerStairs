#ifndef IC_DISTANCE_BASIC_H
#define IC_DISTANCE_BASIC_H

#include <stdint.h>
#include "input_controller.h"


class IC_DistanceBasic : public InputController
{
protected:
    uint16_t m_thr_min;
    uint16_t m_thr_max;
    bool m_inverted;
/*  if m_inverted is 0 then
        active when distance is between min and max
    if m_inverted is 1 then
        active when distance is outside of min and max*/
    // Measurement field
    uint16_t m_distance;

public:
    // Constructor
    IC_DistanceBasic(uint16_t thr_min, uint16_t thr_max, bool inverted);

    // Destructor
    ~IC_DistanceBasic();

    // Return state - true=activated
    bool get_state() override;

    // Upload measurement
    void upload_distance(uint16_t distance);
};

#endif  // IC_DISTANCE_BASIC_H
