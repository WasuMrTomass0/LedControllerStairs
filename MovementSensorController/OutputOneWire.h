#pragma once

#include "IOutput.h"
#include "Settings.h"



class COutputOneWire : public IOutput {
protected:
	const unsigned m_wirePin;
	bool m_state;
public:
	COutputOneWire(const unsigned wirePin) : m_wirePin(wirePin), m_state(false) {}
	void outputState(bool state) final { m_state = state; digitalWrite(m_wirePin, m_state); }
	//void pushOutput() final { digitalWrite(m_wirePin, m_state); }
};