/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

struct node{
    int a;
    int b;
    int w;
};

node graph[1001];
int n, m, parent[1001];

bool comp(node a, node b){
    return (a.w < b.w);
}

int find(int n){
    if(parent[n] == -1){
        return n;
    }
    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    parent[a] = b;
}

int kruskal(){
    int ans{};
    cout<<"\nThe minimum spanning tree for the given graph is:\n";
    for(int i=0; i<m; i++){
        int a = find(graph[i].a);
        int b = find(graph[i].b);
        if(a != b){
            merge(a, b);
            cout<<graph[i].a<<" "<<graph[i].b<<" "<<graph[i].w<<endl;
            ans += graph[i].w;
        }
    }
    return ans;
}

int main(){
    memset(parent, -1, sizeof(parent));
    cout<<"Enter the number of nodes in the graph: ";
    cin>>n;
    cout<<"Enter the number of edges in the graph: ";
    cin>>m;
    cout<<"Enter the graph\n";
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        graph[i].a = a;
        graph[i].b = b;
        graph[i].w = w;
    }
    sort(graph, graph + m, comp);
    int ans = kruskal();
    cout<<"The total weight of the minimum spanning tree is: "<<ans<<endl;
    return 0;
}