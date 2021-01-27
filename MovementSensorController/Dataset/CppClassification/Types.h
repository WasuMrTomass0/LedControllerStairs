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
    constexpr float versicolor = 2.0f;
    constexpr float virginica = 3.0f;
    constexpr float unknown = 0.0f;
}

namespace config{
    // Iris: sepal_len, sepal_wid, petal_len, petal_wid, iris_class
    constexpr int features_quantity = 4;
    constexpr int example_len = features_quantity + 1;
}
