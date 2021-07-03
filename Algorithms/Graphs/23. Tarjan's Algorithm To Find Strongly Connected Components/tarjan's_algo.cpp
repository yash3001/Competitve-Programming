/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int timer;
vector<vector<int>> adj(1001);
vector<int> lo(1001), in(1001), visited(1001, 0), active(1001, 0);
stack<int> st;

void dfs(int n){
    visited.at(n) = 1;
    lo.at(n) = in.at(n) = timer++;
    active.at(n) = 1;
    st.push(n);
    for(const auto &c: adj.at(n)){
        if(visited.at(c)){
            if(active.at(c)){
                lo.at(n) = min(lo.at(n), in.at(c));
            }
        }
        else{
            dfs(c);
            if(active.at(c)){
                lo.at(n) = min(lo.at(n), lo.at(c));
            }
        }
    }
    if(lo.at(n)==in.at(n)){
        while(st.top() != n){
            cout<<st.top()<<" ";
            active.at(st.top()) = 0;
            st.pop();
        }
        cout<<st.top()<<endl;
        active.at(st.top()) = 0;
        st.pop();
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
        adj.at(a).push_back(b);
    }
    cout<<"The strongly connected components are:\n";
    for(int i=1; i<n+1; i++){
        if(!visited.at(i)){
            dfs(i);
        }
    }
    return 0;
}