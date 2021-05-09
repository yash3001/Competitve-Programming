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

    for(int i=0; i<n+1; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<l+1; i++){
        dp[0][l] = 0;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<l+1; j++){
            if(length[i-1]<=j){
                dp[i][j]=max(value[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][l];
}