#pragma once

#include <vector>
#include "Types.h"

class NaiveBayes
{
protected:
    std::vector<class_summary> m_summary;
    container1D m_uniqueLabel;

public:
    void fit(container2D& dataset, container1D groundTruth);
    size_t predict(const container1D& test_data);
};

