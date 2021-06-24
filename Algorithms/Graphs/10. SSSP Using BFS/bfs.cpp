/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> adjacency_list, int n){
    queue<int> q;
    q.push(1);
    vector<int> visited(n+1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(const auto &child: adjacency_list.at(node)){
            if(!visited.at(child)){
                visited.at(child) = 1;
                q.push(child);
            }
        }
    }
    cout<<endl;
}

int main(){
    cout<<"Enter the number of nodes: ";
    int n; cin>>n;
    cout<<"Enter the number of edges: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1);
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    bfs(adjacency_list, n);
    return 0;
}