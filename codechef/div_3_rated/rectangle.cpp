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
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;

void solve(){
    ll n, m; cin>>n>>m;
    vll ones;
    unordered_map<ll, ll> mp;
    forf(ll, i, n){
        forf(ll, j, m){
            char c; cin>>c;
            if(c=='1'){
                ones.pb(j);
                mp[j]++;
            }
        }
    }
    print(ones);
    ll min = *min_element(all(ones)), max = *max_element(all(ones));
    ll count = mp[min];
    bool is_rect {1};
    for(int i=min+1; i<=max; i++){
        if(mp[i]!=count){
            is_rect = 0;
            break;
        }
    }
    if(is_rect){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

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