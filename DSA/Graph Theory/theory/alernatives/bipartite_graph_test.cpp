/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adlist(100001);
vector<int> visited(100001, 0), color(100001, 0);

bool dfs(int n, int col){
    visited.at(n) = 1;
    color.at(n) = col;
    for(int i=0; i<adlist.at(n).size(); i++){
        if(!visited.at(adlist.at(n).at(i))){
            if(!dfs(adlist.at(n).at(i), !col)){
                return false;
            }
        }
        else if(col==color.at(adlist.at(n).at(i))){
            return false;
        }
    }
    return true;
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
    if(dfs(1, color.at(1))){
        cout<<"Graph is bipartite"<<endl;
    }
    else{
        cout<<"Graph is not bipartite"<<endl;
    }
    return 0;
}