#include "NaiveBayes.h"
#include "General.h"
#include <iostream>

void NaiveBayes::fit(container2D& dataset, container1D groundTruth)
{
	m_uniqueLabel = groundTruth;
	std::sort(m_uniqueLabel.begin(), m_uniqueLabel.end());
	m_uniqueLabel.erase(std::unique(m_uniqueLabel.begin(), m_uniqueLabel.end()), m_uniqueLabel.end());
	
	for (auto item = m_uniqueLabel.begin(); item != m_uniqueLabel.end(); ++item)
	{
		// (n_features+1, n_examples) - each row is one example
		m_summary.push_back(calc_class_summary(dataset, *item));
	}
}

size_t NaiveBayes::predict(const container1D& test_data)
{
	// (n_features+1, n_examples) - each row is one example
	container1D vec;
	for (size_t index = 0; index < m_uniqueLabel.size(); ++index)
	{
		vec.push_back(calc_prob_by_summary(test_data, m_summary[index]));
	}
	auto result = std::max_element(vec.begin(), vec.end());
	size_t maxElementIndex = std::distance(vec.begin(), result);
	return maxElementIndex;
}
