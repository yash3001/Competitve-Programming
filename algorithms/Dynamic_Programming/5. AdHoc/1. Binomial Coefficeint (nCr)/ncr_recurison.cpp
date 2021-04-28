/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int nCr(int n, int r);

int main(){
    cout<<"Enter n: ";
    int n; cin>>n;
    cout<<"Enter r: ";
    int r; cin>>r;
    cout<<"Value of nCr is(-1 if r>n) "<<nCr(n, r)<<endl;
    return 0;
}

int nCr(int n, int r){
    if(r==0 || r==n){
        return 1;
    }
    if(r==1){
        return n;
    }
    if(r>n){
        return 0;
    }
    return nCr(n-1, r-1) + nCr(n-1, r);
}