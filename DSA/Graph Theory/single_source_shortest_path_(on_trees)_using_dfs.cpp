#include<bits/stdc++.h>

using namespace std;

void dfs(int n, vector<vector<int>> &adlist, vector<int> &visited, vector<int> &distance, int dist){
    visited.at(n) = 1;
    distance.at(n) = dist;
    for(int i=0; i<adlist.at(n).size(); i++){
        if(!visited.at(adlist.at(n).at(i)))
            dfs(adlist.at(n).at(i), adlist, visited, distance, dist+1);
    }
}

int main(){

    cout<<"Enter the number of nodes"<<endl;
    int n; cin>>n;
    vector<vector<int>> adlist(n+1);
    cout<<"Enter the number of edges"<<endl;
    int m; cin>>m;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adlist.at(a).push_back(b);
        adlist.at(b).push_back(a);
    }
    vector<int> visited(n+1, 0), distance(n+1, 0);
    cout<<"Enter the source node"<<endl;
    int source; cin>>source;
    dfs(source, adlist, visited, distance, 0);
    for(int i=1; i<n+1; i++){
        cout<<"Distance of node "<<i<<" from node "<<source<<" is "<<distance.at(i)<<endl;
    }
    return 0;
}