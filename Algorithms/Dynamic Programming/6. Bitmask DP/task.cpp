/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cost[i][j];
        }
    }

    int m = (1<<n)-1;
    vector<vector<int>> dp(n+1, vector<int>(m, 0));
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = INT_MAX;
            
        }
    }
    return 0;
}