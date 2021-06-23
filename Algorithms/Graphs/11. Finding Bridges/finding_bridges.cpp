#include <bits/stdc++.h>

using namespace std;

vector<int> in(1001, 0), low(1001, 0), visited(1001, 0);
vector<vector<int>> adjacency_list(1001);
int timer=0;

void dfs(int v, int p){
    visited.at(v) = 1;
    low.at(v) = in.at(v) = timer++;
    for(int n: adjacency_list.at(v)){
        if(n == p){
            continue;
        }
        else if(visited.at(n)){
            low.at(v) = min(low.at(v), in.at(n));
        }
        else{
            dfs(n, v);
            low.at(v) = min(low.at(v), low.at(n));
            if(low.at(n)>in.at(v)){
                cout<<v<<"-"<<n<<" is a bridge"<<endl;
            }
        }
    }
}

int main(){
    cout<<"Enter the number of nodes: ";
    int n; cin>>n;
    cout<<"Enter the number of edges: ";
    int m; cin>>m;
    cout<<"Enter the graph\n";
    while(m--){
        int a, b; cin>>a>>b;
        adjacency_list.at(a).push_back(b);
        adjacency_list.at(b).push_back(a);
    }
    dfs(1, -1);
    return 0;
}