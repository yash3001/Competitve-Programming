/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int nCr(int n, int r);

int dp[1001][1001];

int main(){
    cout<<"Enter n: ";
    int n; cin>>n;
    cout<<"Enter r: ";
    int r; cin>>r;
    cout<<"Value of nCr is(0 if r>n) "<<nCr(n, r)<<endl;
    return 0;
}

int nCr(int n, int r){

    for(int i=0; i<n+1; i++){
        for(int j=0; j<r+1; j++){
            if(j==0 || i==j){
                dp[i][j] = 1;
            }
            if(j==1){
                dp[i][j] = i;
            }
            if(j>i){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<r+1; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][r];
}