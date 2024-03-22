#include "dc_hc_sr04.h"


// Constructor
DC_HC_SR04::DC_HC_SR04(uint8_t pin_trig, uint8_t pin_echo)
    : m_pin_trig(pin_trig)
    , m_pin_echo(pin_echo)
{
    pinMode(m_pin_trig, OUTPUT);
    pinMode(m_pin_echo, INPUT);
}

// Destructor
DC_HC_SR04::~DC_HC_SR04()
{

}

void DC_HC_SR04::update_duration()
{
    // Triger measurement
    digitalWrite(m_pin_trig, LOW);
    delayMicroseconds(2);
    digitalWrite(m_pin_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_pin_trig, LOW);
    // Record time travel
    m_duration = pulseIn(m_pin_echo, HIGH);

    Serial.println(m_duration);
}

// Return distance in meters
uint16_t DC_HC_SR04::get_distance_m()
{
    update_duration();
    return m_duration * CONV_M_C;
}

// Return distance in centimeters
uint16_t DC_HC_SR04::get_distance_cm()
{
    update_duration();
    return m_duration * CONV_CM_C;
}

// Return distance in milimeters
uint16_t DC_HC_SR04::get_distance_mm()
{
    update_duration();
    return m_duration * CONV_MM_C;
}
