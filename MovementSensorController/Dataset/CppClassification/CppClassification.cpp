#include <iostream>

#include "General.h"
#include "NaiveBayes.h"
#include "ReadDataset.h"


int main()
{
    NaiveBayes naiveBayes = NaiveBayes();

    container2D dataset = read_iris_dataset();
    dataset = math::vec_transpose(dataset);
    
    unsigned training_percentage = 70;
    container2D training_data, testing_data;
    split_dataset(dataset, training_percentage, training_data, testing_data);
    container1D groundTruth = math::vec_transpose(testing_data)[4];

    std::cout << "\tdataset       size is (" << dataset.size() << ", " << dataset[0].size() << ")" << std::endl;
    std::cout << "\ttraining_data size is (" << testing_data.size() << ", " << testing_data[0].size() << ")" << std::endl;
    std::cout << "\ttesting_data  size is (" << training_data.size() << ", " << training_data[0].size() << ")" << std::endl;

    // (n_features+1, n_examples) - each row is one example
    naiveBayes.fit(training_data, groundTruth);

    container1D predicitions;
    for (int i = 0; i < testing_data.size(); i++)
    {
        auto index = naiveBayes.predict(testing_data[i]);
        predicitions.push_back(index);
        std::cout << index << ' ';
    }

    //testing_data = math::vec_transpose(testing_data);  // Transpose to get groundTruth
    //std::cout << "--------print_container2D(testing_data\n";
    //print_container2D(testing_data);
    //std::cout << "--------print_container1D(testing_data[4]);\n";
    //print_container1D(testing_data[4]);
    /*testing_data = math::vec_transpose(testing_data);
    std::cout << "--------print_container2D(testing_data\n";
    print_container2D(testing_data);*/
    std::cout << "score is: " << calc_vec_match_score(testing_data[4], predicitions) << std::endl;

    std::cout << "--------print_container1D(predicitions\n";
    print_container1D(predicitions);
    
    return 0;
 }
