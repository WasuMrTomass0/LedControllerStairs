// #define TWO_DISTANCE_SENSORS_USED
//#define ONE_DISTANCE_SENSOR_USED
#define ONE_DISTANCE_SENSOR_USED_CREATE_DATASET

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
#ifdef ONE_DISTANCE_SENSOR_USED_CREATE_DATASET
#include "Settings.h"
#include "OutputBoolOneWire.h"
#include "Distance.h"
#include "GlobalFunctions.h"

Distance_HCSR04 DistanceSensor(PINOUT::S2_DIS_TRIG, PINOUT::S2_DIS_ECHO);
OutputBoolOneWire Output(PINOUT::S2_DIS_OUT_PIN);

void setup() {
	Serial.begin(115200);
	Serial.println("OK!");

	pinMode(PINOUT::DS_TRIG_BUTT, INPUT_PULLUP);
	pinMode(PINOUT::DS_DIR_BUTT, INPUT_PULLUP);
	pinMode(PINOUT::DS_BUZZER, OUTPUT);
	
	// Buzzer notiffication and test
	digitalWrite(PINOUT::DS_BUZZER, HIGH);
	delay(50);
	digitalWrite(PINOUT::DS_BUZZER, LOW);
}

unsigned cnt = 0;  // Dataset entry counter
void loop() {
	while (digitalRead(PINOUT::DS_TRIG_BUTT) == LOW)
	{
		delay(50);
	}
	// Start
	buzzer_blink(1);

	int lastRead = 0, currRead = 0, diff = 0; // Can't be unsigned if substraction is used
	while (digitalRead(PINOUT::DS_TRIG_BUTT) == HIGH)
	{
		lastRead = currRead;
		currRead = DistanceSensor.getDistance();
		diff = currRead - lastRead;
		
		// cnt, diff, currRead
		Serial.print(cnt); Serial.print(',');
		Serial.print(diff); Serial.print(',');
		Serial.print(currRead); Serial.println('.');
		delay(25); 
		++cnt;
	}
	// Stop
	buzzer_blink(2);
	Serial.println('-');
}

// WINDOWS DEBUG BELOW
#ifdef _MSC_VER 
int main()
{
	while (true) {
		loop();
	}
}
#endif // _MSC_VER 
// ONE_DISTANCE_SENSOR_USED
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
#elif TWO_DISTANCE_SENSORS_USED
#include "Settings.h"
#include "Distance.h"
#include "OutputBoolOneWire.h"

Distance_HCSR04 DistanceL(PINOUT::S1_LEFT_TRIG, PINOUT::S1_LEFT_ECHO);
Distance_HCSR04 DistanceR(PINOUT::S1_RIGHT_TRIG, PINOUT::S1_RIGHT_ECHO);



#endif
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
