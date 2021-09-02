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

ll dfs(ll n, vvll adj, vll &visited, ll &chosen, vll value){
    visited[n] = 1;
    ll ans = value[n];
    ll m = 0;
    for(const auto &c: adj[n]){
        if(!visited[c]){
            ll t = dfs(c, adj, visited, chosen, value);
            if(t > m){
                m = t;
                if(n == 1){
                    chosen = c;
                }
            }
        }
    }

    return ans+m;
}

ll dfs2(ll n, vvll adj, vll &visited, ll &chosen, vll value){
    visited[n] = 1;
    ll ans = value[n];
    ll m = 0;
    for(const auto &c: adj[n]){
        if(!visited[c] && c != chosen){
            ll t = dfs(c, adj, visited, chosen, value);
            if(t > m){
                m = t;
            }
        }
    }

    return ans+m;
}

void solve(){
    ll n; cin>>n;

    vll value(n+1);
    for(ll i=1; i<=n; i++){
        cin>>value[i];
    }

    vvll adj(n+1);

    forf(ll, i, n-1){
        ll a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vll visited(n+1, 0);

    ll chosen = -1;
    if(adj[1].size() == 0){
        cout<<value[1]<<endl;
    }
    else if(adj[1].size() == 1){
        cout<<dfs(1, adj, visited, chosen, value)<<endl;
    }
    else{
        ll t = dfs(1, adj, visited, chosen, value);
        vll visited2(n+1, 0);
        ll m = dfs2(1, adj, visited2, chosen, value);
        cout<<(t+m-value[1])<<endl;
    }
}

int main(){

    // cfh - ctrl+alt+b
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i = 1;
    ll t; cin >> t;
    while(t--){
        cout<<"Case #"<<i++<<": ";
        solve();
    }
    
    return 0;
}