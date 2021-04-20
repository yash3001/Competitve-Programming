/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <limits>

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

template<typename T>
T gcd(T a, T b){
    if(b == 0)
        return a;
    return(gcd<T>(b, a%b));
}

template<typename T>
T lcm(T a, T b){
    return (a / gcd<T>(a, b)) * b;
}

template<typename T>
void swap_(T &a, T &b){
    a = a^b;
    b = b^a;
    a = a^b;
}

ll minimize(vll &val, ll n, ll in, ll vl){
    if(vl == -1 && in != 0){
        val.at(in-1) = -1;
    }
    if(n==0){
        ll num{0};
        for(ll i=val.size()-1; i>=0; i--){
            if(num != -1)
            num = num*10 + val.at(i);
        }
        return num;
    }
    if(in == 0){
        return 0;
    }
    return max(minimize(val,n-1,in-1,-1), minimize(val, n, in-1, 0));
}

void solve(){
    ll num; cin>>num;
    ll n; cin>>n;
    vll val;
    while(num>0){
        val.pb(num%10);
        num /= 10;
    }
    cout<<minimize(val, n, val.size(), 0);
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