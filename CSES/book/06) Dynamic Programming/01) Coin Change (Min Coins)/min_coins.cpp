/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int minSum(int sum, vector<int> coins, int n){
    int dp[sum+1];
    dp[0] = 0;
    for(int i=1; i<=sum; i++){
        dp[i] = INT_MAX-1;
        for(const auto &c: coins){
            if(i-c >= 0){
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }
    return dp[sum];
}

int main(){
    // cout<<"Enter the number of coins: ";
    int n; cin>>n;
    // cout<<"Enter the coins: ";
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    // cout<<"Enter the target sum: ";
    int sum; cin>>sum;
    // cout<<"The minimum number of coins required to reach the target sum are: ";
    cout<<minSum(sum, coins, n);
    return 0;
}