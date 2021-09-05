/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool canSum(int sum, vector<int> &coins){
    if(sum == 0){
        return true;
    }
    for(const auto &c: coins){
        if(sum-c >= 0){
            if(canSum(sum-c, coins)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    // cout<<"Enter the number of coins: ";
    int n; cin>>n;
    // cout<<"Enter the coins: ";
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    // cout<<"Enter the target sum: ";
    int sum; cin>>sum;
    // cout<<"The minimum number of coins required to reach the target sum are: ";
    cout<<canSum(sum, coins);
    return 0;
}