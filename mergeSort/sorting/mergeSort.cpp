#include "mergeSort.hpp"
#include <vector>
using namespace std;
MergeSort::MergeSort(std::vector<int>* nums){
    //Constructor function code
    this->nums = nums;
};

MergeSort::~MergeSort(){} // Desctructor code empty

void MergeSort::recursiveSort(int left, int right){
    if(left >= right) return ;
    int mid = left + (right - left)/2;
    recursiveSort(left,mid);
    recursiveSort(mid+1,  right);
    vector<int> res;

    int i = left;
    int j = mid+1;

    while(i <= mid && j<=right){
        if((*nums)[i] <= (*nums)[j]){
            res.push_back((*nums)[i]);
            i++;
        }else{
            res.push_back((*nums)[i]);
            j++;
        };
    };
    
    while(i <= mid){
        res.push_back((*nums)[i]);
        i++;
    };
    while(j <= right){
        res.push_back((*nums)[i]);
        j++;
    };
    
    for(int k =0 ; k < res.size() ; k++){
        (*nums)[left + k ]= res[k];
    }
};


void MergeSort::sort(){
    if((*nums).size() == 0){
        exit(1);
    };
    recursiveSort(0,(*nums).size() -1);
}
