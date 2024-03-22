#include "pc_pca9685.h"


// Constructor
PC_PCA9685::PC_PCA9685(uint16_t *ptr_bc, const uint16_t num_leds)
    : PWMController(ptr_bc, num_leds)
{
    // Join as controller (no address specified)
    // Wire.begin();
    setup();
}

// Destructor
PC_PCA9685::~PC_PCA9685()
{
    // Wire.end();
}

// Main logic
void PC_PCA9685::main()
{
    // TODO: Debug .setPWM() method and implement autoincrement method

    // Write data
    for (uint8_t i = 0; i < C_NUM_LEDS; ++i)
    {
        uint16_t brightness = m_data_br[i];
        ada_pwm.setPWM(i, 0, brightness);
    }
 
    // uint8_t error;
    // // Start I2C transmission on LED0 register
    // Wire.beginTransmission(C_SLV_ADDR);
    // Wire.write(C_REG_LED0_ON_L);
    // // Write data
    // for (uint8_t i = 0; i < C_NUM_LEDS; ++i)
    // {
    //     uint16_t brightness = m_data_br[i];
    //     Wire.write(0x01);               // ON  - byte 0     // TODO: 0x00 or 0x01?
    //     Wire.write(0x00);               // ON  - byte 1
    //     Wire.write(brightness & 0xFF);  // OFF - byte 0
    //     Wire.write(brightness >> 8);    // OFF - byte 1
    // }
    // error = Wire.endTransmission();
}

void PC_PCA9685::setup()
{
    ada_pwm.begin();
    ada_pwm.setPWMFreq(1600);

    // uint8_t error;
    // // MODE1
    // Wire.beginTransmission(C_SLV_ADDR);
    // Wire.write(C_REG_MODE1);
    // Wire.write(C_DEFAULT_MODE1);
    // error = Wire.endTransmission();
    // // MODE2
    // Wire.beginTransmission(C_SLV_ADDR);
    // Wire.write(C_REG_MODE2);
    // Wire.write(C_DEFAULT_MODE2);
    // error = Wire.endTransmission();
}
