/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> arr, int n){
    int dp[n];
    int ans = 1;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
        }
    }

    return ans;
}

int main(){
    // cout<<"Enter the size of the array: ";
    int n; cin>>n;
    // cout<<"Enter the array: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<lis(arr, n);
    return 0;
}