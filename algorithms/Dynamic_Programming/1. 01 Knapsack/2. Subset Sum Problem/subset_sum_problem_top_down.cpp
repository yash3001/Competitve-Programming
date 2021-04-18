/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool subset_sum_problem(int *, int, int);

// max n - 10000 sum - 10000
int dp[10001][10001];

int main(){
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
    for(int i=1; i<sum+1; i++){
        dp[sum][0] = false;
    }
    for(int j=0; j<n+1; j++){
        dp[0][j] = true;
    }
    for(int i=1; i<sum+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[j-1]<=i){
                dp[i][j]=(dp[i-arr[j-1]][j-1] || dp[i][j-1]);
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    return dp[sum][n];
}