#pragma once

#include <vector>
#include <string>

typedef std::vector<std::vector<float>> container2D;
typedef std::vector<float> container1D;

/* Select only one */
// #define DS_IRIS
#define DS_BALANCE
// #define DS_DISTANCE_SIMPLE

typedef struct class_summary
{
    container2D mean_st_dev;
    float class_prob;
} class_summary;

namespace config{
    // Iris: sepal_len, sepal_wid, petal_len, petal_wid, iris_class
#ifdef DS_IRIS 
    constexpr int features_quantity = 4;
    constexpr int example_len = features_quantity + 1;
    constexpr int no_of_classes = 3;
#elif defined  DS_BALANCE 
    constexpr int features_quantity = 4;
    constexpr int example_len = features_quantity + 1;
    constexpr int no_of_classes = 3;
#elif defined DS_DISTANCE_SIMPLE 
    constexpr int features_quantity = 10;
    constexpr int example_len = features_quantity + 1;
    constexpr int no_of_classes = 3;
#endif    
}
