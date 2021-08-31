/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int maxPath(vector<vector<int>> mat, int r, int c){
    vector<vector<int>> dp(r+1, vector<int>(c+1, 0));

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + mat[i-1][j-1];
        }
    }

    return dp[r][c];
}

int main(){
    // cout<<"Enter the rows and columns in the matrix: ";
    int r, c; cin>>r>>c;
    // cout<<"Enter the matrix:\n";
    vector<vector<int>> mat(r, vector<int>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>mat[i][j];
        }
    }

    cout<<maxPath(mat, r, c);
    return 0;
}