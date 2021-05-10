/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int timer{1};

void dfs(vector<vector<int>> &adjacency_list, vector<int> &visited, vector<int> &start, vector<int> &end, int n){
    visited.at(n) = 1;
    start.at(n) = timer++;
    for(int i=0; i<adjacency_list.at(n).size(); i++){
        if(!visited.at(adjacency_list.at(n).at(i))){
            dfs(adjacency_list, visited, start, end, adjacency_list.at(n).at(i));
        }
    }
    end.at(n) = timer++;
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1);
    vector<int> visited(n+1), start(n+1), end(n+1);
    cout<<"Enter the edges:"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    dfs(adjacency_list, visited, start, end, 1);
    cout<<"Enter the first node: ";
    int a; cin>>a;
    cout<<"Enter the second node: ";
    int b; cin>>b;
    if(start.at(a)<start.at(b) && end.at(a)>end.at(b)){
        cout<<"Node "<<b<<" is present on the subgraph of node "<<a<<endl;
    }
    else{
        cout<<"Node "<<b<<" is not present on the subgraph of node "<<a<<endl;
    }
    return 0;
}