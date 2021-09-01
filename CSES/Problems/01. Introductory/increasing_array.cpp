/* @author -> gamma30 */
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
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
    ll n, f, s, ans{}; cin>>n;
    cin>>f;
    forf(int, i, n-1){
        cin>>s;
        if(s<f){
            ans+=f-s;
        }
        else{
            f=s;
        }
    }
    cout<<ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t{1}; 
    while(t--){
        solve();
    }
    
    return 0;
}
