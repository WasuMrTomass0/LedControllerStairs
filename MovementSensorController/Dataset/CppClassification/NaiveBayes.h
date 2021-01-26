#pragma once

#include <vector>
#include "Types.h"

class NaiveBayes
{
protected:
	std::vector<class_summary> m_summary;
	std::vector<float> m_uniqueLabel;

public:
	void fit(container2D dataset);
	int predict(const container1D& test_data);
};

