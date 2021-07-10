/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void dfs1(int n, vector<vector<int>> &adj, vector<int> &visited, vector<int> &order){
    visited.at(n) = 1;
    for(const auto &c: adj.at(n)){
        if(!visited.at(c)){
            dfs1(c, adj, visited, order);
        }
    }
    order.push_back(n);
}

void dfs2(int n, vector<vector<int>> &adj, vector<int> &visited){
    visited.at(n) = 1;
    for(const auto &c: adj.at(n)){
        if(!visited.at(c)){
            dfs2(c, adj, visited);
        }
    }
}

int main(){
    cout<<"Enter the number of nodes of the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges: ";
    int m; cin>>m;
    cout<<"Enter the graph:\n";
    vector<vector<int>> adj(n);
    vector<int> visited(n, 0), visited1(n, 0), order;
    while(m--){
        int a, b; cin>>a>>b;
        adj.at(a).push_back(b);
    }
    for(int i=0; i<n; i++){
        if(!visited.at(i))  dfs1(i, adj, visited, order);
    }
    int ans{};
    for(const auto &n: order){
        if(!visited1.at(n)){
            ans++;
            dfs2(n, adj, visited1);
        }
    }
    cout<<ans<<endl;
    return 0;
}