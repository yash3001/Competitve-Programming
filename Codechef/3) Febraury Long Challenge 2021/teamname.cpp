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

void solve(){
    ll n; cin>>n;
    unordered_map<string, vector<char>> mp;
    vector<string> vec;
    ll ans{};
    forf(ll, i, n){
        string s; cin>>s;
        if(!mp.count(s.substr(1, s.size()-1))){
            mp[s.substr(1, s.size()-1)] = vector<char>();
            vec.pb(s.substr(1, s.size()-1));
        }
        mp[s.substr(1, s.size()-1)].pb(s[0]);
    }
    for(ll i=0; i<vec.size()-1; i++){
        for(ll j=i; j<vec.size(); j++){
            unordered_map<char, int> s;
            for(const auto &c: mp[vec[i]]){
                s[c]++;
            }
            for(const auto &c: mp[vec[j]]){
                s[c]++;
            }
            ans += (s.size()-mp[vec[i]].size())*(s.size()-mp[vec[j]].size());
        }
    }
    cout<<2*ans<<endl;
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