#ifndef FILTER_UP_DN_H
#define FILTER_UP_DN_H

#include <stdint.h>

class FilterUpDn
{
public:
    FilterUpDn(int min_val, int max_val, bool inverted);

    ~FilterUpDn();

    bool update(bool state);

    void reset();

    bool get_state();

protected:
    bool m_inverted;
    bool m_state;
    int m_cnt;
    int m_min;
    int m_max;

};

#endif // FILTER_UP_DN_H
