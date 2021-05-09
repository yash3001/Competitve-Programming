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

    for(int i=0; i<n+1; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<w+1; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(weight[i-1]<=j){
                dp[i][j] = max(value[i-1]+dp[i][j-weight[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}