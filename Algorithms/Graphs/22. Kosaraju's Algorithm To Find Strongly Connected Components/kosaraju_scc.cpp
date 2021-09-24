/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void first_dfs(int n, vector<vector<int>> &adj, vector<int> &visited, vector<int> &order){
    visited.at(n) = 1;
    for(const auto &c: adj.at(n)){
        if(!visited.at(c)){
            first_dfs(c, adj, visited, order);
        }
    }
    order.push_back(n);
}

void second_dfs(int n, vector<vector<int>> &adj, vector<int> &visited){
    visited.at(n) = 1;
    cout<<n<<" ";
    for(const auto &c: adj.at(n)){
        if(!visited.at(c)){
            second_dfs(c, adj, visited);
        }
    }
}

int main(){
    cout<<"Enter the number of nodes in the graph: ";
    int n; cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    int m; cin>>m;
    vector<vector<int>> adj(n+1), rev_adj(n+1);
    cout<<"Enter the graph:\n";
    while(m--){
        int a, b; cin>>a>>b;
        adj.at(a).push_back(b);
        rev_adj.at(b).push_back(a);
    }
    vector<int> visited(n+1, 0), order;
    for(int i=1; i<n+1; i++){
        if(!visited.at(i)){
            first_dfs(i, adj, visited, order);
        }
    }
    fill(visited.begin(), visited.end(), 0);
    int count{};
    for(int i=order.size()-1; i>=0; i--){
        if(!visited.at(order.at(i))){
            cout<<"\nSCC number "<<++count<<" is: ";
            second_dfs(order.at(i), rev_adj, visited);
        }
    }
    cout<<endl;
    return 0;
}