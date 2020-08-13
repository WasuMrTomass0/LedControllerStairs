#include "OutputOneWire.h"
#include "ISensor.h"
#include "CSensorHCSr04.h"
#include "IController.h"
#include "ControllerDualDistance.h"


//  //  // //  Current setup  //  //  // //
IController* controller = new CControllerDualDistance(
	new COutputOneWire(OUT_PIN),
	new CSensorHCSr04(LEFT_TRIG, LEFT_ECHO),
	new CSensorHCSr04(RIGHT_TRIG, RIGHT_ECHO)
);


void setup() {

}

void loop() {
	controller->mainLoop();
}

int main()
{

}