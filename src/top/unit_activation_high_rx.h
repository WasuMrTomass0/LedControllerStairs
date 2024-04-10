// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
const int I_PIN_RX    = 11;  // Default pin used by RH_ASK
const int O_PIN_STATE = 2;
// Set buffer to size of expected message
const uint8_t STATE_ON_C  = 5;
const uint8_t STATE_OFF_C = 9;
const char msg_len = 1;
uint8_t buf[msg_len];
uint8_t buflen = sizeof(buf);
// Helper
uint16_t cnt;


void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Pin setup
    pinMode(O_PIN_STATE, OUTPUT);
    // Helper
    cnt = 0;
}
 

void loop()
{
    
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
        // Control output based on message
        if (buf[0] == STATE_ON_C)
        {
            digitalWrite(O_PIN_STATE, HIGH);
            // Set cnt to max value
            cnt = 0xFFFF;
        }
        else if (buf[0] == STATE_OFF_C)
        {
            digitalWrite(O_PIN_STATE, LOW);
        }
        
    }
    else
    {
        // TODO: Clearing mechanism when no data is received
        if (cnt)
        {
            if (--cnt == 0)
            {
                digitalWrite(O_PIN_STATE, LOW);
            }
        }
    }
}