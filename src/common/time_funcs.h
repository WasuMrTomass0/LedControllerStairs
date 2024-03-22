bool is_time_elapsed(unsigned long curr, unsigned long prev, unsigned long period)
{
    return curr - prev >= period;
}

bool is_time_overflowed(unsigned long curr, unsigned long prev)
{
    return prev > curr;
}
