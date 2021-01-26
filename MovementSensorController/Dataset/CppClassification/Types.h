#pragma once

typedef std::vector<std::vector<float>> container2D;
typedef std::vector<float> container1D;

typedef struct class_summary
{
	container2D Mean_Stdev;
	float class_prob;
} class_summary;
