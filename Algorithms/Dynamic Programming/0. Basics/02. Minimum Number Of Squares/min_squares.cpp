/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int min_squares(int n){
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
        for(int j=1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    return dp[n];
}

int main(){
    // cout<<"Enter N: ";
    int n; cin>>n;
    cout<<min_squares(n);
    return 0;
}