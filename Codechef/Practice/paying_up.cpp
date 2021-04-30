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

bool helper(ll *coins, ll n, ll m){
    if(m==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(coins[n-1]>m){
        return helper(coins, n-1, m);
    }
    return helper(coins, n-1, m) || helper(coins, n-1, m-coins[n-1]);
}

void solve(){
    ll n, m; cin>>n>>m;
    ll coins[n];
    forf(ll, i, n){
        cin>>coins[i];
    }
    sort(coins, coins+n);
    cout<<(helper(coins, n, m)?"Yes":"No")<<endl;
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