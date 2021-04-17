/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool minimum_subset_sum_difference(int *arr, int sum, int n);

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
    int ans = sum+1;
    for(int i=0; i<=sum; i++){
        if(minimum_subset_sum_difference(arr, i, n)){
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

bool minimum_subset_sum_difference(int *arr, int sum, int n){
    if(sum == 0){
        return dp[n][sum]=true;
    }
    else if(n==0){
        return dp[n][sum]=false;
    }

    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }

    if(arr[n-1]<=sum){
        return dp[n][sum]=(minimum_subset_sum_difference(arr, sum-arr[n-1], n-1) || minimum_subset_sum_difference(arr, sum, n-1));
    }
    else{
        return dp[n][sum]=(minimum_subset_sum_difference(arr, sum, n-1));
    }
}