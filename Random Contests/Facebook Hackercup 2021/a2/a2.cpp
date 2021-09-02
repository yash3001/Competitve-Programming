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

void solve(){
    string s; cin>>s;
    vll uniq; umll dups;
    
    for(const auto &c: s){
        if(dups[c-'A']++ == 0){
            uniq.pb(c-'A');
        }
    }

    ll k; cin>>k;
    vvll adj(26);
    if(k == 0 && uniq.size() > 1){
        cout<<-1<<endl;
        return;
    }
    while(k--){
        char a, b; cin>>a>>b;
        adj[a-'A'].pb(b-'A');
    }

    if(uniq.size() == 1){
        cout<<0<<endl;
        return;
    }

    umll cnt, dist;
    vll shortListed;
    for(const auto &u: uniq){
        vll visited(26, 0);
        cnt[u]++;
        dist[u]+=0;
        if(cnt[u] == uniq.size()){
            shortListed.pb(u);
        }

        queue<pair<ll, ll>> q;
        q.push({u, 0});
        visited[u] = 1;
        while(!q.empty()){
            ll node = q.front().first;
            ll node_d = q.front().second;
            q.pop();
            for(const auto &c: adj[node]){
                if(!visited[c]){
                    q.push({c, node_d+1});
                    cnt[c]++;
                    visited[c] = 1;
                    if(cnt[c] == uniq.size()){
                        shortListed.pb(c);
                    }
                    dist[c] += (node_d+1)*(dups[u]);
                }
            }
        }
    }

    ll ans = LONG_LONG_MAX;

    if(shortListed.size() == 0){
        cout<<-1<<endl;
        return;
    }

    for(const auto &sl: shortListed){
        // cout<<sl<<" "<<dist[sl]<<endl;
        ans = min(ans, dist[sl]);
    }

    cout<<ans<<endl;
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

    ll t; cin >> t;
    ll i=1;
    while(t--){
        cout<<"Case #"<<(i++)<<": ";
        solve();
    }
    
    return 0;
}