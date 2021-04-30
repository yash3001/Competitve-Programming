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
    unordered_map<string, int> mp;
    vector<string> names;
    bool flag{1};
    string t1; cin>>t1;
    mp[t1]++;
    names.pb(t1);
    forf(ll, i, n-1){
        string t2; cin>>t2;
        mp[t2]++;
        names.pb(t2);
        if(t2[0]!=t1[0] || t2.substr(1, t2.size()-1)!=t1.substr(1, t1.size()-1))
            flag = 0;
    }
    if(!flag){
        ll ans{};
        for(ll i=0; i<n-1; i++){
            for(ll j=i+1; j<n; j++){
                string a, b;
                a=names[i].substr(0,1)+names[j].substr(1,names[j].size()-1);
                b=names[j].substr(0,1)+names[i].substr(1,names[i].size()-1);
                if(!mp[a]&&!mp[b]){
                    ans++;
                }
            }
        }
        cout<<ans*2<<endl;
    }
    else{
        cout<<0<<endl;
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

    ll t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}