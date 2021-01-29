#pragma once

#include <vector>
#include <string>

typedef std::vector<std::vector<float>> container2D;
typedef std::vector<float> container1D;

typedef struct class_summary
{
    container2D mean_st_dev;
    float class_prob;
} class_summary;

namespace iris {
    constexpr float setosa = 0.0f;
    constexpr float versicolor = 1.0f;
    constexpr float virginica = 2.0f;
    constexpr float unknown = 100.0f;
}

namespace config{
    // Iris: sepal_len, sepal_wid, petal_len, petal_wid, iris_class
    /*constexpr int features_quantity = 4;
    constexpr int example_len = features_quantity + 1;
    constexpr int no_of_classes = 3;*/

    // Movement simple
    constexpr int features_quantity = 10;
    constexpr int example_len = features_quantity + 1;
    constexpr int no_of_classes = 3;
}
