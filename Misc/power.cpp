#include<bits/stdc++.h>

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    for(long long i=0; i<200000000; i++){
    }
    for(long long i=0; i<200000000; i++){
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout<<duration.count()/1000.0<<std::endl;
    return 0;
}