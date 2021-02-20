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

void solve(){
    string p, v; cin>>p>>v;
    if(v.size()>=p.size()){
        if(v!=p){
            cout<<"No Match!"<<endl;
            return;
        }
    }
    bool match{};
    for(ll i=0; i<p.size()-v.size(); i++){
        ll count{};
        if(p.substr(i, v.size())==v){
            if(!match)
                match = 1;
            cout<<i<<" ";
        }
        else{
            for(ll j=i, k=0; j<i+v.size(); j++, k++){
                if(count==2){
                    break;
                }
                if(p.at(j)!=v.at(k)){
                    count++;
                }
            }
            if(count==1){
                if(!match)
                    match = 1;
                cout<<i<<" ";
            }
        }
    }
    if(!match)
        cout<<"No Match!";
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