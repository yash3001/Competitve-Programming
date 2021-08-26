/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int max_length = INT_MIN, max_node;

void dfs(vector<vector<int>> &adjacency_list, vector<int> &visited, int n, int d){
    visited.at(n) = 1;
    if(d>max_length){
        max_length = d;
        max_node = n;
    }
    for(int i=0; i<adjacency_list.at(n).size(); i++){
        if(!visited.at(adjacency_list.at(n).at(i))){
            dfs(adjacency_list, visited, adjacency_list.at(n).at(i), d+1);
        }
    }
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1);
    vector<int> visited(n+1);
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    dfs(adjacency_list, visited, 1, 0);
    for(int i = 0; i<visited.size(); i++){
        visited.at(i) = 0;
    }
    dfs(adjacency_list, visited, max_node, 0);
    cout<<"Diameter of the tree is "<<max_length<<endl;
    return 0;
}