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
    ll n,m; cin>>n>>m;
    map<string, string> chef_country;
    map<string, ll> country, chef;
    forf(ll,i,n){
        string cheff, countryy; cin >> cheff >> countryy;
        chef_country[cheff] = countryy;
        chef[cheff] = 0;
        country[countryy] = 0;
    }
    forf(ll,i,m){
        string cheff; cin>>cheff;
        chef[cheff]++;
        country[chef_country[cheff]]++;
    }
    string winner {"gamma30"};
    ll count{};
    for(const auto &cheff: country){
        if(cheff.y>count){
            count=cheff.y;
            winner=cheff.x;
        }
        if(cheff.y==count && cheff.x<winner){
            winner=cheff.x;
        }
    }
    cout<<winner<<endl;
    winner="gamma30";
    count=0;
    for(const auto &cheff: chef){
        if(cheff.y>count){
            count=cheff.y;
            winner=cheff.x;
        }
        if(cheff.y==count && cheff.x<winner){
            winner=cheff.x;
        }
    }
    cout<<winner<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    solve();
    return 0;
}