/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<vector<int>> adj(n);
    cout<<"Enter the graph\n";
    while(m--){
        int a, b; cin>>a>>b;
        adj.at(a).push_back(b);
        adj.at(b).push_back(a);
    }
    for(int i=0; i<n; i++){
        for(const auto &c: adj.at(i)){
            cout<<i<<"->"<<c<<endl;
        }
    }
    return 0;
}