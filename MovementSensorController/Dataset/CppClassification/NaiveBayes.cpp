#include "NaiveBayes.h"
#include "General.h"
//#include <algorithm>

void NaiveBayes::fit(container2D dataset)
{
}

size_t NaiveBayes::predict(const container1D& test_data)
{
	container1D vec;
	for (auto row = m_uniqueLabel.begin(); row != m_uniqueLabel.end(); ++row)
	{
		vec.push_back(calc_prob_by_summary(test_data, m_summary[*row]));
	}

	auto result = std::max_element(vec.begin(), vec.end());
	size_t maxElementIndex = std::distance(vec.begin(), result);
	return maxElementIndex;
}
