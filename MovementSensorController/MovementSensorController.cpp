// #define TWO_DISTANCE_SENSORS_USED
#define ONE_DISTANCE_SENSOR_USED

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
#ifdef ONE_DISTANCE_SENSOR_USED
#include "Settings.h"
#include "OutputBoolOneWire.h"
#include "Distance.h"
#include <iostream>

Distance_HCSR04 DistanceSensor(PINOUT::S2_DIS_TRIG, PINOUT::S2_DIS_ECHO);
OutputBoolOneWire Output(PINOUT::S2_DIS_OUT_PIN);

void setup() {

}

void loop() {

}


// int cnt = 0;
int main()
{
	while (true) {
		// loop();
		// cnt++;
		// if (cnt % 1000 == 0) std::cout << cnt << ".\n";
	}
}
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
