/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &adjacency_list, vector<int> &visited, vector<int> &distance, int n){
    queue<int> q;
    q.push(n);
    distance.at(n) = 0;
    visited.at(n) = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0; i<adjacency_list.at(t).size(); i++){
            if(!visited.at(adjacency_list.at(t).at(i))){
                q.push(adjacency_list.at(t).at(i));
                distance.at(adjacency_list.at(t).at(i)) = distance.at(t)+1;
                visited.at(adjacency_list.at(t).at(i)) = 1;
            }
        }
    }
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<vector<int>> adjacency_list(n+1);
    vector<int> visited(n+1), distance(n+1);
    queue<int> q;
    cout<<"Enter the graph:"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    cout<<"Enter the starting element: ";
    int start; cin>>start;
    bfs(adjacency_list, visited, distance, 1);
    cout<<"Enter the ending element: ";
    int end; cin>>end;
    cout<<"The shortest distance between starting node and the ending node is: "<<distance.at(end)<<endl; 
    return 0;
}