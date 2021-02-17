/* @author -> gamma30 */
#include <bits/stdc++.h>

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
typedef vector<string> vs;

void solve(){
    ll n1, n2, n3; cin>>n1>>n2>>n3;
    unordered_map<ll, ll> mp;
    vll nums;
    ll size{};
    forf(ll, i, n1+n2+n3){
        ll t; cin>>t;
        if(!mp[t]){
            nums.pb(t);
        }
        mp[t]++;
        if(mp[t]==2){
            size++;
        }
    }
    sort(all(nums));
    cout<<size<<endl;
    for(const auto &n: nums){
        if(mp[n]>1){
            cout<<n<<endl;
        }
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

    ll t{1};
    while(t--){
        solve();
    }
    
    return 0;
}