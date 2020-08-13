#pragma once

#include "DataStorage.h"

class DSSlopeFactor : public IDataContainer<float> {
	/* Class focused on storing slope factors used to evaluate movement direction. */
protected:
	float m_meanFactor;

protected:
	void calculateMean();

public:
	DSSlopeFactor(const unsigned);

	void calculateSlope(data_t, data_t, time_type, time_type);

	float getSlopeFactor();
};