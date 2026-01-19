#include "threadedMergeSort.hpp"
#include <cstdlib>
#include <thread>

using namespace std;

ThreadedMergeSort::ThreadedMergeSort(vector<int>* nums):nums(nums){ };

ThreadedMergeSort::~ThreadedMergeSort(){};

void ThreadedMergeSort::recursiveSort(int left , int right , int depth){
    const int THRESHOLD = 5000;
    const int MAX_DEPTH = 2;
        
    if(right - left < THRESHOLD){
        sort(nums->begin() + left , nums->begin() + right + 1);
        return ;
    };
    
    if(left >= right) return;
    
    int mid = left + (right - left)/2;
    
    if(depth < MAX_DEPTH){
        thread t1([this , left , mid , depth]{
            this->recursiveSort(left , mid , depth+1);
        });
        thread t2([this , mid , right , depth]{
          this->recursiveSort(mid+1,  right,  depth +1);  
        });
        t1.join();
        t2.join();
    }else{
        recursiveSort(left, mid, depth + 1);
        recursiveSort(mid+1, right, depth +1 );
    };
    
    
    vector<int> res;
    res.reserve(right - left +1);
    int i = left , j = mid+ 1;
    
    while (i <= mid && j <= right) {
           if ((*nums)[i] <= (*nums)[j])
               result.push_back((*nums)[i++]);
           else
               result.push_back((*nums)[j++]);
       };
    while (i <= mid) result.push_back((*nums)[i++]);
        while (j <= right) result.push_back((*nums)[j++]);
    
        for (int k = 0; k < result.size(); k++) {
            (*nums)[left + k] = result[k];
        } ;
        
        
};

void ThreadedMergeSort::sort(){
    if((*nums).size() == 0){
        exit(1);
    }
    
    thread mainThread([this] {
        this->recursiveSort(0 , (*nums).size() - 1 , 0);
    });
    
    mainThread.join();
}
