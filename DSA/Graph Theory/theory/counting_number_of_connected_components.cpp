#include<bits/stdc++.h>

using namespace std;

void bfs(int n, vector<vector<int>> &adlist, vector<int> &vis){
    vis.at(n) = 1;
    for(int i=0; i<adlist.at(n).size(); i++){
        if(!vis.at(adlist.at(n).at(i))){
            bfs(adlist.at(n).at(i), adlist, vis);
        }
    }
}

int main(){
    cout<<"Enter the number of nodes"<<endl;
    int n; cin>>n;
    vector<vector<int>> adlist(n+1);
    cout<<"Enter the number of edges"<<endl;
    int m; cin>>m;
    cout<<"Enter the edges"<<endl;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adlist.at(a).push_back(b);
        adlist.at(b).push_back(a);
    }
    vector<int> visited(n+1, 0);
    int count{};
    for(int i=1; i<n+1; i++){
        if(visited.at(i)==0){
            bfs(i, adlist, visited);
            count++;
        }
    }
    cout<<"Number of connected components in the graph is "<<count<<endl;
    return 0;
}