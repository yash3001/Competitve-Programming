/* @author -> gamma30 */
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define endl "\n"
#define EPS 1e-9
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

bool comp(pair<ll, ll> p1, pair<ll, ll> p2){
    return p1.second > p2.second;
}

void solve(){
    ll n, k; cin>>n>>k;
    umll mp, pos_index; ll count = 0; vll uniq; unordered_map<ll, vll> pos;
    
    for(ll i=0; i<n; i++){
        ll t; cin>>t;
        mp[t]++;
        if(mp[t] == 1){
            uniq.pb(t);
            pos[t] = vll();
        }
        if(mp[t] > k){
            continue;
        }
        pos[t].pb(i);
        count++;
    }

    count = count/k;    
    vll colors(k+1, count);

    vector<pair<ll, ll>> sorted_data;
    for(const auto &n: uniq){
        sorted_data.pb({n, mp[n]});
    }

    sort(all(sorted_data), comp);

    vll ans(n, -1);

    for(const auto &p: sorted_data){
        ll n = p.first;
        ll count = p.second;
        ll j=1;
        for(ll i=1; i<=count; i++){
            while(colors[j] == 0 && j<k+1){
                j++;
            }
            if(j == k+1){
                break;
            }
            ans[pos[n][pos_index[n]++]] = j;
            colors[j]--;
            j++;
        }
    }

    for(auto &n: ans){
        if(n == -1){
            n = 0;
        }
        cout<<n<<" ";
    }
    cout<<endl;
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