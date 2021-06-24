/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int grid[1001][1001], m, n;
int visited[1001][1001], dist[1001][1001];
int xadd[]{-1, 0, 1, 0}, yadd[]{0, 1, 0, -1};

bool isValid(int i, int j){
    return (i>=0 && i<m && j>=0 && j<n && grid[i][j] && !visited[i][j]);
}

void dfs(int i, int j, int d){
    dist[i][j] = d;
    visited[i][j] = 1;
    for(int k=0; k<4; k++){
        if(isValid(i+xadd[k], j+yadd[k])){
            dfs(i+xadd[k], j+yadd[k], d+1);
        }
    }
}

int main(){
    cout<<"Enter the size of the grid(mxn): ";    
    cin>>m>>n;
    cout<<"Enter the grid:\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    dfs(0, 0, 0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}