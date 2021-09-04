/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n){
    int dp[n+1];
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    // cout<<"Enter the n for nth fibonacci number: ";
    int n; cin>>n;
    cout<<fibonacci(n);
    return 0;
}