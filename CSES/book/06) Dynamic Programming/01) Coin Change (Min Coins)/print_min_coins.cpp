/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void minSum(int sum, vector<int> coins, int n){
    int dp[sum+1];
    vector<int> ans(sum+1);
    dp[0] = 0;
    for(int i=1; i<=sum; i++){
        dp[i] = INT_MAX;
        for(const auto &c: coins){
            if(i-c >= 0){
                if(dp[i] > dp[i-c]+1){
                    dp[i] = dp[i-c]+1;
                    ans[i] = c;
                }
            }
        }
    }

    while(sum > 0){
        cout<<ans[sum]<<" ";
        sum -= ans[sum];
    }
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
    minSum(sum, coins, n);
    return 0;
}