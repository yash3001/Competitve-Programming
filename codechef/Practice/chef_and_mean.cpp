/* @author -> gamma30 */
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forf(t,i,n) for(t i=0;i<n;i++)
#define forr(t,i,n) for(t i=n-1;i>=0;i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

void solve(){
    ll n, sum{}; cin>>n;
    vll nums;
    forf(ll, i, n){
        ll t; cin>>t;
        nums.pb(t);
        sum+=t;
    }
    ld mean= (double)sum/n;
    ld value = mean*(double)(n-1);
    value = (double)sum - value;
    auto check = find(nums.begin(), nums.end(), value);
    if(check != nums.end()){
        cout<<check-nums.begin()+1<<endl;
        return;
    }
    cout<<"Impossible"<<endl;
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