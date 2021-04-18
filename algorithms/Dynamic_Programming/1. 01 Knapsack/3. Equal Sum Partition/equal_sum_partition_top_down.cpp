/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int dp[1'001][1'001];

bool equal_sum_partition(int *arr, int sum, int n){
    for(int i=0; i<n+1; i++){
        dp[0][i] = 1;
    }
    for(int i=1; i<sum+1; i++){
        dp[i][0] = 0;
    }

    for(int i=1; i<sum+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[j-1]<=i){
                dp[i][j] = (dp[i-arr[j-1]][j-1] || dp[i][j-1]);
            }
            else{
                dp[i][j] = (dp[i][j-1]);
            }
        }
    }

    return dp[sum][n];
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