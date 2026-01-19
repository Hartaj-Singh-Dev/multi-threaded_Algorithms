#ifndef THREADEDMERGESORT_H
#define THREADEDMERGESORT_H

// #pragma once // this can be only included once
#include <vector>
#include<thread>

using namespace std;

class ThreadedMergeSort{
    private:
    vector<int>* nums;

    public:
        ThreadedMergeSort(vector<int>* nums);
        ~ThreadedMergeSort();
        void sort();
        void recursiveSort(int left , int right , int depth);

};

#endif




