/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
vector<vector<int>> adjacency_list(1001);
vector<int> parent(1001, -1), visited(1001, 0);
int level_x, level_y;

void dfs(int n, int d){
    visited.at(n) = 1;
    if(n == x){
        level_x = d;
    }
    if(n == y){
        level_y = d;
    }
    for(const auto &c: adjacency_list.at(n)){
        if(!visited.at(c)){
            parent[c] = n;
            dfs(c, d+1);
        }
    }
}

int lca(){
    int d = level_x - level_y;
    if(d >= 0){
        while(d--){
            x = parent[x];
        }
    }
    else{
        d = -d;
        while(d--){
            y = parent[y];
        }
    }
    
    if(x==y){
        return x;
    }
    while(parent[x] != parent[y]){
        x = parent[x];
        y = parent[y];
    }
    if(parent[x]==-1){
        return 0;
    }
    return parent[x];
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    cin>>m;
    cout<<"Enter the graph:\n";
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    cout<<"Enter the first node: ";
    cin>>x;
    cout<<"Enter the second node: ";
    cin>>y;
    dfs(0, 0);
    cout<<"Lowest common ancestor of both of the given nodes is: "<<lca()<<endl;
    return 0;
}