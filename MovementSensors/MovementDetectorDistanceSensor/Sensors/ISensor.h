#pragma once

#include "Settings.h"

class ISensor
{
public:
	ISensor() = default;
	~ISensor() = default;

	virtual data_t getMeausrement() = 0;
};

