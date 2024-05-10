#include "InsertionSort.hpp"
#include <iostream>
#include <algorithm>
#include <vector>


/*
    sets index/position variables and key variables
    checks which elements are greater than the key, continuously placing them forward
        stops when j is less than the key
*/
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