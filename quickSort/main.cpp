#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

int main(int argc , char* argv[]){
    const int SIZE = 1000000;
    vector<int> nums(SIZE);
    vector<int> nums1(SIZE);
    for(int i = 0 ; i < SIZE ;i++){
        nums[i] = rand() % SIZE;
        nums1[i] = nums[i];
    };
    
    
    
};