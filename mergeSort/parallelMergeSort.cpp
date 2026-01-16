#include "parallelMergeSort.hpp"
using namespace std;

ParallelMergeSort::ParallelMergeSort(vector<int>* nums): nums(nums){
   // : nums(nums) means member initalizer list , basically it does
   // the same as this->nums = nums;
};

ParallelMergeSort::~ParallelMergeSort(){}

void ParallelMergeSort::recursiveSort(int left, int right){
    const int THRESHOLD = 5000;
    if(right - left < THRESHOLD){
        std::sort(nums->begin() + left , nums->begin() + right + 1);
        return;
    };
    
    if(left >= right){
        return ;
    }
    int mid = left + (right - left)/2;
    thread thread_1([this , left , mid] {this->recursiveSort(left , mid);});
    thread thread_2([this , mid , right] {this->recursiveSort(mid+1,  right);});
    
    thread_1.join();
    thread_2.join();
    
    vector<int> res;
    int i = left ; 
    int j = mid+1;
    
    while (i <= mid && j <= right) {
            if ((*nums)[i] <= (*nums)[j]) {
                res.push_back((*nums)[i]);
                i++;
            } else {
                res.push_back((*nums)[j]);
                j++;
            }
        }
    
        while (i <= mid) {
            res.push_back((*nums)[i]);
            i++;
        }
    
        while (j <= right) {
            res.push_back((*nums)[j]);
            j++;
        }
    
        for (int k = 0; k < res.size(); k++) {
            (*nums)[left + k] = res[k];
        } 
};

void ParallelMergeSort::sort(){
    if((*nums).size() == 0 ){
        exit(1);
    };
    thread thread_1([this] {this->recursiveSort(0, (*nums).size() - 1 );});
    thread_1.join();
    
}


