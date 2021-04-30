/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int coin_change(vector<int> &coins, int sum, int n);

int dp[1001][1001];

int main(){
    memset(dp, -1, sizeof(dp));

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
    cout<<"The number of ways are: "<<coin_change(coins, sum, n)<<endl;
    return 0;
}

int coin_change(vector<int> &coins, int sum, int n){

    if(sum==0){
        return dp[n][sum]=1;
    }
    else if(n==0){
        return dp[n][sum]=0;
    }

    if(dp[n][sum] != -1){
        return dp[n][sum];
    }

    if(coins[n-1]<=sum){
        return dp[n][sum]=coin_change(coins, sum-coins[n-1], n)+coin_change(coins, sum, n-1);
    }
    else{
        return dp[n][sum]=coin_change(coins, sum, n-1);
    }
}