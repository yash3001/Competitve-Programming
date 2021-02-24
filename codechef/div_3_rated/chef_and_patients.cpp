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
    ll n; cin>>n;
    vector<pair<ll, ll>> patients(n);
    vll real(n);
    forf(ll, i, n){
        cin>>patients.at(i).ss;
        patients.at(i).ff = i+1;
        real.at(i) = patients.at(i).ss;
    }
    sort(all(patients), 
        [](const pair<ll, ll> &a, const pair<ll, ll> &b) -> bool
            {
                return (a.ss==b.ss ? a.ff < b.ff : a.ss > b.ss);  
            }
        );
    unordered_map<ll, vector<ll>> mp;
    for(ll i=0; i<n; i++){
        if(!mp.count(patients.at(i).ss)){
            mp[patients.at(i).ss] = vector<ll>();
            mp[patients.at(i).ss].pb(i+1);
        }
        else{
            mp[patients.at(i).ss].pb(i+1);
        }
    }
    for(const auto &p: real){
        ll i=0;
        while(mp[p].at(i)==-1){
            i++;
        }
        cout<<mp[p].at(i)<<" ";
        mp[p].at(i)=-1;
    }
    cout<<endl;
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