/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int grid[1001][1001], n, m;
int xadd[]{-1, 0, 1, 0}, yadd[]{0, 1, 0, -1};

bool isValid(int i, int j){
    if(i<=m && i>=1 && j<=n && n>=1){
        if(!grid[i][j]){
            return true;
        }
        return false;
    }
    return false;
}

void dfs(int i, int j){
    grid[i][j] = 1;
    cout<<i<<" "<<j<<endl;
    for(int k=0; k<4; k++){
        if(isValid(i+xadd[k], j+yadd[k])){
            dfs(i+xadd[k], j+yadd[k]);
        }
    }
}

int main(){
    cout<<"Enter the size of the grid(mxn): ";
    cin>>m>>n;
    dfs(1, 1);   
    return 0;
}