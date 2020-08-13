#pragma once

#include "Settings.h"
#include "ISensor.h"
#include "IController.h"


class CControllerDualDistance: public IController
{
protected:

public:
	CControllerDualDistance(ISensor*, IOutput*);

	bool getOutput() final;
};

