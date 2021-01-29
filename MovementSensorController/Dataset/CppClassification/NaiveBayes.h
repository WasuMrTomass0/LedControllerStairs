#pragma once

#include <vector>
#include "Types.h"
#include "General.h"  // print_dontainer2d

class NaiveBayes
{
protected:
    std::vector<class_summary> m_summary;
    container1D m_uniqueLabel;

public:
    void fit(container2D& dataset, container1D groundTruth);
    size_t predict(const container1D& test_data);
    void print_info();
};

