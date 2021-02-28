/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <utility>

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
    vector<pair<int, int>> R;
    ll max_s{}, max_r{}, max_i{};
    forf(int, i, n){
        ll s, r; cin>>s>>r;
        if(s > max_s){
            max_s = s;
            max_r = r;
            max_i = i+1;
        }
        if(s == max_s && r>max_r){
            max_r = r;
            max_i = i+1;
        }
        R.push_back(make_pair<int, int>(i+1, r));
    }
    sort(all(R), [](pair<int, int> a, pair<int, int> b){return a.y>b.y;});
    set<int> ans;
    for(auto &p: R){
        if(p.y > max_r){
            ans.insert(p.x);
        }
        else{
            break;
        }
    }
    for(auto &a: ans){
        cout<<a<<" ";
    }
    cout<<max_i<<endl;
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