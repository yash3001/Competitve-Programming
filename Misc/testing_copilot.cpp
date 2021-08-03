/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void dfs(int n, vector<vector<int>> adj, vector<int> &visited){
    visited[n] = 1;
    for(int i = 0; i < adj[n].size(); i++){
        if(visited[adj[n][i]] == 0){
            dfs(adj[n][i], adj, visited);
        }
    }
}

int main(){
    
    return 0;
}