#include<iostream>
#include<vector>
#include<mutex>
#include<chrono>
#include "mergeSort.hpp"
#include "parallelMergeSort.hpp"
#include "threadedMergeSort.hpp"
using namespace std;

int main(int argc , char * argv[]){
    const int SIZE = 100000000;
    vector<int> nums(SIZE);
    vector<int> nums1(SIZE);
    vector<int> nums2(SIZE);
    for(int i = 0 ; i < SIZE ;i++){
        nums[i] = rand() % SIZE;
        nums1[i] = nums[i];
        nums2[i] = nums[i];
    };

    MergeSort* mergesort =  new MergeSort(&nums);
    auto start = chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeSortDuration = end - start;

    cout << "MergeSort time taken:" << mergeSortDuration.count() << " seconds" << endl;

    delete mergesort;


    ParallelMergeSort* mergesort1 = new ParallelMergeSort(&nums1);
     start = chrono::high_resolution_clock::now();
    mergesort1->sort();
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> parallelMergeSortDuration = end - start;

    cout << "ParallelMergesort time taken:  " << parallelMergeSortDuration.count() << "seconds" << endl;

    delete mergesort1;


    ThreadedMergeSort* sorter = new ThreadedMergeSort(&nums2);
    start = chrono::high_resolution_clock::now();
    sorter->sort();
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> threadedMergeSort4Duration = end-start;

    cout << "4 Threaded Merge Sort time taken :" << threadedMergeSort4Duration.count() << "seconds" << endl;

    delete sorter;


    return 0;
}
