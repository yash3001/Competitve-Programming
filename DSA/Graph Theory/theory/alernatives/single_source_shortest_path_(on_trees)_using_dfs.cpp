/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adlist(100001);
vector<int> visited(100001, 0);
vector<int> dist(100001, 0);

void dfs(int n, int d){
    visited.at(n) = 1;
    dist.at(n) = d;
    cout<<n<<endl;
    for(int i=0; i<adlist.at(n).size(); i++){
        if(!visited.at(adlist.at(n).at(i))){
            dfs(adlist.at(n).at(i), d+1);
        }
    }
}

int main(){
    cout<<"Enter the number of nodes ";
    int n; cin>>n;
    cout<<"Enter the number of edges ";
    int m; cin>>m;
    cout<<"Enter the edges"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adlist.at(a).push_back(b);
        adlist.at(b).push_back(a);
    }
    cout<<"Enter the source node ";
    int s; cin>>s;
    dfs(s, 0);
    for(int i=1; i<=n; i++){
        cout<<"Distance of "<<i<<" from "<<s<<" is "<<dist.at(i)<<endl;
    }
    return 0;
}