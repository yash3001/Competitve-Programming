/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int count_subset_sum(int *, int, int);

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
    if(int i=count_subset_sum(arr,sum,n)){
        cout<<i<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}

int count_subset_sum(int *arr, int sum, int n){
    if(sum==0){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    if(arr[n-1]<=sum){
        return (count_subset_sum(arr, sum-arr[n-1], n-1) + count_subset_sum(arr, sum, n-1));
    }
    else{
        return (count_subset_sum(arr, sum, n-1));
    }
}