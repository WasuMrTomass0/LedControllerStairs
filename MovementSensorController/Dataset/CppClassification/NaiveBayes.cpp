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
	// std::cout << maxElementIndex << "  ->  "; print_container1D(vec);
	return maxElementIndex;
}

void NaiveBayes::print_info()
{
	std::cout << "\nNaive Bayes post fir summary:\n";
	std::cout << "\tm_summary     size is " << m_summary.size() << '\n';
	std::cout << "\tm_uniqueLabel size is " << m_summary.size() << '\n';
	std::cout << '\n';
	std::cout << "Iteration:\n";
	for (size_t i = 0; i < m_summary.size(); ++i)
	{
		std::cout << "------------------------------\n";
		std::cout << "Label " << m_uniqueLabel[i] << '\n';
		std::cout << "  class_prob " << m_summary[i].class_prob << "\n";
		std::cout << "  mean_st_dev\n";
		print_container2D(m_summary[i].mean_st_dev);
		std::cout << "\n";
	}

	/*typedef struct class_summary
	{
		container2D mean_st_dev;
		float class_prob;
	} class_summary;*/

	//std::vector<class_summary> m_summary;
	//container1D m_uniqueLabel;

}
