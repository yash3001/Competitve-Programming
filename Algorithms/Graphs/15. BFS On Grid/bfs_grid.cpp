/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int grid[1001][1001], m, n;
int xadd[]{-1, 0, 1, 0}, yadd[]{0, 1, 0 , -1};

bool isValid(int i, int j){
    return (i>=0 && i<m && j>=0 && j<n && !grid[i][j]);
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = 1;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        cout<<i<<" "<<j<<endl;
        for(int k=0; k<4; k++){
            if(isValid(i+xadd[k], j+yadd[k])){
                grid[i+xadd[k]][j+yadd[k]] = 1;
                q.push({i+xadd[k], j+yadd[k]});
            }
        }
    }
}

int main(){
    cout<<"Enter the size of the gird(mxn): ";
    cin>>m>>n;
    bfs(0, 0);
    return 0;
}