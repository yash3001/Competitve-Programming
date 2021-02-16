// Algorithm to find prime numbers upto any number

#include<bits/stdc++.h>

using namespace std;

int main(){
    long long num; cin>>num;
    vector<bool> primes(num+1, 1);
    primes.shrink_to_fit();
    for(int i=2; i<=sqrt(num); i++){
        if(primes.at(i)){
            for(int j=i*i; j<=num; j=j+i){
                primes.at(j) = 0;
            }
        }
    }
    for(int i=2; i<=num; i++){
        if(primes.at(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}