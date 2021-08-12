/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> primes;
    cout<<"Enter the number: ";
    int n; cin>>n;
    for(int i=2; i<=sqrt(n); i++){
        while(n%i == 0){
            primes.push_back(i);
            n /= i;
        }
    }
    if(n != 1){
        primes.push_back(n);
    }
    cout<<"Prime factorization of the given number is: ";
    for(const auto &i: primes){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}