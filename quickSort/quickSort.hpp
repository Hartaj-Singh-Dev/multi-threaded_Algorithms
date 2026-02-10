#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<vector>
#include<thread>
#include<cstdlib>

using namespace std;

class QuickSort{
    private: vector<int>* nums;
    public:
        QuickSort(vector<int>* nums);
        ~QuickSort();
        void sort();
        void partition(int left , int right);
        
};

#endif