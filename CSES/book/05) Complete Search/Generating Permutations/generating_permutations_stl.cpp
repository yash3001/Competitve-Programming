/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        nums.push_back(i);
    }
    do{
        for(int i=0; i<n; i++){
            cout<<nums.at(i)<<" ";
        }
        cout<<endl;
    }while(next_permutation(nums.begin(), nums.end()));
    return 0;
}