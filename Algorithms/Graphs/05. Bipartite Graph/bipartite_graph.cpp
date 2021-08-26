/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &adjacency_list, vector<int> &visited, vector<int> &colour, int n, int c){
    visited.at(n) = 1;
    colour.at(n) = c;
    for(int i=0; i<adjacency_list.at(n).size(); i++){
        if(!visited.at(adjacency_list.at(n).at(i))){
            if(!dfs(adjacency_list, visited, colour, adjacency_list.at(n).at(i), c^1)){
                return false;
            }
        }
        else{
            if(colour.at(n) == colour.at(adjacency_list.at(n).at(i))){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cout<<"Enter the number of nodes: ";
    int n; cin>>n;
    cout<<"Enter the number of edges: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1);
    vector<int> visited(n+1), colour(n+1);
    cout<<"Enter the edges:"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    if(dfs(adjacency_list, visited, colour, 1, 0)){
        cout<<"The given graph is bipartite graph"<<endl;
    }
    else{
        cout<<"The given graph is not a bipartite graph"<<endl;
    }
    return 0;
}