/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

struct node{
    int a, b, w;
};

bool comp(node x, node y){
    return (x.w < y.w);
}

node graph[1001];
int n, m, parent[1001];

int find(int n){
    if(parent[n] == -1){
        return n;
    }
    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    parent[a] = b;
}

void kruskal(){
    int ans{};
    for(int i=0; i<m; i++){
        int a = find(graph[i].a);
        int b = find(graph[i].b);
        if(a != b){
            merge(a, b);
            ans += graph[i].w;
        }
    }
    cout<<ans<<endl;
}

int main(){
    memset(parent, -1, sizeof(parent));
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"Enter the graph: ";
    for(int i=0; i<m; i++){
        int a, b, w; cin>>a>>b>>w;
        graph[i].a = a;
        graph[i].b = b;
        graph[i].w = w;
    }
    sort(graph, graph+m, comp);
    kruskal();
    return 0;
}