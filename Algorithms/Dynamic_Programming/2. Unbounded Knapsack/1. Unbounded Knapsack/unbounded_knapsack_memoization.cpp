/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int unbounded_knapsack(vector<int> weight, vector<int> value, int w, int n);

int dp[1001][1001];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the capacity of the knapsack: ";
    int w; cin>>w;
    cout<<"Enter the number of elements: ";
    int n; cin>>n;
    vector<int> weight(n), value(n);
    cout<<"Enter the weight of the elements:"<<endl;
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }
    cout<<"Enter the value of the elements:"<<endl;
    for(int i=0; i<n; i++){
        cin>>value[i];
    }
    cout<<"The maximum profit is: "<<unbounded_knapsack(weight, value, w, n)<<endl;
    return 0;
}

int unbounded_knapsack(vector<int> weight, vector<int> value, int w, int n){
    if(n==0 || w==0){
        return dp[n][w]=0;
    }

    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    if(weight[n-1]<=w){
        return dp[n][w]=max(value[n-1] + unbounded_knapsack(weight, value, w-weight[n-1], n), unbounded_knapsack(weight, value, w, n-1));
    }
    else{
        return dp[n][w]=unbounded_knapsack(weight, value, w, n-1);
    }
}