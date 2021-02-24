/* @author -> gamma30 */
// Print the largest sum possible in contiguos subarray
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the size of the subarray ";
    int n; cin>>n;

    vector<int> arr(n); int are_negative{1}, min_negative{-1'000'000'001};
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr.at(i);
        if(arr.at(i)>=0){
            are_negative = 0;
        }
        if(are_negative){
            if(arr.at(i)>min_negative){
                min_negative = arr.at(i);
            }
        }
    }
    
    if(are_negative){
        cout<<"The maximum sum possible is "<<min_negative<<endl;
    } 
    else{
    // kadane's algorithm
        int max_sum{}, current_sum{};
        for(int i=0; i<n; i++){
            current_sum += arr.at(i);
            if(current_sum>max_sum)
                max_sum = current_sum;
            if(current_sum<0)
                current_sum = 0;
        }
        cout<<"The maximum sum possible is "<<max_sum<<endl;
    }

    return 0;
}