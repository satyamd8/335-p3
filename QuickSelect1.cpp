/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: QuickSelect1.hpp
Description: Prototype functions for the Quick Select method of sorting
Date: 5/3/2024
*/
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

/*
    Quick Select Implementation derived from geeksforgeeks.org
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
    calls first partition
    depending on the position, function will either:
        recursively call itself for more partitions
        or if sorted, will return the kth smaller element in the vector
*/
int quick(std::vector<int>& data, int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) { 
        int index = partition(data, l, r); 

        if (index - l == k - 1){
            return data[index];
        }

        if (index - l > k - 1){  
            return quick(data, l, index - 1, k); 
        }

        return quick(data, index + 1, r, k - index + l - 1); 
    } 
    return INT_MAX; 
} 


/*
    First initializes the percentile variables to be used later
    Checks if data has more then 20 elements
        if yes, uses insertion sort
        if not, uses quickSelect
    min and max are calculated using min/max_element on the sorted vector (from the standard c++ library)
    prints all information
*/
void quickSelect1(const std::string & header, std::vector<int> data){
    int p25a, p50a, p75a;
    int p25 = data.size()/4;
    int p50 = data.size()/2;
    int p75 = (data.size() * 3) / 4;
    
    if (data.size() <= 20){
        insertionSort(data, 0, data.size() - 1);
    }
    else{
        p50a = quick(data, 0, data.size() - 1, p50);         //median
        p25a = quick(data, 0, p50, p25);                 //25
        p75a = quick(data, 0, data.size() - 1, p75);      //75 SCUFFED
    }

    int min = *std::min_element(data.begin(), data.begin() + p25); 
    int max = *std::max_element(data.begin() + p75, data.end());

    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25a << std::endl;
    std::cout << "P50: " << p50a << std::endl;
    std::cout << "P75: " << p75a << std::endl;
    std::cout << "Max: " << max << std::endl;
}

/* Copyright 2024, Satyam Dhar */