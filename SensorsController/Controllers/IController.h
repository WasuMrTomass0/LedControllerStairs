#pragma once

#include "OutputInterface/IOutput.h"

class IController{
protected:
	IOutput* m_output;
public:
	IController(IOutput* output) : m_output(output) = default;
	virtual bool getOutput() = 0;
};
