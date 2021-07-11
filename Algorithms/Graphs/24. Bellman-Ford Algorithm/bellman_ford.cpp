/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void bellman_ford(int s, vector<vector<int>>& adj, vector<int>& dist, int n, int m){
    dist.at(s) = 0;
    for(int k=0; k<n-1; k++){
        for(const auto &v: adj){
            int a = v.at(0);
            int b = v.at(1);
            int w = v.at(2);

            if(dist.at(a) != INT_MAX){
                if(dist.at(a)+w < dist.at(b)){
                    dist.at(b) = dist.at(a) + w;
                }
            }
        }
    }
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;

    vector<vector<int>> adj;
    cout<<"Enter the graph:\n";
    while(m--){
        vector<int> t(3);
        cin>>t.at(0)>>t.at(1)>>t.at(2);
        adj.push_back(t);
    }
    
    cout<<"Enter the source node: ";
    int s; cin>>s;

    vector<int> dist(n, INT_MAX);
    bellman_ford(s, adj, dist, n, m);

    cout<<"\nDistance of all nodes are as follows\n";
    for(int i=0; i<n; i++){
        cout<<s<<"->"<<dist.at(i)<<endl;
    }
    return 0;
}