/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int coin_change(vector<int> value, int sum, int n);

int dp[1001][1001];

int main(){
    cout<<"Enter the number of coins: ";
    int n; cin>>n;

    vector<int> value(n);
    cout<<"Enter the value of the elements: ";
    for(int i=0; i<n; i++){
        cin>>value[i];
    }

    int sum{};
    cout<<"Enter the sum: ";
    cin>>sum;
    cout<<"The number of ways are: "<<coin_change(value, sum, n)<<endl;
    return 0;
}

int coin_change(vector<int> value, int sum, int n){
    for(int i=1; i<sum+1; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(value[i-1]<=j){
                dp[i][j] = dp[i][j-value[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}