/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <climits>
#include <cstdint>

using namespace std;

int coin_change(vector<int> coins, int sum, int n);

int dp[1001][1001];

int main(){
    cout<<"Enter the number of coins: ";
    int n; cin>>n;

    vector<int> coins(n);
    cout<<"Enter the value of the elements: ";
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    int sum{};
    cout<<"Enter the sum: ";
    cin>>sum;
    cout<<"The minimum number of coins are: "<<coin_change(coins, sum, n)<<endl;
    return 0;
}

int coin_change(vector<int> coins, int sum, int n){
    for(int i=0; i<sum+1; i++){
        dp[0][i] = INT_MAX-1;
    }
    for(int i=1; i<n+1; i++){
        dp[i][0] = 0;
    }
    for(int i=1; i<sum+1; i++){
        if(i%coins[0]==0)
            dp[1][i] = i/coins[0];
        else{
            dp[1][i] = INT_MAX-1;
        }
    }
    for(int i=2; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coins[i-1]<=sum){
                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}