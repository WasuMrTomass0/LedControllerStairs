#include "timer.h"

// Create static field
unsigned long Timer::m_now = 0;

// Update current time in iteration
void Timer::update_time()
{
    Timer::m_now = millis();
}

// Update given timestamp with 'current' time
void Timer::update_timestamp(unsigned long *ptr)
{
    *ptr = Timer::m_now;
}

// Check if time is elapsed using given timestamp as 'now'
bool Timer::is_time_elapsed(unsigned long curr, unsigned long prev, unsigned long period)
{
    return curr - prev >= period;
}

// Check if time is elapsed using timestamp m_now
bool Timer::is_time_elapsed(unsigned long prev, unsigned long period)
{
    return Timer::m_now - prev >= period;
}

// Check if time is elapsed using timestamp m_now, update if it is elapsed
bool Timer::is_time_elapsed_with_update(unsigned long *prev, unsigned long period)
{
    bool res = Timer::m_now - *prev >= period;
    if (res)
    {
        Timer::update_timestamp(prev);
    }
    return res;
    
}

// Check if time variables has overflowed
bool Timer::is_time_overflowed(unsigned long curr, unsigned long prev)
{
    return prev > curr;
}