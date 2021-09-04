/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n, int *dp){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fibonacci(n-1, dp)+fibonacci(n-2, dp);
}

int main(){
    // cout<<"Enter the n for nth fibonacci number: ";
    int n; cin>>n;
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    dp[2] = 1;
    cout<<fibonacci(n, dp);
    return 0;
}