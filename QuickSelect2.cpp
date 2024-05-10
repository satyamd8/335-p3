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

/* 
    Quick Select implementation based off geeksforgeeks.org, modified to match instructions
*/

/*







REDO COMPLETELY
READ BB INSTRUCTIONS
USE VECTOR OR LIST INSTEAD OF SET LIEK DUBASS GPT







*/

// Standard partition process of QuickSort(). 
// It considers the last element as pivot 
//  and moves all smaller element to left of 
//  it and greater elements to right 
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

// This function returns k'th smallest  
//  element in arr[l..r] using QuickSort  
//  based method.  ASSUMPTION: ALL ELEMENTS 
//  IN ARR[] ARE DISTINCT 
int quickRecursive(std::vector<int>& data, int l, int r, std::vector<int>& keys) 
{
    if (keys.empty() || l >= r) {
        return INT_MAX; // No more keys to find or out of bounds
    }

    int index = partition(data, l, r); // Partition the data and get the pivot index

    // Remove keys that are found at the current partition index
    std::vector<int> found_keys;
    for (auto it = keys.begin(); it != keys.end();) {
        if (*it == index) {
            found_keys.push_back(*it);
            it = keys.erase(it); // Remove the found key
        } else {
            ++it; // Continue to the next key
        }
    }

    if (!keys.empty()) {
        // Determine the minimum and maximum remaining keys to guide recursion
        int min_key = *std::min_element(keys.begin(), keys.end());
        int max_key = *std::max_element(keys.begin(), keys.end());

        if (min_key < index) { // Recurse left if there are keys to the left
            quickRecursive(data, l, index - 1, keys);
        }

        if (max_key > index) { // Recurse right if there are keys to the right
            quickRecursive(data, index + 1, r, keys);
        }
    } 
}

void quickSelect2(const std::string & header, std::vector<int> data){
    int n = data.size();
    std::vector<int> keys; 
    keys.push_back(0);
    keys.push_back(n/4);
    keys.push_back(n/2);
    keys.push_back((3 * n) / 4);
    keys.push_back(n-1);

    // Use quickSelect with the set of keys to isolate desired positions
    quickRecursive(data, 0, n - 1, keys);

    int min = data[0]; 
    int p25 = data[n / 4];          // 25th 
    int p50 = data[n / 2];          // Median
    int p75 = data[(3 * n) / 4];    // 75th 
    int max = data[n - 1]; 

    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << p50 << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
}

/* Copyright 2024, Satyam Dhar */