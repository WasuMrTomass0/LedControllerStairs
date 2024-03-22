#ifndef AC_ALL_STEPS_AS_ONE_H
#define AC_ALL_STEPS_AS_ONE_H

#include <stdint.h>
#include "activation_controller.h"


class AC_AllStepsAsOne : public ActivationController
{
protected:

public:
    // Constructor
    AC_AllStepsAsOne(uint16_t *data_ptr) ;

    // Destructor
    ~AC_AllStepsAsOne();

    // Main logic
    virtual void main(bool stateLow, bool stateHigh);

protected:
    // Activate all steps
    void activate_all();

    // Deactivate all steps
    void deactivate_all();
};

#endif  // AC_ALL_STEPS_AS_ONE_H
