/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &adjacency_list, vector<int> &visited, int n, int p){
    visited.at(n) = 1;
    for(int i=0; i<adjacency_list.at(n).size(); i++){
        if(!visited.at(adjacency_list.at(n).at(i))){
            if(!dfs(adjacency_list, visited, adjacency_list.at(n).at(i), n)){
                return false;
            }
        }
        else{
            if(adjacency_list.at(n).at(i) != p){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1);
    vector<int> visited(n+1);
    cout<<"Enter the edges:"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    if(!dfs(adjacency_list, visited, 1, 1)){
        cout<<"The graph has a cycle"<<endl;
    }
    else{
        cout<<"The graph doesn't have cycles"<<endl;
    }
    return 0;
}