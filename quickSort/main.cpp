#include<iostream>
#include<vector>
#include<chrono>
#include "quickSort.hpp"
#include<mutex>

using namespace std;

int main(int argc , char* argv[]){
    const int SIZE = 5* 1000000;
    vector<int> nums(SIZE);
    vector<int> nums1(SIZE);
    for(int i = 0 ; i < SIZE ;i++){
        nums[i] = rand() % SIZE;
        nums1[i] = nums[i];
    };
    
   QuickSort* quickSort = new QuickSort(&nums);
   auto start = chrono::high_resolution_clock::now();
   quickSort->sort();
   auto end = chrono::high_resolution_clock::now();
   
   chrono::duration<double> quickSortDuration = end - start;
   
   cout << "Single Threaded Time taken: " << quickSortDuration.count() << " seconds" << endl;
   
    
};