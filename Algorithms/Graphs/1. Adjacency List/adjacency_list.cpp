/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges: ";
    int m; cin>>m;
    vector<int> adjacency_list[n+1];
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
    return 0;
}