/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<int> visited(1001, 0), low(1001, 0), in(1001, 0);
vector<vector<int>> adjacecny_list(1001);
int counter{1};
set<int> s;

void dfs(int v, int p){
    visited.at(v) = 1;
    low.at(v) = in.at(v) = counter++;
    int child_cnt = 0;
    for(const auto &n: adjacecny_list.at(v)){
        if(n == p){
            continue;
        }
        else if(visited.at(n)){
            low.at(v) = min(low.at(v), in.at(n));
        }
        else{
            dfs(n, v);
            child_cnt++;
            low.at(v) = min(low.at(v), low.at(n));
            if(low.at(n) >= in.at(v) && p != -1){
                s.insert(v);
            }
        }
    }
    if(p == -1 && child_cnt > 1){
        s.insert(v);
    }
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    cout<<"Enter the graph:\n";
    while(m--){
        int a, b; cin>>a>>b;
        adjacecny_list.at(a).push_back(b);
        adjacecny_list.at(b).push_back(a);
    } 
    dfs(1, -1);
    cout<<"The articulations points are: ";
    for(const auto &n: s){
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}