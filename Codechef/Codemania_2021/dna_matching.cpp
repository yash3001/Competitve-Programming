/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <valarray>

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
    string s; cin>>s;
    ll t; cin>>t;
    string cor{}; ll cor_c{};
    while(t--){
        ll cur_c{};
        string p; cin>>p;
        for(ll i=0; i<s.size()-p.size(); i++){
            if(s.substr(i, p.size())==p){
                cur_c++;
            }
        }
        if(cur_c>cor_c){
            cor_c=cur_c;
            cor=p;
        }
        if(cur_c==cor_c){
            if(p<cor)
                cor=p;
        }
    }
    cout<<cor;
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