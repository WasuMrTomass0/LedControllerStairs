#pragma once

#include "DataStorage.h"

class DSSlopeFactor : public IDataContainer<float> {
	/* Class focused on storing slope factors used to evaluate movement direction. */
protected:
	float m_meanFactor;
public:
	DSSlopeFactor(const unsigned);

	float getSlopeFactor();
};