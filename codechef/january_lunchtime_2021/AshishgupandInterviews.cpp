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
    ll n, k; cin>>n>>k;
    bool too_slow{}, bot{1};
    ll solved{};
    forf(ll, i, n){
        ll t; cin>>t;
        if(t > k){
            too_slow = true;
        }
        if(t > 1 || t == -1){
            bot = false;
        }
        if(t!=-1){
            solved++;
        }
    }
    if(solved < ceil(n/2.0)){
        cout<<"Rejected"<<endl;
        return;
    }
    if(too_slow){
        cout<<"Too Slow"<<endl;
        return;
    }
    if(bot){
        cout<<"Bot"<<endl;
        return;
    }
    cout<<"Accepted"<<endl;
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