#include<bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the size of the array: ";
    int n; cin>>n;
    cout<<"Enter the array in sorted order:"<<endl;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched for: ";
    int num; cin>>num;
    int start=0, mid=n/2, end=n-1;
    while(start<=end){
        if(arr[mid]>num)
            end=mid-1;
        else if(arr[mid]<num)
            start=mid+1;
        else
            break;
        mid=(start+end)/2;
    }
    if(arr[mid]==num){
        cout<<"Element "<<num<<"at index "<<mid<<endl;
    }
    return 0;
}