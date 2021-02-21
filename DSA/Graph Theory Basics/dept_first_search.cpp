#include<bits/stdc++.h>

using namespace std;

void dfs(int n, vector<int> &vis, vector<vector<int>> &list){
    vis.at(n) = 1;
    cout<<n<<" ";
    for(int i=0; i<list.at(n).size(); i++){
        if(!vis.at(list.at(n).at(i))){
            dfs(list.at(n).at(i), vis, list);
        }
    }
}

int main(){
    int n; cin>>n;  // nodes
    vector<vector<int>> adjacency_list(n+1);
    int m; cin>>m; // edges
    while(m--){
        int a,b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }

    vector<int> visited(n+1, 0);
    dfs(1, visited, adjacency_list);
    cout<<endl;
}