/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <climits>

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
#define print(x) for(const auto &e: (x)) { cout<<e<<" "; } cout<<endl

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
typedef unordered_map<long long, long long> umll;

ll helper(ll n, ll e, ll h, ll a, ll b, ll c){
    ll ans = 1e15;

    if(n<=0){
        return 0;
    }

    if(2*n <= e){
        ans = min(ans, n*a);
    }

    if(3*n <= h){
        ans = min(ans, n*b);
    }

    if(n<=e && n<=h){
        ans = min(ans, n*c);
    }

    if(e/2 >= 1 && (e/2 >= (3*n - h + 2)/3)){
        if(a>=b){
            ans = min(ans, n*b + (max(n/n, (3*n-h + 2)/3)*(a-b)));
        }
        else{
            ans = min(ans, n*b + min(n-1, e/2)*(a-b));
        }
    }

    if((e-n) >= 1 && e-n>=n-h){
        if(a>=c){
            ans = min(ans, n*c + max(n/n, n-h)*(a-c));
        }
        else{
            ans = min(ans, n*c + min(n-1, e-n)*(a-c));
        }
    }

    if((h-n)/2 >= 1 && (h-n)/2 >= n-e){
        if(b>=c){
            ans = min(ans, c*n + max(n/n, n-e)*(b-c));
        }
        else{
            ans = min(ans, c*n + min(n-1, (h-n)/2)*(b-c));
        }
    }
    if((e >= 3) && (h >= 4) && (n >= 3)){
        ans = min(ans, a + b + c + helper(n-3, e-3, h-4, a, b ,c));
    }

    return ans;
}

void solve(){
    ll n, e, h, a, b, c; cin>>n>>e>>h>>a>>b>>c;
    ll ans = helper(n, e, h, a, b ,c);
    if(ans != 1e15){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
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