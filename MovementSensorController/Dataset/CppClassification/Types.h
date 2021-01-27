#pragma once

#include <vector>

typedef std::vector<std::vector<float>> container2D;
typedef std::vector<float> container1D;

typedef struct class_summary
{
    container2D mean_st_dev;
    float class_prob;
} class_summary;

namespace iris {
    constexpr float setosa = 1.0f;
    constexpr float versicolor = 1.0f;
    constexpr float virginica = 1.0f;
    constexpr float unknown = 1.0f;
}
