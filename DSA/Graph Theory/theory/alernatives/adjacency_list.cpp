/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adlist(100001);

int main(){
    cout<<"Enter the number of nodes"<<endl;
    int n; cin>>n;
    cout<<"Enter the number of edges"<<endl;
    int m; cin>>m;
    cout<<"Enter the edges"<<endl;
    while(m--){
        int a, b; cin>>a>>b;
        adlist.at(a).push_back(b);
        adlist.at(b).push_back(a);
    }
    return 0;
}