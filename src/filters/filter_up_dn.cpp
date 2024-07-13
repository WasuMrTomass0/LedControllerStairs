#include "filter_up_dn.h"

FilterUpDn::FilterUpDn(int min_val, int max_val, bool inverted)
{
    m_min = min_val;
    m_max = max_val;
    m_inverted = inverted;
    reset();
}

FilterUpDn::~FilterUpDn()
{

}

bool FilterUpDn::update(bool state)
{
    if (state)
    {
        ++m_cnt;
        if(m_cnt >= m_max)
        {
            m_cnt = m_max;
            m_state = !m_inverted;
        }
    }
    else
    {
        --m_cnt;
        if(m_cnt <= m_min)
        {
            m_cnt = m_min;
            m_state = m_inverted;
        }
    }

    return m_state ^ m_inverted;
}

void FilterUpDn::reset()
{
    m_state = m_inverted;
    m_cnt = m_inverted ? m_max : m_min;
}

bool FilterUpDn::get_state()
{
    return m_state ^ m_inverted;
}
