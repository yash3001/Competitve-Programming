/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj(1001);
vector<int> dist(1001, INT_MAX);

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    dist.at(0) = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        int node = pq.top().first;
        int node_d = pq.top().second;
        pq.pop();
        for(const auto &p: adj.at(node)){
            if(p.second + node_d < dist.at(p.first)){
                dist.at(p.first) = p.second + node_d;
                pq.push({dist.at(p.first), p.first});
            }
        }
    }
}

int main(){
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"Enter the graph\n";
    while(m--){
        int a, b, w; cin>>a>>b>>w;
        adj.at(a).push_back({b, w});
        adj.at(b).push_back({a, w});
    }
    cout<<"Enter the ending node: ";
    int end; cin>>end;
    dijkstra();
    cout<<"Shortest distance from node 0 to node "<<end<<" is: "<<dist.at(end)<<endl;
    return 0;
}