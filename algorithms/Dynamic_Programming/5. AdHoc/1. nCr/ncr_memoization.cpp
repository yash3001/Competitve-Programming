/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int nCr(int n, int r);

int dp[1001][1001];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter n: ";
    int n; cin>>n;
    cout<<"Enter r: ";
    int r; cin>>r;
    cout<<"Value of nCr is(0 if r>n) "<<nCr(n, r)<<endl;
    return 0;
}

int nCr(int n, int r){
    if(r==0 || r==n){
        return dp[n][r]=1;
    }
    if(r==1){
        return dp[n][r]=n;
    }
    if(r>n){
        return dp[n][r]=0;
    }
    if(dp[n][r] != -1){
        return dp[n][r];
    }
    return dp[n][r]=nCr(n-1, r-1) + nCr(n-1, r);
}