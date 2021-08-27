/* @author -> gamma30 */
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define endl "\n"
#define EPS 1e-9
#define MOD 1e9+7
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forf(t,i,n) for(t i=0;i<n;i++)
#define forr(t,i,n) for(t i=n-1;i>=0;i--)
#define print(x) for(const auto &e: (x)) { cout<<e<<" "; } cout<<endl

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
typedef unordered_map<long long, long long> umll;

template<typename T>
T gcd(T a, T b){
    if(b == 0)
        return a;
    return(gcd<T>(b, a%b));
}

template<typename T>
T lcm(T a, T b){
    return (a / gcd<T>(a, b)) * b;
}

template<typename T>
void swap_(T &a, T &b){
    a = a^b;
    b = b^a;
    a = a^b;
}

template<typename T>
T modpow(T a, T b, T m){
    if(b == 0){
        return 1;
    }
    T c = modpow(a, b/2, m);
    c = (c * c)%m;
    if(b%2 == 1){
        c = (c * a)%m;
    }
    return c;
}

bool comp(pair<ll, pair<ll, ll>> p1, pair<ll, pair<ll, ll>> p2){
    return p1.first < p2.first;
}

void solve(){
    ll n, m; cin>>n>>m;

    vector<vector<pair<ll, ll>>> adj(n+1);
    vector<ll> dist(n+1, LLONG_MAX);

    while(m--){
        ll a, b, w; cin>>a>>b>>w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    priority_queue< pair<ll,pair<ll, ll>>, vector<pair<ll,pair<ll, ll>> >, greater<pair<ll, pair<ll, ll>>> > pq;

    pq.push({0, {1, 1}});
    dist.at(1) = 0;

    while(!pq.empty()){
        ll node = pq.top().second.first;
        ll node_d = pq.top().first;
        ll fac = pq.top().second.second;

        pq.pop();

        for(const auto &p: adj[node]){
            if(node_d + (fac)*p.second < dist[p.first]){
                dist[p.first] = node_d + (fac)*p.second;
                pq.push({dist[p.first], {p.first, fac+1}});
            }
        }
    }

    for(ll i=1; i<=n; i++){
        cout<<(dist[i] == LONG_LONG_MAX ? -1 : dist[i])<<endl;
    }
}

int main(){

    // cfh - ctrl+alt+b
    #ifndef ONLINE_JUDGE
        freopen("consistency_chapter_1_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t{1};
    while(t--){
        solve();
    }
    
    return 0;
}