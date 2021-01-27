#include "ReadDataset.h"

#include <sstream>      // std::istringstream
#include <algorithm>    // std::replace
#include <fstream>      // std::ifstream
#include <string>
#include <iostream>

container2D read_iris_dataset()
{
    std::ifstream my_file("iris.data");
    std::string line;
    container2D iris_dataset;

    container1D temp_sepal_len;
    container1D temp_sepal_wid;
    container1D temp_petal_len;
    container1D temp_petal_wid;
    container1D temp_iris_class;

    float sepal_len_f, sepal_wid_f, petal_len_f, petal_wid_f, iris_class_f;
    
    std::string temp_str;
    size_t count = 0;

    if (!my_file.is_open())
    {
        std::cout << "Unable to open file\n";
        return iris_dataset;
    }

    std::cout << "File opened successfully\n";
    while (std::getline(my_file, line)) {
        std::replace(line.begin(), line.end(), '-', '_');
        std::replace(line.begin(), line.end(), ',', ' ');

        // std::cout << line << '\n';
        std::istringstream iss(line);
        ++count;
        iss >> sepal_len_f >> sepal_wid_f >> petal_len_f >> petal_wid_f >> temp_str;
        temp_sepal_len.push_back(sepal_len_f);
        temp_sepal_wid.push_back(sepal_wid_f);
        temp_petal_len.push_back(petal_len_f);
        temp_petal_wid.push_back(petal_wid_f);

        if (temp_str.compare("Iris_setosa") == 0)
        {
            iris_class_f = iris::setosa;
        }
        else if (temp_str.compare("Iris_versicolor") == 0)
        {
            iris_class_f = iris::versicolor;
        }
        else if (temp_str.compare("Iris_virginica") == 0)
        {
            iris_class_f = iris::virginica;
        }
        else
        {
            iris_class_f = iris::unknown;
        }

        temp_iris_class.push_back(iris_class_f);
    }

    iris_dataset.push_back(temp_sepal_len);
    iris_dataset.push_back(temp_sepal_wid);
    iris_dataset.push_back(temp_petal_len);
    iris_dataset.push_back(temp_petal_wid);
    iris_dataset.push_back(temp_iris_class);

    return iris_dataset;
}
