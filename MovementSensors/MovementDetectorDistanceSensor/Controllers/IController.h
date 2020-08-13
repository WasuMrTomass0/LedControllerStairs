#pragma once

#include "OutputInterface/IOutput.h"

class IController{
protected:
	IOutput* m_output;
	ISensor* m_sensor;
public:
	IController(ISensor* sensor, IOutput* output) : m_sensor(sensor), m_output(output) = default;
	virtual bool getOutput() = 0;
};
