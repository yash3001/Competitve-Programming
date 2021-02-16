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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

void solve(){
    ll n; cin>>n;
    char ch; string s;
    ll total_0{}, total_1{};
    forf(ll, i, n){
        cin>>ch;
        if(ch=='0')
            total_0++;
        else
            total_1++;
        s += ch;
    }
    ll ans = min(total_0, total_1);
    if(ans == 0){
        cout<<ans<<endl;
        return;
    }
    ll current_0{}, current_1{};
    for(auto &c: s){
        if(c == '0')
            current_0++;
        else
            current_1++;
        ans = min(current_1 + total_0 - current_0, ans);
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