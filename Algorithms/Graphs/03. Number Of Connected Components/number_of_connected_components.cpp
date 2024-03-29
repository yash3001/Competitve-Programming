/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adjacency_list, vector<int> &visited, int node){
    visited.at(node) = 1;
    for(int i=0; i<adjacency_list.at(node).size(); i++){
        if(!visited.at(adjacency_list.at(node).at(i)))
            dfs(adjacency_list, visited, adjacency_list.at(node).at(i));
    }
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1); 
    vector<int> visited(n+1, 0);
    cout<<"Enter the edges:"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
    int ans{};
    for(int i=1; i<n+1; i++){
        if(!visited.at(i)){
            ans++;
            dfs(adjacency_list, visited, i);
        }
    }
    cout<<"The number of connected components are "<<ans<<endl;
    return 0;
}