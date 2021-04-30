#include<bits/stdc++.h>

using namespace std;

int main(){
    long long size; cin>>size;
    long long arr[size];
    for(int i=0; i<size; i++){
        long long num; cin>>num;
        arr[i] = num;
    }

    cout<<"Before sorting:"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    // bubble sort
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(arr[j]>arr[j+1]){
                long long temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout<<"\n\n";
    cout<<"After sorting:"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}