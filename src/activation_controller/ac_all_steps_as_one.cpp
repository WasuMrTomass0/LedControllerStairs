#include "ac_all_steps_as_one.h"


// Constructor
AC_AllStepsAsOne::AC_AllStepsAsOne(uint16_t *data_ptr) 
    : ActivationController(data_ptr)
{

}

// Destructor
AC_AllStepsAsOne::~AC_AllStepsAsOne()
{

}

// Main logic
void AC_AllStepsAsOne::main(bool stateLow, bool stateHigh)
{
    // TODO: Add hold time when in ON state. Right now it is deactivating lights right away
    if (stateLow || stateHigh)
    {
        activate_all();
    }
    else
    {
        deactivate_all();
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
