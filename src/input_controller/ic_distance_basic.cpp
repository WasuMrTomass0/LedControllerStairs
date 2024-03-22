#include "ic_distance_basic.h"


// Constructor
IC_DistanceBasic::IC_DistanceBasic(uint16_t thr_min, uint16_t thr_max, bool inverted)
{
    m_thr_min  = thr_min;
    m_thr_max  = thr_max;
    m_inverted = inverted;
}

// Destructor
IC_DistanceBasic::~IC_DistanceBasic()
{

}

// Return state - true=activated
bool IC_DistanceBasic::get_state()
{
    return m_inverted ^ (m_thr_min <= m_distance && m_distance <= m_thr_max);
}

// Upload measurement
void IC_DistanceBasic::upload_distance(uint16_t distance)
{
    m_distance = distance;
}
