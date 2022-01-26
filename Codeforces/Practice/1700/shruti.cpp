/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void solve(vector<bool> &primes){
    int a, b; cin>>a>>b;
    unordered_map<int, int> ma, mb;
    int t = a;
    vector<int> x, y;
    for(int i=2; i<=sqrt(a); i++){
        if(primes[i]){
            if(t&i == 0){
                x.push_back(i);
            }
            while(t%i == 0){
                ma[i]++;
                t /= i;
            }
        }
    }
    if(primes[a]){
        ma[a]++;
        x.push_back(a);
    }
    t = b;
    for(int i=2; i<=sqrt(b); i++){
        if(primes[i]){
            if(t&i == 0){
                y.push_back(i);
            }
            while(t%i == 0){
                mb[i]++;
                t /= i;
            }
        }
    }
    if(primes[b]){
        ma[b]++;
        x.push_back(b);
    }
    cout<<"x"<<endl;
    for(const auto &c: x){
        cout<<c<<" ";
    }
    cout<<endl;
    cout<<"y"<<endl;
    for(const auto &c: y){
        cout<<c<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    int num = 1000;
    vector<bool> primes(num+1, 1);
    for(int i=2; i<=sqrt(num); i++){
        if(primes.at(i)){
            for(int j=i*i; j<=num; j=j+i){
                primes.at(j) = 0;
            }
        }
    }
    primes[0] = 0;
    primes[1] = 1;
    while(t--){
        solve(primes);
    }
    return 0;
}