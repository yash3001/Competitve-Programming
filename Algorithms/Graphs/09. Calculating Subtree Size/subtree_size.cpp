/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> &adjacency_list, vector<int> &visited, vector<int> &size, int n){
    visited.at(n) = 1;
    int count{1};
    for(int i=0; i<adjacency_list.at(n).size(); i++){
        if(!visited.at(adjacency_list.at(n).at(i))){
            count += size.at(adjacency_list.at(n).at(i)) = dfs(adjacency_list, visited, size, adjacency_list.at(n).at(i));
        }
    }
    return count;
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1);
    vector<int> visited(n+1), size(n+1);
    cout<<"Enter the edges:"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }

    size.at(1) = dfs(adjacency_list, visited, size, 1);
    for(int i=1; i<size.size(); i++){
        cout<<size.at(i)<<" ";
    }
    cout<<endl;
    return 0;
}