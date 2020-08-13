#pragma once

#include "ISensor.h"
#include "Settings.h"

class CSensorHCSr04 : public ISensor {
protected:
	const unsigned m_trig;
	const unsigned m_echo;
	
protected:
	data_t getMeausrement();

public:
	CSensorHCSr04(const unsigned trig, const unsigned echo) : m_trig(trig), m_echo(echo) {}

	data_t getMeas_cm() final { return static_cast<double>(getMeausrement()) * 0.017; }
	data_t getMeas_mm() final { return static_cast<double>(getMeausrement()) * 0.17; }
};

