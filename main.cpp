/*
Name: Satyam Dhar
Class: CSCI 335 Professor Tojeira
Title: main.cpp
Description: Converts input files to a vector, to then be passed on to the sorting functions of each class.
Date: 5/3/2024
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"
using namespace std;

/*
    takes in input file using ifstream
    prints first line of input file
    then uses istringstream to process each value of the second line
        each value is pushed back to an int vector

*/
int main(){
    string input = "test_input.txt";
    ifstream fin(input);

    vector <int> data;

    string header;
    getline(fin, header);
    /*
    if (getline(fin, header)){
        cout << header << endl;
    }
    */

    string nums;
    if (getline(fin, nums)){
        istringstream number(nums);
        int value;
        
        while (number >> value){
            data.push_back(value);
        }
    }
    fin.close();

    //method calls
    stdSort(header, data);
    quickSelect1(header, data);
    //quickSelect2(header, data);
    //countingSort(header, data);

    //call methods here
    //cout << "done" << endl;
}