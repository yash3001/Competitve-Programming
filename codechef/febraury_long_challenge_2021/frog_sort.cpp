/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <unordered_map>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define endl "\n"
#define EPS 1e-9
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

void solve(){
    ll n; cin>>n;
    vll frogs;
    unordered_map<ll, ll> mp_pos, mp_len;
    forf(ll, i, n){
        ll t; cin>>t;
        frogs.pb(t);
        mp_pos[frogs.at(i)] = i;
    }
    forf(ll, i, n){
        ll t; cin>>t;
        mp_len[frogs.at(i)] = t;
    }
    ll ans{};
    for(ll i=2; i<=n; i++){
        while(mp_pos[i]<=mp_pos[i-1]){
            mp_pos[i] += mp_len[i];
            ans++;
        }
    }
    cout<<ans<<endl;
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