#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
protected:
    static unsigned long m_now;

public:
    // Update current time in iteration
    static void update_time();

    // Update given timestamp with 'current' time
    static void update_timestamp(unsigned long *ptr);

    // Check if time is elapsed using given timestamp as 'now'
    static bool is_time_elapsed(unsigned long curr, unsigned long prev, unsigned long period);

    // Check if time is elapsed using timestamp m_now
    static bool is_time_elapsed(unsigned long prev, unsigned long period);

    // Check if time variables has overflowed
    static bool is_time_overflowed(unsigned long curr, unsigned long prev);

};

#endif  // TIMER_H
