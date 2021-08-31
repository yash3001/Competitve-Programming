// Generate all subsets of a set containing elements from 0 to n-1

/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;

void subset(int k){
    if(k == n){
        for(int i=0; i<nums.size(); i++){
            cout<<nums.at(i)<<" ";
        }
        cout<<endl;
    }
    else{
        subset(k+1);
        nums.push_back(k);
        subset(k+1);
        nums.pop_back();
    }
}

int main(){
    cin>>n;
    subset(0);    
    return 0;
}