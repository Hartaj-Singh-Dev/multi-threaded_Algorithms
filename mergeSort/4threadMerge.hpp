#pragma once // this can be only included once
#include <vector>
#include<thread>

using namespace std;

class threadedMergeSort{
    private:
    vector<int>* nums;
    void recursiveSort(int left , int right , int depth);

    public:
        threadedMergeSort(vector<int>* nums);
        ~threadedMergeSort();
        void sort();
}
