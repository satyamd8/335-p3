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

struct Info{
    int value;
    int freq;
};

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
    int p25 = -1;
    int p50 = -1;
    int p75 = -1;
    int max = freqVec.back().value;

    for (const auto &item : freqVec){
        count += item.freq;
        if (p25 == -1 && count >= data.size() * 0.25) {
            p25 = item.value; // 25th percentile
        }

        if (p50 == -1 && count >= data.size() * 0.5) {
            p50 = item.value; // 50th percentile (median)
        }

        if (p75 == -1 && count >= data.size() * 0.75) {
            p75 = item.value; // 75th percentile
        }

        if (p25 != -1 && p50 != -1 && p75 != -1) {
            break; // If all percentiles are found, we can exit early
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