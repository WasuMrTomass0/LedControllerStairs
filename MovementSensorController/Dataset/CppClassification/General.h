#pragma once

#include <vector>
#include <numeric>		// std::inner_product, std::accumulate
#include <cmath>		// std::exp, std::sqrt
#include <algorithm>	// std::for_each, std::max_element
#include "NaiveBayes.h"

namespace math {
	template <typename T>
	T calc_mean(std::vector<T>& data)
	{
		return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
	}

	// Standard Deviation
	template <typename T>
	double calc_st_dev(std::vector<T>& data)
	{
		T mean = calc_mean<T>(data);
		double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
		double st_dev = std::sqrt(sq_sum / data.size() - (double)(mean * mean));
		return st_dev;
	}

	// Variancy
	template <typename T>
	double calc_variancy(std::vector<T>& data)
	{
		T mean = calc_mean<T>(data);
		double sum = 0.0d;
		std::for_each(data[4].begin(), data[4].end(),
			[&](float& item)
			{
				double temp = item - mean;
				sum += temp * temp;
			});
		return sum / static_cast<double>(data.size());
	}

	// Normal distribution probability
	double calc_prob(double value, double mean, double st_dev);

	// It can be a template
	container2D vec_transpose(container2D& vec);
}  // 'math' namespace


container2D split_by_class(container2D& dataset, float data_class);

class_summary calc_class_summary(container2D& dataset, float class_label);

float calc_prob_by_summary(const container1D& test_data, const class_summary& summary);

float calc_vec_match_schore(const container1D& labels, const container1D& predictions);
