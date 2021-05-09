/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int coin_change(vector<int> &value, int sum, int n);

int main(){

    cout<<"Enter the number of coins: ";
    int n; cin>>n;

    vector<int> value(n);
    cout<<"Enter the value of the elements: ";
    for(int i=0; i<n; i++){
        cin>>value[i];
    }

    int sum{};
    cout<<"Enter the sum: ";
    cin>>sum;
    cout<<"The number of ways are: "<<coin_change(value, sum, n)<<endl;
    return 0;
}

int coin_change(vector<int> &value, int sum, int n){

    if(sum==0){
        return 1;
    }
    else if(n==0){
        return 0;
    }

    if(value[n-1]<=sum){
        return coin_change(value, sum-value[n-1], n)+coin_change(value, sum, n-1);
    }
    else{
        return coin_change(value, sum, n-1);
    }
}