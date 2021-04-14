/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool subset_sum_problem(int *, int, int);

// max n - 10000
// max sum - 10000
int dp[10001][10001];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the size of the set: ";
    int n; cin>>n;
    cout<<"Enter the set: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the sum to be checked: ";
    int sum; cin>>sum;
    if(subset_sum_problem(arr,sum,n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}

bool subset_sum_problem(int *arr, int sum, int n){
    if(sum==0){
        return true;
    }
    else if(n==0){
        return false;
    }
    if(dp[sum][n] != -1){
        return dp[sum][n];
    }
    if(arr[n-1]<=sum){
        return dp[sum][n]=(subset_sum_problem(arr, sum-arr[n-1], n-1) || subset_sum_problem(arr, sum, n-1));
    }
    else{
        return dp[sum][n]=(subset_sum_problem(arr, sum, n-1));
    }
}