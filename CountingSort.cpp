/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: StdSort.hpp
Description: Prototype functions for the Counting Sort method of sorting
Date: 5/3/2024
*/
#include "CountingSort.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>

struct Info{
    int value;
    int freq;
};

/*
    create hashmap to track values and their frequency
    fills hashmap with values and frequency coutn from input data vector

    create vector of Info objects, to store frequencies of each element
    goes through hashmap and creates Info objects to fill freqVec with

    sorts the objects in freqVec using std::sort from the standard library
        uses a lambda expression to compare the values of each object
        sorts from least to greatest

    initializes info variables
    iterates through sorted freqVec
        each percentile is checked by:
            if it has been found yet
            if the count int has exceeded the data size of that percentiles
    
    prints all info
*/
void countingSort(const std::string & header, std::vector<int> data){
    std::unordered_map<int, int> freqMap;
    for (int i = 0; i < data.size(); i++){
        freqMap[data[i]]++;
    }

    std::vector<Info> freqVec;
    for (const auto &pair : freqMap){
        freqVec.push_back({pair.first, pair.second});
    }

    std::sort(freqVec.begin(), freqVec.end(), [](const Info &a, const Info &b) {
        return a.value < b.value;
    });


    int count = 0;
    int min = freqVec.front().value;
    int p25 = 0;
    int p50 = 0;
    int p75 = 0;
    int max = freqVec.back().value;

    for (const auto &item : freqVec){
        count += item.freq;
        if (p25 == 0 && count >= data.size() * 0.25) {
            p25 = item.value; 
        }

        if (p50 == 0 && count >= data.size() * 0.5) {
            p50 = item.value; 
        }

        if (p75 == 0 && count >= data.size() * 0.75) {
            p75 = item.value; 
        }

        if (p25 != 0 && p50 != 0 && p75 != 0) {
            break; 
        }
    } 
    
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << p50 << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Unique: " << freqVec.size() << std::endl;
}

/* Copyright 2024, Satyam Dhar */