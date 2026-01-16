#include "parallelMergeSort.hpp"
using namespace std;

ParallelMergeSort::ParallelMergeSort(vector<int>* nums): nums(nums){
   // : nums(nums) means member initalizer list , basically it does
   // the same as this->nums = nums;
};

ParallelMergeSort::~ParallelMergeSort(){}

void ParallelMergeSort::recursiveSort(int left, int right){
    
};

void ParallelMergeSort::sort(){
    if((*nums).size() == 0 ){
        exit(1);
    };
    thread thread_1([this] {this->recursiveSort(0, (*nums).size() - 1 );});
    thread_1.join();
    
}


