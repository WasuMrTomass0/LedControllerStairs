#pragma once

#include "IOutput.h"

class IController{
protected:
	IOutput* m_output;
public:
	IController(IOutput* output) : m_output(output) {}
	void outputState(bool state) { m_output->outputState(state); }
	virtual void mainLoop() = 0;
};
