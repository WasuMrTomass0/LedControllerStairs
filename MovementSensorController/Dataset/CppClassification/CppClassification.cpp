#include <iostream>

#include "General.h"
#include "NaiveBayes.h"
#include "ReadDataset.h"


int main()
{
    NaiveBayes naiveBayes = NaiveBayes();

    // (n_examples, n_features+1)
    container2D dataset = read_dataset::default_ds();
    
    // (n_features+1, n_examples)
    dataset = math::vec_transpose(dataset);
    
    // print_container2D(dataset);

    unsigned training_percentage = 70;
    container2D training_data, testing_data;
    split_dataset(dataset, training_percentage, training_data, testing_data);
    container1D groundTruth = math::vec_transpose(testing_data)[config::example_len-1];

    std::cout << "\tdataset       size is (" << dataset.size()       << ", " << dataset[0].size()       << ")" << std::endl;
    std::cout << "\ttraining_data size is (" << training_data.size()  << ", " << training_data[0].size()  << ")" << std::endl;
    std::cout << "\ttesting_data  size is (" << testing_data.size() << ", " << testing_data[0].size() << ")" << std::endl;

    // (n_features+1, n_examples) - each row is one example
    naiveBayes.fit(training_data, groundTruth);

    container1D predicitions;
    for (auto example = testing_data.begin(); example != testing_data.end(); ++example)
    {
        // (n_features+1, n_examples) - each row is one example
        auto index = naiveBayes.predict(*example);
        predicitions.push_back(index);
        //std::cout << index << ", ";
    }

    std::cout << "\nscore is: " << calc_vec_match_score(groundTruth, predicitions) << "%\n\n" << std::endl;   

    print_truth_table(predicitions, groundTruth);

    naiveBayes.print_info();

    return 0;
 }
