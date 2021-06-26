/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adjacency_list(1001);
vector<int> dist(1001, INT_MAX);

void dijkstra(int start){
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    
    pq.push({0, start});
    dist.at(start) = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int node_d = pq.top().first;

        pq.pop();

        for(const auto &p: adjacency_list.at(node)){
            if(node_d + p.second < dist.at(p.first)){
                dist.at(p.first) = node_d+p.second;
                pq.push({dist.at(p.first), p.first});
            }
        }
    }
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    cout<<"Enter the graph:\n";
    while(m--){
        int a, b, w;
        cin>>a>>b>>w;
        adjacency_list.at(a).push_back({b, w});        
        adjacency_list.at(b).push_back({a, w});        
    }
    cout<<"\nEnter the starting node: ";
    int start; cin>>start;
    dijkstra(start);
    // cout<<"Enter the ending node: ";
    // int end; cin>>end;
    // cout<<"The shortest path distance is: "<<dist.at(end)<<endl;
    cout<<"\nShortest distances are as follows:\n";
    for(int i=0; i<n; i++){
        cout<<start<<" -> "<<i<<" = "<<dist.at(i)<<endl;
    }
    return 0;
}