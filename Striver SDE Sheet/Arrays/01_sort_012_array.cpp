// using dutch flag algorithm
// we will use 3 pointers (low, mid, high) and assume that all the elements to the right of high are 2 and all elements to the left of low are 0.

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(auto &n: nums){
        cin>>n;
    }

    int high = n-1, low = 0, mid = 0;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[mid], nums[high]);
            high--;
        }
        else{
            mid++;
        }
    }


    for(const auto &c: nums){
        cout<<c<<" ";
    }

    return 0;
}