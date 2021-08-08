/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number upto which you want the prime number: ";
    int n; cin>>n;

    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;   
    for(int i=2; i<=sqrt(n); i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    return 0;
}