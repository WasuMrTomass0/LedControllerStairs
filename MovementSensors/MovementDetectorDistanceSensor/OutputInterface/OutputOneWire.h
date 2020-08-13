#pragma once

#include "IOutput.h"

void digitalWrite(unsigned, bool); // Forward declaration

class COutputOneWire : public IOutput {
protected:
	const unsigned m_wirePin;
	bool m_state;
public:
	COutputOneWire(const unsigned wirePin) : m_wirePin(wirePin), m_state(false) = default;
	void outputState(bool state) final { m_state = state; digitalWrite(m_wirePin, m_state); }
	//void pushOutput() final { digitalWrite(m_wirePin, m_state); }
};