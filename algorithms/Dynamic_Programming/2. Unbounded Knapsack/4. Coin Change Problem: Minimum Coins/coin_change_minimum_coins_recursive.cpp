/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int coin_change(vector<int> &coins, int sum, int n);

int main(){
    cout<<"Enter the number of coins: ";
    int n; cin>>n;

    vector<int> coins(n);
    cout<<"Enter the value of the elements: ";
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    int sum{};
    cout<<"Enter the sum: ";
    cin>>sum;
    cout<<"The minimum number of coins are: "<<coin_change(coins, sum, n)<<endl;
    return 0;
}

int coin_change(vector<int> &coins, int sum, int n){
    if(n==0){
        return INT_MAX-1;
    }
    else if(sum == 0){
        return 0;
    }
    if(n==1 && sum != 0){
        if(sum%coins[0]==0){
            return sum/coins[0];
        }
        else{
            return INT_MAX-1;
        }
    }
    if(coins[n-1]<=sum){
        return min(1+coin_change(coins, sum-coins[n-1], n), coin_change(coins, sum, n-1));
    }
    else{
        return coin_change(coins, sum, n-1);
    }
}