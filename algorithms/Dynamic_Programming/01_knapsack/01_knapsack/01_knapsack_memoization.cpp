/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> weight, vector<int> value, int w, int n);

//max w - 10000
//max n - 10000
int dp[10001][10001];

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
    cout<<"The maximum profit is: "<<knapsack(weight, value, w, n)<<endl;
    return 0;
}

int knapsack(vector<int> weight, vector<int> value, int w, int n){
    if(n==0 || w==0){
        return 0;
    }

    if(dp[w][n]!=-1){
        return(dp[w][n]);
    }

    if(weight[n-1]<=w){
        return dp[w][n]=(max(value[n-1] + knapsack(weight, value, w-weight[n-1], n-1), knapsack(weight, value, w, n-1)));
    }
    else{
        return dp[w][n]=(knapsack(weight, value, w, n-1));
    }
}