/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<int> prime_factorization(int n) {
    vector<int> result;
    for(int i=2; i*i<=n; i++){
        while(n%i == 0){
            result.push_back(i);
            n /= i;
        }
    }
    if(n > 1){
        result.push_back(n);
    }
    return result;
}

int main(){
    int n; cin>>n;
    vector<int> factors = prime_factorization(n);
    for(int i = 0; i < factors.size(); i++){
        cout<<factors[i]<<" ";
    }
    cout<<endl;
    return 0;
}