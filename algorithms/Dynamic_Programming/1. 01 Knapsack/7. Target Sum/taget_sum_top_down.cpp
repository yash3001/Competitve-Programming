/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int count_subset_partition_difference(int *, int, int);

//int dp[n][sum]
int dp[1001][1001];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the size of the set: ";
    int n; cin>>n;
    cout<<"Enter the set: ";
    int arr[n];
    int sum{};
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<"Enter the difference between the two subset partitions: ";
    int diff; cin>>diff;
    if(int i=count_subset_partition_difference(arr,(sum+diff)/2,n)){
        cout<<i<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}

int count_subset_partition_difference(int *arr, int sum, int n){

    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<sum+1; i++){
        dp[0][i] = 0;
    }
    // n - i
    // sum - y
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] + dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}