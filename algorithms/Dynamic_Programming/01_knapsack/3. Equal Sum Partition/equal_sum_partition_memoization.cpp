/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int dp[1'001][1'001];

bool equal_sum_partition(int *arr, int sum, int n){
    if(sum == 0){
        return dp[sum][n] = 1;
    }
    else if(n==0){
        return dp[sum][n] = 0;
    }

    if(dp[sum][n] != -1){
        return dp[sum][n];
    }

    if(arr[n-1]<=sum){
        return dp[sum][n] = (equal_sum_partition(arr, sum-arr[n-1], n-1) || equal_sum_partition(arr, sum, n-1));
    }
    else{
        return dp[sum][n] = (equal_sum_partition(arr, sum, n-1));
    }
}

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
    if(!(sum&1) && equal_sum_partition(arr,sum/2,n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}