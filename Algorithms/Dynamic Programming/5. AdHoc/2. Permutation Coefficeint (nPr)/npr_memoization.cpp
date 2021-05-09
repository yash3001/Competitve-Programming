/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int nPr(int n, int r);

int dp[1001][1001];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter n: ";
    int n; cin>>n;
    cout<<"Enter r: ";
    int r; cin>>r;
    cout<<"Value of nPr is(0 if r>n) "<<nPr(n, r)<<endl;
    return 0;
}

int nPr(int n, int r){
    if(r==0){
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
    return dp[n][r]= r*nPr(n-1, r-1) + nPr(n-1, r);
}