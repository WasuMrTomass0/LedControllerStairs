#ifndef PC_PCA9685_H
#define PC_PCA9685_H

#include <stdint.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "pwm_controller.h"


class PC_PCA9685 : public PWMController
{
protected:    
    // Slave address
    const uint8_t C_SLV_ADDR = 0x40;
    // Registers
    const uint8_t C_REG_MODE1 = 0x00;
    const uint8_t C_REG_MODE2 = 0x01;
    const uint8_t C_REG_ALLCALLADR = 0x05;
    // All LEDs
    const uint8_t C_REG_ALL_LED_ON_L = 0xFA;
    const uint8_t C_REG_ALL_LED_ON_H = 0xFB;
    const uint8_t C_REG_ALL_LED_OFF_L = 0xFC;
    const uint8_t C_REG_ALL_LED_OFF_H = 0xFD;
    // Single LED
    const uint8_t C_REG_LED0_ON_L = 0x06;   // First
    const uint8_t C_REG_LED15_OFF_H = 0x45; // Last

    // Setup values
    const uint8_t C_DEFAULT_MODE1 = 0x21; // enable autoincrement and write to all_on/all_off registers
    const uint8_t C_DEFAULT_MODE2 = 0x04; // PWM outputs change on ACK

    // Adafruit controller
    Adafruit_PWMServoDriver ada_pwm = Adafruit_PWMServoDriver(C_SLV_ADDR);

public:
    // Constructor
    PC_PCA9685(uint16_t *ptr_bc, const uint16_t num_leds);

    // Destructor
    ~PC_PCA9685();

    // Main logic
    void main() override;
    
protected:
    void setup();
};

#endif  // PC_PCA9685_H
