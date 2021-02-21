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

ll helper(ll i, ll &count, vll &h, vll &iq, ll &n){
    if(i==n){
        return count;
    }
    else{
        if(h.at(i)>h.at(i-1)&&iq.at(i)<iq.at(i-1)){
            helper(i+1, ++count, h, iq, n);
        }
    }
}

void solve(){
    ll n; cin>>n;
    vll heights(n, 0);
    vll iqs(n, 0);
    forf(ll, i, n){
        cin>>heights.at(i);
    }
    forf(ll, i, n){
        cin>>iqs.at(i);
    }
    ll ans{};
    for(ll i=1; i<n-1; i++)
    {
        ll count{};
        ll t = helper(i+1, count, heights, iqs, n))
        if(t)
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