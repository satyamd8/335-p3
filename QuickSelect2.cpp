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
#include <set>
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
int quickRecursive(std::vector<int>& data, int l, int r, std::set<int>& k) 
{ 
    int index = partition(data, l, r); // Partition and get the pivot index

    std::set<int> found_keys;
    for (int key : k) {
        if (key == index) {
            found_keys.insert(key);
        }
    }

    // Remove the found keys from the set
    for (int found : found_keys) {
        k.erase(found);
    }

    // Recurse on the necessary sides
    if (!k.empty()) {
        int min_key = *k.begin();
        int max_key = *k.rbegin();

        if (min_key < index) { // Recurse left
            quickRecursive(data, l, index - 1, k);
        }

        if (max_key > index) { // Recurse right
            quickRecursive(data, index + 1, r, k);
        }
    }

    // If k is more than number of  
    // elements in array 
    return INT_MAX; 
} 

void quickSelect2(const std::string & header, std::vector<int> data){
    int n = data.size();
    std::set<int> keys = {0, n / 4, n / 2, (3 * n) / 4, n - 1}; // The five keys to find

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