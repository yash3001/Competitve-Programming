#include<bits/stdc++.h>

using namespace std;

bool dfs(int n, vector<vector<int>> &adlist, vector<int> &visited, vector<int> &color, int c){
    visited.at(n) = 1;
    color.at(n) = c;
    for(int i=0; i<adlist.at(n).size(); i++){
        if(!visited.at(adlist.at(n).at(i))){
            if(!dfs(adlist.at(n).at(i), adlist, visited, color, !c)){
                return false;
            }
        }
        else if(color.at(adlist.at(n).at(i))==c){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<"Enter the number of nodes"<<endl;
    int n; cin>>n;
    vector<vector<int>> adlist(n+1);
    cout<<"Enter the number of edges"<<endl;
    int m; cin>>m;
    cout<<"Enter the edges"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adlist.at(a).push_back(b);
        adlist.at(b).push_back(a);
    }
    vector<int> visited(n+1, 0), color(n+1, 0);
    if(!dfs(1, adlist, visited, color, 0)){
        cout<<"Not a bipartite graph"<<endl;
    }
    else{
        cout<<"Bipartite graph"<<endl;
    }
    return 0;
}