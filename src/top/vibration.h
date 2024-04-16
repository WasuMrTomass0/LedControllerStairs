const int PIN_DATA = 2;
int cnt = 0;
int local_max = 0;
int local_window = 1024;
uint8_t read_state;


void setup() {
    pinMode(PIN_DATA, INPUT);    
    Serial.begin(115200);
}

void loop() {

    // Window
    local_max = 0;
    for (size_t i = 0; i < local_window; ++i)
    {
        read_state = digitalRead(PIN_DATA);
        
        local_max = local_max + read_state;
    
        cnt = cnt + (read_state ? 1 : -1);
        cnt = max(0, cnt);
    }

    // Debug
    Serial.print(read_state);
    Serial.print(",");
    Serial.print(local_max);
    Serial.print(",");
    Serial.println(cnt);
}
