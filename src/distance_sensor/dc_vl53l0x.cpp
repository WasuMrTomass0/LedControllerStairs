#include "dc_vl53l0x.h"


// Constructor
DC_VL53L0X::DC_VL53L0X(uint8_t pin_scl, uint8_t pin_sda, unsigned long timeout, unsigned long interval, bool repeat_init)
    : m_pin_scl(pin_scl)
    , m_pin_sda(pin_sda)
    , m_timeout (timeout)
    , m_interval (interval)
    , m_repeat_init_if_failure (repeat_init)
{
    do
    {
        this->init();

#define DEBUG
#ifdef DEBUG
    if (this->is_ok())
    {
        Serial.println("DC_VL53L0X init succeded");
    }
    else
    {
        Serial.println("DC_VL53L0X init failed");
    }
#endif

    } while (!this->is_ok() && this->m_repeat_init_if_failure);
}

// Destructor
DC_VL53L0X::~DC_VL53L0X()
{

}

// Initialize sensor
bool DC_VL53L0X::init()
{
    // Wire.begin(this->m_pin_sda, this->m_pin_scl);
    Wire.begin();
    this->m_sensor.setTimeout(this->m_timeout);
    this->m_status = this->m_sensor.init();

    if (this->m_status)
    {
        if (this->m_interval == 0)
        {
            this->m_sensor.startContinuous();
        }
        else
        {
            this->m_sensor.startContinuous(this->m_interval);
        }
    }
    return this->m_status;
}

// Initialize sensor
bool DC_VL53L0X::is_ok()
{
    return this->m_status;
}

// Return distance in meters
uint16_t DC_VL53L0X::get_distance_m()
{
    return this->get_distance_mm() / 1000;
}

// Return distance in centimeters
uint16_t DC_VL53L0X::get_distance_cm()
{
    return this->get_distance_mm() / 10;
}

// Return raw distance measurement
uint16_t DC_VL53L0X::get_raw_distance()
{
    return this->m_sensor.readRangeContinuousMillimeters();
}

// Return distance in milimeters
uint16_t DC_VL53L0X::get_distance_mm()
{
    uint16_t x = this->get_raw_distance();
    if (this->m_sensor.timeoutOccurred() || x >= this->m_error_threshold)
    {
        return 0;
    }
    
    return x;
}
