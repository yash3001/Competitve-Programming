/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> a, vector<int> b, int n, int m){
    vector<vector<int>> adj(n+1);
    vector<pair<int, int>> count;
    for(int i=0; i<m; i++){
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    unordered_map<int, int> mp;

    for(int i=1; i<=n; i++){
        count.push_back({adj[i].size(), i});
    }
    sort(count.begin(), count.end(), greater<pair<int, int>>());
    int t = n;
    for(int i=0; i<count.size(); i++){
        mp[count[i].second] = t--;
    }

    int ans = 0;
    vector<int> visited(n+1, 0);
    for(int i=1; i<=n; i++){
        if(adj[i].size() != 0){
            visited[i] = 1;
            for(const auto &c: adj[i]){
                if(!visited[c]){
                    ans += mp[i]+mp[c];
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    int n, m; cin>>n>>m;
    vector<int> a(n), b(n);
    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    solve(a, b, n, m);
    return 0;
}