#include "ac_all_steps_as_one.h"


// Constructor
AC_AllStepsAsOne::AC_AllStepsAsOne(uint16_t *data_ptr, unsigned long active_pd) 
    : ActivationController(data_ptr)
{
    m_active_pd = active_pd;
}

// Destructor
AC_AllStepsAsOne::~AC_AllStepsAsOne()
{

}

// Main logic
void AC_AllStepsAsOne::main(bool stateLow, bool stateHigh)
{
    if (stateLow || stateHigh)
    {
        Timer::update_timestamp(&m_active_ts);
        activate_all();
    }
    else
    {
        if (Timer::is_time_elapsed(m_active_ts, m_active_pd))
        {
            deactivate_all();
        }
    }
}

// Activate all steps
void AC_AllStepsAsOne::activate_all()
{
    *m_data = C_MAX;
}

// Deactivate all steps
void AC_AllStepsAsOne::deactivate_all()
{
    *m_data = C_MIN;
}
