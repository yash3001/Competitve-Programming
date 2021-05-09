/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> *adjacency_list, vector<int> &visited, int node){
    visited.at(node) = 1;
    cout<<node<<" ";
    for(const auto &n: adjacency_list[node]){
        if(!visited[n])
            dfs(adjacency_list, visited, n);
    }
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<int> adjacency_list[n+1], visited(n+1, 0);
    cout<<"Enter the edges:"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
    dfs(adjacency_list, visited, 1);
    cout<<endl;
    return 0;
}