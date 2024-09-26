#include "ReadDataset.h"

#include <sstream>      // std::istringstream
#include <algorithm>    // std::replace
#include <fstream>      // std::ifstream
#include <string>
#include <iostream>


namespace read_dataset 
{
    container2D iris()
    {
        constexpr float iris_setosa = 0.0f;
        constexpr float iris_versicolor = 1.0f;
        constexpr float iris_virginica = 2.0f;
        constexpr float iris_unknown = 100.0f;

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
            if (temp_str.compare("Iris_setosa") == 0)
            {
                iris_class_f = iris_setosa;
            }
            else if (temp_str.compare("Iris_versicolor") == 0)
            {
                iris_class_f = iris_versicolor;
            }
            else if (temp_str.compare("Iris_virginica") == 0)
            {
                iris_class_f = iris_virginica;
            }
            else
            {
                iris_class_f = iris_unknown;
                std::cout << "Unknown class: '" << temp_str << "'. Skipping.\n";
                continue;
            }
            temp_sepal_len.push_back(sepal_len_f);
            temp_sepal_wid.push_back(sepal_wid_f);
            temp_petal_len.push_back(petal_len_f);
            temp_petal_wid.push_back(petal_wid_f);
            temp_iris_class.push_back(iris_class_f);
        }

        iris_dataset.push_back(temp_sepal_len);
        iris_dataset.push_back(temp_sepal_wid);
        iris_dataset.push_back(temp_petal_len);
        iris_dataset.push_back(temp_petal_wid);
        iris_dataset.push_back(temp_iris_class);

        return iris_dataset;
    }

    container2D distance_simple()
    {
        std::ifstream my_file("../PyCharm/TEST_CONV_10_DIFF_ALL.csv");
        if (!my_file) std::cerr << "Could not open the file!" << std::endl;

        std::string line;
        container2D dataset;

        container1D temp_n[10];
        container1D temp_class;

        float n_f[10];
        float class_f, cnt;
        std::string temp_str;
        size_t count = 0;

        if (!my_file.is_open())
        {
            std::cout << "Unable to open file\n";
            exit;
            return dataset;
        }

        std::cout << "File opened successfully\n";
        while (std::getline(my_file, line)) {
            if (line[0] == '\'') continue;
            // std::replace(line.begin(), line.end(), '-', '_');
            std::replace(line.begin(), line.end(), ',', ' ');

            // std::cout << line << '\n';

            std::istringstream iss(line);
            ++count;
            iss >> cnt >> n_f[0] >> n_f[1] >> n_f[2] >> n_f[3] >> n_f[4] >> n_f[5] >> n_f[6] >> n_f[7] >> n_f[8] >> n_f[9] >> class_f;
            if (class_f >= config::no_of_classes || class_f < 0)
            {
                std::cout << "Unknown class: '" << class_f << "'. Skipping.\n";
                continue;
            }
            for (size_t i = 0; i < config::features_quantity; ++i)
            {
                temp_n[i].push_back(n_f[i]);
            }
            temp_class.push_back(class_f);

        }

        for (size_t i = 0; i < config::features_quantity; ++i)
        {
            dataset.push_back(temp_n[i]);
        }
        dataset.push_back(temp_class);
        return dataset;
    }

    container2D balance()
    {
        std::ifstream my_file("balance-scale.data");
        std::string line;
        container2D dataset;
        container1D temp[5];
        float variables[5];
        char class_char;
        size_t count = 0;

        if (!my_file.is_open())
        {
            std::cout << "Unable to open file\n";
            return dataset;
        }

        std::cout << "File opened successfully\n";
        while (std::getline(my_file, line)) {
            std::replace(line.begin(), line.end(), '-', '_');
            std::replace(line.begin(), line.end(), ',', ' ');

            std::istringstream iss(line);
            iss >> class_char >> variables[0] >> variables[1] >> variables[2] >> variables[3];
            switch (class_char)
            {
            case 'L': {variables[4] = 0; break; }
            case 'B': {variables[4] = 1; break; }
            case 'R': {variables[4] = 2; break; }
            default:  {std::cout << "Unknown class: '" << class_char << "'. Skipping.\n"; continue;}
            }
            for (size_t i = 0; i < config::example_len; ++i)
            {
                temp[i].push_back(variables[i]);
            }
        }
               
        for (size_t i = 0; i < config::example_len; ++i)
        {
            dataset.push_back(temp[i]);
        }
        return dataset;
    }

    container2D default_ds()
    {
#ifdef DS_IRIS
        return iris();
#elif defined  DS_BALANCE
        return balance();
#elif defined DS_DISTANCE_SIMPLE
        return distance_simple();
#endif  
    }
}  // namespace 'read_dataset'
