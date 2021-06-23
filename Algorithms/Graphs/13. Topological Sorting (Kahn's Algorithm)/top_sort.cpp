/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adjacency_list(1001);
vector<int> in_deg(1001, 0);

void top_sort(int n){
    queue<int> q;
    vector<int> ans;
    for(int i=1; i<n+1; i++){
        if(in_deg.at(i)==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v = q.front();
        ans.push_back(v);
        q.pop();
        for(const auto &c: adjacency_list.at(v)){
            if(--in_deg.at(c) == 0){
                q.push(c);
            }
        }
    }
    for(int i=1; i<n+1; i++){
        if(in_deg.at(i) != 0){
            cout<<"Topological sorting not possible, loop found."<<endl;
            return;
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Enter the number of nodes: ";
    int n; cin>>n;
    cout<<"Enter the number of edges: ";
    int m; cin>>m;
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        in_deg.at(b)++;
    }
    top_sort(n);
    return 0;
}