#pragma once

#include "Settings.h"
#include "ISensor.h"
#include "IController.h"


class CControllerDualDistance: public IController
{
protected:
	ISensor* m_sensorL;
	ISensor* m_sensorR;
public:
	CControllerDualDistance(IOutput*);

	bool getOutput() final;
};

