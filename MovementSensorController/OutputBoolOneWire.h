#pragma once

#include "IOutput.h"
#include "Settings.h"

class OutputBoolOneWire : public IOutput {
protected:
	const unsigned m_wirePin;
	bool m_state;
public:
	OutputBoolOneWire(const unsigned wirePin) : m_wirePin(wirePin), m_state(CONFIG::DISABLE_STAIRS) {}
	void setOutputState(bool state) final { m_state = state; digitalWrite(m_wirePin, m_state); }
};
