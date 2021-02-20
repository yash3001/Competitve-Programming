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
    ll n; cin>>n;
    ll max_lead{}, max_lead_player{};
    ll f1, s1, f2, s2;
    cin>>f1>>s1;
    ll s=f1, t=s1;
    if(abs(s-t)>max_lead){
        max_lead = abs(s-t);
        max_lead_player = s>t?1:2;
    }
    n--;
    while(n--){
        cin>>f2>>s2;
        s=f1+f2; t=s1+s2;
        f1=s; s1=t;
        if(abs(s-t)>max_lead){
            max_lead = abs(s-t);
            max_lead_player = s>t?1:2;
        }
    }
    cout<<max_lead_player<<" "<<max_lead;
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