/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

int grid[1001][1001], m, n;
int visited[1001][1001], dist[1001][1001];
int xadd[]{-1, 0, 1, 0}, yadd[]{0, 1, 0, -1};

bool isValid(int i, int j){
    return (i>=0 && i<m && j>=0 && j<n && grid[i][j] && !visited[i][j]);
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    dist[x][y] = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            if(isValid(i+xadd[k], j+yadd[k])){
                q.push({i+xadd[k], j+yadd[k]});
                visited[i+xadd[k]][j+yadd[k]] = 1;
                dist[i+xadd[k]][j+yadd[k]] = dist[i][j]+1;
            }
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
    bfs(0, 0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}