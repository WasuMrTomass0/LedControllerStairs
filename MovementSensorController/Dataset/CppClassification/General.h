#pragma once

#include <vector>
#include <numeric>
#include <cmath>
#include "NaiveBayes.h"

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

// Normal distribution probability
double calc_prob(double value, double mean, double st_dev)
{
	static const double inv_sqrt_2pi = 0.3989422804014327;
	double a = (value - mean) / st_dev;
	return inv_sqrt_2pi / st_dev * std::exp(-0.5f * a * a);
}

//struct class_summary;  // Forward declaration
class_summary calc_class_summary()
{
	auto class_data = 
}

