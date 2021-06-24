/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int grid[1001][1001], visited[1001][1001], m, n;
int xadd[]{-1, 0, 1, 0}, yadd[]{0, 1, 0, -1};

bool isValid(int i, int j){
    return (i<m && i>=0 && j<n && j>=0 && grid[i][j] && !visited[i][j]);
}

void dfs(int i, int j){
    visited[i][j] = 1;
    for(int k=0; k<4; k++){
        if(isValid(i+xadd[k],j+yadd[k])){
            dfs(i+xadd[k], j+yadd[k]);
        }
    }
}

int main(){
    cout<<"Enter the size of the grid(mxn): ";
    cin>>m>>n;
    cout<<"Enter the grid\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    int ans{};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] && !visited[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout<<"Number of connected components are: "<<ans<<endl;
    return 0;
}