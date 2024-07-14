#ifndef OUTPUT_CONTROLLER_H
#define OUTPUT_CONTROLLER_H

#include <stdint.h>

class OutputController
{
protected:
    const bool M_ACTIVE_STATE_C;

public:
    // Constructor
    OutputController(bool active_state);

    // Destructor
    ~OutputController();

    // Modify state
    virtual void update_state(bool state) = 0;
    virtual void clear() = 0;
    virtual void set() = 0;
};

#endif  // OUTPUT_CONTROLLER_H
