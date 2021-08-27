/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adjacency_list, vector<int> &visited, vector<int> &distance, int n, int d){
    visited.at(n) = 1;
    distance.at(n) = d;
    for(int i=0; i<adjacency_list.at(n).size(); i++){
        if(!visited.at(adjacency_list.at(n).at(i))){
            dfs(adjacency_list, visited, distance, adjacency_list.at(n).at(i), d+1);
        }
    }
}

int main(){
    cout<<"Enter the number of nodes: ";
    int n; cin>>n;
    cout<<"Enter the number of edges: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1);
    vector<int> visited(n+1), distance(n+1);
    cout<<"Enter the edges:"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    cout<<"Enter the starting node: ";
    int start; cin>>start;
    cout<<"Enter the ending node: ";
    int end; cin>>end;
    dfs(adjacency_list, visited, distance, start, 0);
    cout<<"The minimum distance between the two nodes is "<<distance.at(end)<<endl;
    return 0;
}