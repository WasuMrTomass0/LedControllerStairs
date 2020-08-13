#include "OutputOneWire.h"
#include "ISensor.h"
#include "CSensorHCSr04.h"
#include "IController.h"
#include "ControllerDualDistance.h"

#include <iostream>

//  //  // //  Current setup  //  //  // //
IController* controller = new CControllerDualDistance(
	new COutputOneWire(OUT_PIN),
	new CSensorHCSr04(LEFT_TRIG, LEFT_ECHO),
	new CSensorHCSr04(RIGHT_TRIG, RIGHT_ECHO),
	dataCapacity
);

void setup() {

}

void loop() {
	controller->mainLoop();
}

int cnt = 0;

int main()
{
	while (true) {
		loop();
		cnt++;
		if(cnt % 1000 == 0) std::cout << cnt <<".\n";
	}
}