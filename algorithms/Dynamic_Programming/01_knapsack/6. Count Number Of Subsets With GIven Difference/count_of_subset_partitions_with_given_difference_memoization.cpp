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
    if(sum==0){
        return dp[n][sum]=1;
    }
    else if(n==0){
        return dp[n][sum]=0;
    }

    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }

    if(arr[n-1]<=sum){
        return dp[n][sum]=(count_subset_partition_difference(arr, sum-arr[n-1], n-1) + count_subset_partition_difference(arr, sum, n-1));
    }
    else{
        return dp[n][sum]=(count_subset_partition_difference(arr, sum, n-1));
    }
}