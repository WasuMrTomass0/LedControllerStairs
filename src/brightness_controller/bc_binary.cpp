#include "bc_binary.h"


// Constructor
BC_Binary::BC_Binary(uint16_t *ptr_bc, uint16_t *ptr_ac, const uint16_t num_leds) 
    : BrightnessController(ptr_bc, ptr_ac, num_leds)
{

}

// Destructor
BC_Binary::~BC_Binary()
{

}

// Main logic
void BC_Binary::main()
{
    uint16_t ac_value = *m_data_ac;
    for (uint8_t i = 0; i < C_NUM_LEDS; ++i)
    {
        m_data_br[i] = ac_value & 0x01 ? m_br_max : m_br_min;
        ac_value = ac_value >> 1;
    }
}
