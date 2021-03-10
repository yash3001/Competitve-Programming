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

void solve(){
    ll n; cin>>n;
    vll h;
    forf(ll, i, n){
        ll t; cin>>t;
        h.pb(t);
    }
    ll ans{};
    for(ll i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            ll h1 = h.at(i), h2 = h.at(j);
            ll minh = min(h1, h2);
            ll flag{1};
            for(ll k=i+1; k<j; k++){
                if(h.at(k)>=minh){
                    if(h.at(k)==minh){
                        if(minh == h1 && minh == h2){
                            flag = 0;
                            break;
                        }
                    }
                    else{
                        if(!(h.at(k)-minh == max(h1, h2)-h.at(k) && h.at(k)-minh == j-k && j-k == k-i))
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            if(flag){
                ans = max(ans, j-i);
            }
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