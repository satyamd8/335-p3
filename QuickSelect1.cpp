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

/*
    Quick Select Implementation used from geeksforgeeks.org
*/

// Standard partition process of QuickSort(). 
// It considers the last element as pivot 
//  and moves all smaller element to left of 
//  it and greater elements to right 
int partition(std::vector<int>& data, int l, int r) 
{ 
    int x = data[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (data[j] <= x) { 
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
int quickSelect(std::vector<int>& data, int l, int r, int k) 
{ 
    // If k is smaller than number of  
    // elements in array 
    if (k > 0 && k <= r - l + 1) { 

        // Partition the array around last  
        // element and get position of pivot  
        // element in sorted array 
        int index = partition(data, l, r); 

        // If position is same as k 
        if (index - l == k - 1) 
            return data[index]; 

        // If position is more, recur  
        // for left subarray 
        if (index - l > k - 1)  
            return quickSelect(data, l, index - 1, k); 

        // Else recur for right subarray 
        return quickSelect(data, index + 1, r,  
                            k - index + l - 1); 
    } 

    // If k is more than number of  
    // elements in array 
    return INT_MAX; 
} 

/*
void insertionSort(std::vector<int>& data, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= left && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}
*/

void quickSelect1(const std::string & header, std::vector<int> data){
    int p25 = data.size()/4;
    int p50 = data.size()/2;
    int p75 = (data.size() * 3) / 4;

    if (data.size() <= 20){
        insertionSort(data, 0, data.size() - 1);
    }
    else{
        quickSelect(data, 0, data.size() - 1, p50);         //median
        quickSelect(data, 0, p50 - 1, p25);                 //25
        quickSelect(data, p50 + 1, data.size() - 1, p75);   //75 SCUFFED
    }

    //how to find other stuff???
    int min = data[0];
    //*std::min_element(data.begin(), data.begin() + p25);
    int p25a = data[data.size()/4];
    int p50a = data[data.size()/2];
    int p75a = data[(data.size() * 3) / 4]; //SCUFFED
    int max = data[data.size()];
    //*std::max_element(data.begin() + p75, data.end());

    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25a << std::endl;
    std::cout << "P50: " << p50a << std::endl;
    std::cout << "P75: " << p75a << std::endl;
    std::cout << "Max: " << max << std::endl;
}

/* Copyright 2024, Satyam Dhar */