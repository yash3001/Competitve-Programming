/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void minimum_subset_sum_difference(int *arr, int sum, int n);

// dp[n][sum]
int dp[1001][1001];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the size of the set: ";
    int n; cin>>n;
    int sum{};
    cout<<"Enter the set: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    minimum_subset_sum_difference(arr, sum, n);
    int ans = sum+1;
    for(int i=0; i<=sum; i++){
        if(dp[n][i]){
            ans = min(ans, abs(sum - 2*i));
        }
    }
    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<sum+1; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<endl;
}

void minimum_subset_sum_difference(int *arr, int sum, int n){

    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<sum+1; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}