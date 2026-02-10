#include "quickSort.hpp"
#include<vector>
#include<cstdlib>

using namespace std;

QuickSort::QuickSort(vector<int>* nums){
    this->nums = nums;
};

QuickSort::~QuickSort(){};


void QuickSort::partition(int left, int right){
    if(left >= right)return ;
    
    int  pivot = (*nums)[right];
    int i = left -1;
    
    for(int j = left ; j < right ; j++){
        if((*nums)[j] <= pivot){
            i++;
            swap((*nums)[i] ,(*nums)[j]);
        };
    };
    
    swap((*nums)[i+1] , (*nums)[right]);
    int pivotIndex = i+1;
    
    partition(left, pivotIndex -1);
    partition( pivotIndex + 1 , right);
};

void QuickSort::sort(){
    if((*nums).size() == 0) {
        exit(1);
    };
    
    partition(0, (*nums).size() -1);
}