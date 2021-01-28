#include "General.h"

namespace math {
    double calc_prob(double value, double mean, double st_dev)
    {
        static const double inv_sqrt_2pi = 0.3989422804014327;
        double a = (value - mean) / st_dev;
        return inv_sqrt_2pi / st_dev * std::exp(-0.5f * a * a);
    }

    container2D vec_transpose(container2D& vec)
    {
        if (vec.size() <= 0) return vec;
        container2D out_vec(vec[0].size(), container1D(vec.size()));
        for (size_t a = 0; a < vec.size(); ++a)
        {
            for (size_t b = 0; b < vec[a].size(); ++b)
            {
                out_vec[b][a] = vec[a][b];
            }
        }
        return out_vec;
    }
}  // 'math' namespace

// Dataset needs to be size (n_features+1, n_examples)
container2D split_by_class(container2D& dataset, float data_class)
{
    container2D out_vec;
    for (const auto example : dataset)
    {
        if (*(example.end() - 1) == data_class)
        {
            out_vec.push_back(example);
        }
    }
    return out_vec;  // returned as (n_features+1, n_examples) - each row is one example
}

class_summary calc_class_summary(container2D& dataset, float class_label)
{
    // (n_features+1, n_examples) - each row is one example
    auto class_data = split_by_class(dataset, class_label);
    // // (n_examples, n_features+1) - each row is a set of all features + last row groundTruth
    class_data = math::vec_transpose(class_data); 
    
    class_summary summary;
    container1D temp;
    for (auto row = class_data.begin(); row != class_data.end() - 1; ++row)
    {
        temp.clear();
        temp.push_back(math::calc_mean(*row));
        temp.push_back(math::calc_variancy(*row));
        summary.mean_st_dev.push_back(temp);
    }
    summary.class_prob = static_cast<float>(class_data[0].size()) / dataset.size();
    return summary;
}

float calc_prob_by_summary(const container1D& test_data, const class_summary& summary)
{
    // (n_features+1, n_examples) - each row is one example
    size_t index = 0;
    double prob = 1.0f;
    for (auto row = summary.mean_st_dev.begin(); row != summary.mean_st_dev.end() - 1; ++row)
    {   
        prob *= math::calc_prob(test_data[index], (*row)[0], (*row)[1]);
        ++index;
    }
    prob *= summary.class_prob;
    return prob;
}

float calc_vec_match_score(const container1D& labels, const container1D& predictions)
{
    float result = 0.0f;
    size_t index = 0;
    std::for_each(labels.begin(), labels.end(), 
        [&](float label)
        {
            result += label == predictions[index];
            ++index;
        });
    return static_cast<float>(100.0 * result / labels.size());
}

void split_dataset(container2D& dataset, const unsigned training_percentage,
    container2D& training_ds, container2D& test_ds)
{
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(dataset.begin(), dataset.end());
    const unsigned threshold = dataset.size() * training_percentage / 100;
    size_t counter = 0;
    for (auto row = dataset.begin(); row != dataset.end(); ++row)
    {
        if (counter < threshold)
        {
            training_ds.push_back(*row);
        }
        else
        {
            test_ds.push_back(*row);
        }
        ++counter;
    }
}

void print_container1D(const container1D& container)
{
    for (auto item = container.begin(); item != container.end(); ++item)
    {
        std::cout << (*item) << '\t';
    }
    std::cout << '\n';
}

void print_container2D(const container2D& container)
{
    for (auto row = container.begin(); row != container.end(); ++row)
    {
        for (auto item = (*row).begin(); item != (*row).end(); ++item)
        {
            std::cout << (*item) << '\t';
        }
        std::cout << '\n';
    }
}
