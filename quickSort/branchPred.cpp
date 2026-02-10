#include<iostream>
#include<vector>
#include<random>
#include<chrono>

using namespace std;

constexpr int N = 10'000'000;
constexpr int LIMIT = 500;

int with_branch(const vector<int>& numbers , vector<int>& out){
  int j = 0 ;
  for(int i =0 ;i < numbers.size() ; i++){
      if(numbers[i] < LIMIT){
          out[j] = numbers[i];
          j++;
      };
  };
  return j;
};


int branchless(const vector<int>& numbers , vector<int>& out){
    int j = 0 ;
    for(int i =0 ; i < numbers.size() ;i++){
        int x = numbers[i];
        out[j] = x;
        j += (x < LIMIT);
    }
    return j;
}



int main(){
        vector<int> numbers(N);
        vector<int> out(N);
        
        mt19937 rng(123);
        uniform_int_distribution<int> dist(0 , 999);
        for(int i = 0 ;i < N ;i++) numbers[i] = dist(rng);
        
        with_branch(numbers,out);
        branchless(numbers,out);
        
        auto t1 = chrono::high_resolution_clock::now();
        int c1 = with_branch(numbers, out);
        auto t2 = chrono::high_resolution_clock::now();
        
        auto t3 = chrono::high_resolution_clock::now();
        int c2 = branchless(numbers , out);
        auto t4 = chrono::high_resolution_clock::now();
        
        auto d1 = chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
        auto d2 = chrono::duration_cast<chrono::milliseconds>(t4 - t3).count();

        cout<< "with Branch :  " << d1 << " ms , count = " << c1 << "\n" ;
        cout<< "Branchless : " << d2 << " ms , count = " << c2 << "\n";
        
};