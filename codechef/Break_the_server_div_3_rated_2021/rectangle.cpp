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
    vll ones, ones_y;
    unordered_map<ll, ll> mp, mp_y;
    ll max_x{-1}, max_y{-1}, min_x{n+1}, min_y{n+1}; 
    forf(ll, i, n){
        forf(ll, j, m){
            char c; cin>>c;
            if(c=='1'){
                if(j>max_x)
                    max_x = j;
                if(j<min_x)
                    min_x = j;
                if(i>max_y)
                    max_y = i;
                if(i<min_y)
                    min_y = i;

                ones.pb(j);
                ones_y.pb(i);
                mp[j]++;
                mp_y[i]++;
            }
        }
    }
    ll count_x = mp[min_x];
    ll count_y = mp_y[min_y];
    bool is_rect {1};
    for(int i=min_x+1; i<=max_x; i++){
        if(mp[i]!=count_x){
            is_rect = 0;
            break;
        }
    }
    if(is_rect){
        for(int i=min_y+1; i<=max_y; i++){
            if(mp_y[i]!=count_y){
                is_rect = 0;
                break;
            }
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