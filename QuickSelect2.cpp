/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: QuickSelect2.hpp
Description: Prototype functions for a different Quick Select method of sorting
Date: 5/3/2024
*/
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <climits>
#include <chrono>

/* 
    Quick Select implementation based off geeksforgeeks.org, modified to match instructions
*/

/*
    set last element of data as the pivot
    moves all smaller elements to the left, greater elements to the right of pivot
*/
int partition(std::vector<int>& data, int l, int r) 
{ 
    int pivot = data[r]; 
    int i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (data[j] <= pivot) { 
            std::swap(data[i], data[j]); 
            i++; 
        } 
    } 
    std::swap(data[i], data[r]); 
    return i; 
} 

/*
    checks the keys vector to proceed
    starts with initial partition
    sets new vector of found keys
    uses iterator to check through keys vector
        checks if key is = to pivot
            pushes found key to new vector
            removes key from keys vector
        if key isn't pivot, move on to next key
    determines min and max key using min/max_element from standard c++ library
    if min key is less than pivot, or max key is greater than pivot, recuirsively call quickselect
*/
int quickRecursive(std::vector<int>& data, int l, int r, std::vector<int>& keys) {
    if (keys.empty() || l >= r) {
        return INT_MAX; 
    }

    int index = partition(data, l, r); 

    std::vector<int> found_keys;
    for (auto it = keys.begin(); it != keys.end();) {
        if (*it == index) {
            found_keys.push_back(*it);
            it = keys.erase(it);
        } else {
            ++it;
        }
    }

    if (!keys.empty()) {
        int min_key = *std::min_element(keys.begin(), keys.end());
        int max_key = *std::max_element(keys.begin(), keys.end());

        if (min_key < index) { 
            quickRecursive(data, l, index - 1, keys);
        }

        if (max_key > index) { 
            quickRecursive(data, index + 1, r, keys);
        }
    } 

    return 0;
}

/*
    creates keys vector and fills it with the proper percentile values, and min/max
    calls modified quickSelect with keys vector
    sets info variables
    prints info variables
*/
void quickSelect2(const std::string & header, std::vector<int> data){
    int n = data.size();
    std::vector<int> keys; 
    keys.push_back(0);
    keys.push_back(n/4);
    keys.push_back(n/2);
    keys.push_back((3 * n) / 4);
    keys.push_back(n-1);

    quickRecursive(data, 0, n - 1, keys);

    int min = data[0]; 
    int p25 = data[n / 4];          
    int p50 = data[n / 2];          
    int p75 = data[(3 * n) / 4];    
    int max = data[n - 1]; 
    
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << p50 << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
}

/* Copyright 2024, Satyam Dhar */