/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> weight, vector<int> value, int w, int n);

//max w - 10000
//max n - 10000
int dp[10001][10001];

int main(){
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
    for(int j=0; j<n+1; j++){
        dp[0][j] = 0;
    }
    for(int i=0; i<w+1; i++){
        dp[i][0] = 0;
    }
    for(int i=1; i<w+1; i++){
        for(int j=1; j<n+1; j++){
            if(weight[j-1]<=i){
                dp[i][j]=max(value[j-1] + dp[i-weight[j-1]][j-1], dp[i][j-1]);
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    return(dp[w][n]);
}