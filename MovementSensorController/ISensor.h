#pragma once

#include "Settings.h"

class ISensor
{
public:
	ISensor() = default;
	~ISensor() = default;

	virtual data_t getMeas_cm() = 0;
	virtual data_t getMeas_mm() = 0;
};

