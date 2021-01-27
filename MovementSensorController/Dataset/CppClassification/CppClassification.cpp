#include <iostream>

#include "General.h"
#include "NaiveBayes.h"
#include "ReadDataset.h"

#include <ctime>


int main()
{
    NaiveBayes naiveBayes = NaiveBayes();

    container2D dataset = read_iris_dataset();
    dataset = math::vec_transpose(dataset);
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(dataset.begin(), dataset.end());

    unsigned training_percentage = 70;
    container2D training_data, testing_data;
    split_dataset(dataset, training_percentage, training_data, testing_data);

    std::cout << "\tdataset       size is (" << dataset.size() << ", " << dataset[0].size() << ")" << std::endl;
    std::cout << "\ttraining_data size is (" << testing_data.size() << ", " << testing_data[0].size() << ")" << std::endl;
    std::cout << "\ttesting_data  size is (" << training_data.size() << ", " << training_data[0].size() << ")" << std::endl;

 }
