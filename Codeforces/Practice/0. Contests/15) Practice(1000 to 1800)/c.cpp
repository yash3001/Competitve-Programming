/* @author -> gamma30 */

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define endl "\n"
#define EPS 1e-9
#define MOD 1e9+7
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define forf(t,i,n) for(t i=0;i<n;i++)
// #define forr(t,i,n) for(t i=n-1;i>=0;i--)
#define forf(i,a,b) for(ll i=a;i<b;i++)
#define forr(i,a,b) for(ll i=a;i>=b;i--)
#define ceach(a,x) for(const auto &a: x)
#define each(a,x) for(auto &a: x)
#define print(x) for(const auto &e: (x)) { cout<<e<<" "; } cout<<endl

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef unordered_map<int, int> umi;
typedef unordered_map<long long, long long> umll;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, long long> umcll;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, long long> umsll;

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

template<typename T>
T modpow(T a, T b, T m){
    if(b == 0){
        return 1;
    }
    T c = modpow(a, b/2, m);
    c = (c * c)%m;
    if(b%2 == 1){
        c = (c * a)%m;
    }
    return c;
}

/* ----------STRING AND INTEGER CONVERSIONS---------- */
// 1) number to string -> to_string(num)
// 2) string to number -> stoi(str)

ll lcs(string s1, string s2){
    ll m = s1.size();
    ll n = s2.size();

    vvll dp(m+1, vll(n+1, 0));

    for(ll i=0; i<m+1; i++){
        dp[i][0] = 0;
    }
    for(ll i=1; i<n+1; i++){
        dp[0][i] = 0;
    }

    for(ll i=1; i<m+1; i++){
        for(ll j=1; j<n+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[m][n];
}

void solve(){
    string s, t, p; cin>>s>>t>>p;
    ll le = lcs(t, s);
    if(le != s.size()){
        cout<<"NO"<<endl;
        return;
    }
    umcll a, b, c;
    each(x, p){
        c[x]++;
    }
    each(x, t){
        b[x]++;
    }
    each(x, s){
        a[x]++;
    }
    each(x, t){
        if(!a[x]){
            if(!c[x]){
                cout<<"NO"<<endl;
                return;
            }
            else{
                c[x]--;
            }
        }
        else{
            a[x]--;
        }
    }
    cout<<"YES"<<endl;
}

int main(){

    // cfh - ctrl+alt+b
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}