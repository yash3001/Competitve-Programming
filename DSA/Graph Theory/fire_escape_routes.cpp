/* @author -> gamma30 */
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define endl "\n"
#define EPS 1e-9
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forf(t,i,n) for(t i=0;i<n;i++)
#define forr(t,i,n) for(t i=n-1;i>=0;i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<string> vs;

void dfs(ll n, vector<vector<ll>> &adlist, vll &visited, ll &connected_count){
    visited.at(n) = 1;
    for(int i=0; i<adlist.at(n).size(); i++){
        if(!visited.at(adlist.at(n).at(i))){
            connected_count++;
            dfs(adlist.at(n).at(i), adlist,visited, connected_count);
        }
    }
}

void solve(){
    ll n, m; cin>>n>>m;
    vector<vector<ll>> adlist(n+1);
    vll visited(n+1, 0);
    ll count{};
    while(m--){
        ll a, b; cin>>a>>b;
        adlist.at(a).pb(b);
        adlist.at(b).pb(a);
    }
    ll ans{1};
    for(ll i=1; i<n+1; i++){
        ll connected_count{1};
        if(!visited.at(i)){
            dfs(i, adlist, visited, connected_count);
            count++;
        }
        ans = (ans*connected_count)%MOD;
    }
    cout<<count<<" "<<ans<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}