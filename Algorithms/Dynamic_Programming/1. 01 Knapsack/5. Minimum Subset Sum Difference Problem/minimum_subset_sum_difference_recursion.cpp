/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool minimum_subset_sum_difference(int *arr, int sum, int n);

int main(){
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
    for(int i=0; i<=sum/2; i++){
        if(minimum_subset_sum_difference(arr, i, n)){
            ans = min(ans, abs(sum - 2*i));
        }
    }
    cout<<ans<<endl;
}

bool minimum_subset_sum_difference(int *arr, int sum, int n){
    if(sum == 0){
        return true;
    }
    else if(n==0){
        return false;
    }
    if(arr[n-1]<=sum){
        return(minimum_subset_sum_difference(arr, sum-arr[n-1], n-1) || minimum_subset_sum_difference(arr, sum, n-1));
    }
    else{
        return(minimum_subset_sum_difference(arr, sum, n-1));
    }
}