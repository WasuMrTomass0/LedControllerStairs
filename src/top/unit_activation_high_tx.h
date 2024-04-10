// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library
#include <SPI.h>

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
const uint8_t STATE_ON_C  = 5;
const uint8_t STATE_OFF_C = 9;
const uint8_t *msg_on  = {STATE_ON_C};
const uint8_t *msg_off = {STATE_OFF_C};
const char msg_len = 1;
const int O_PIN_TX  = 12;  // Default pin used by RH_ASK
const int I_PIN_PIR = 2;   // PIR's output (use voltage divider)
// Helpers
const uint8_t NUM_REPEATS_C = 5;
// uint8_t cnt_on;
uint8_t cnt_off;


void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Pin setup
    pinMode(I_PIN_PIR, INPUT);
}

void loop()
{
    // Monitor state
    if (digitalRead(I_PIN_PIR))
    {
        // Send packets continously
        rf_driver.send(msg_on, msg_len);
        rf_driver.waitPacketSent();
        cnt_off = NUM_REPEATS_C;
        delay(10);
    }
    else
    {
        // Send few packets when state is low
        if (cnt_off)
        {
            rf_driver.send(msg_off, msg_len);
            rf_driver.waitPacketSent();
            cnt_off--;
            delay(10);
        }
    }
}
