/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int rod_cutting(vector<int> &length, vector<int> &value, int w, int n);

int dp[1001][1001];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the lenght of the rod: ";
    int l; cin>>l;
    int n; n=l;
    vector<int> value(n), length(n);
    cout<<"Enter the weight of the elements:"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter value for length "<<i+1<<" of rod: ";
        cin>>value[i];
    }
    for(int i=1; i<=l; i++){
        length.at(i-1) = i;
    }
    cout<<"The maximum profit is: "<<rod_cutting(length, value, l, n)<<endl;
    return 0;
}

int rod_cutting(vector<int> &length, vector<int> &value, int l, int n){
    if(n==0 || l==0){
        return dp[n][l] = 0;
    }
    
    if(dp[n][l]!=-1){
        return dp[n][l];
    }

    if(length[n-1]<=l){
        return dp[n][l]=max(value[n-1] + rod_cutting(length, value, l-length[n-1], n), rod_cutting(length, value, l, n-1));
    }
    else{
        return dp[n][l]=rod_cutting(length, value, l, n-1);
    }
}