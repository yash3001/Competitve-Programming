/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int count_subset_sum(int *, int, int);

int dp[1001][1001];

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
    if(int i=count_subset_sum(arr,sum,n)){
        cout<<i<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}

int count_subset_sum(int *arr, int sum, int n){

    for(int i=0; i<n+1; i++){
        dp[0][i] = 1;
    }
    for(int i=1; i<sum+1; i++){
        dp[i][0] = 0;
    }

    for(int i=1; i<sum+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[j-1]<=i){
                dp[i][j] = dp[i-arr[j-1]][j-1] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[sum][n];
}