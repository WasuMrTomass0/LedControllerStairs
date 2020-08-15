#pragma once

#include "IInput.h"
#include "Settings.h"

class CInputOneWire: public IInput
{
protected:
	const unsigned m_pin;
public:
	CInputOneWire(unsigned pin) : m_pin(pin) {}
	~CInputOneWire() = default;
	bool getInput() { digitalRead(m_pin); }
};
