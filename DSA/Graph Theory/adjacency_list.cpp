#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;  // nodes
    vector<int> adjacency_list[n+1];
    int m; cin>>m; // edges
    while(m--){
        int a,b; cin>>a>>b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
    return 0;
}