/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int nPr(int n, int r);

int main(){
    cout<<"Enter n: ";
    int n; cin>>n;
    cout<<"Enter r: ";
    int r; cin>>r;
    cout<<"Value of nPr is(-1 if r>n) "<<nPr(n, r)<<endl;
    return 0;
}

int nPr(int n, int r){
    if(r==0){
        return 1;
    }
    if(r==1){
        return n;
    }
    if(r>n){
        return 0;
    }
    return r*nPr(n-1, r-1) + nPr(n-1, r);
}