/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: StdSort.hpp
Description: Prototype functions for std::sort method of sorting
Date: 5/3/2024
*/

#include "StdSort.hpp"
#include <iostream>
#include <algorithm>
#include <vector>


/*
    uses std::sort from c++ library to sort the data vector from least to greatest
    then assigns the different integer values with int division
    prints header and all values
*/
void stdSort(const std::string & header, std::vector<int> data){
    std::sort(data.begin(), data.end());

    for (int i = 0; i < data.size(); i++){
        std::cout << data[i] << " ";
    }

    int min = data[0];
    int p25 = data[data.size()/4];
    int p50 = data[data.size()/2];
    int p75 = data[(data.size() * 3) / 4];
    int max = data[data.size() - 1];

    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << p50 << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
}

/* Copyright 2024, Satyam Dhar */