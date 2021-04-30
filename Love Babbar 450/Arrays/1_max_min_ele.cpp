/* @author -> gamma30 */
#include <algorithm>
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
T nCr(T n, T r){
    T dp[n+1][r+1];
    for(T i=0; i<n+1; i++){
        for(T j=0; j<r+1; j++){
            if(j==0 || j==i){
                dp[i][j] = 1;
            }
            if(j==1){
                dp[i][j] = i;
            }
            if(j>i){
                dp[i][j] = 0;
            }
        }
    }
    for(T i=1; i<n+1; i++){
        for(T j=1; j<r+1; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    return dp[n][r];
}

template<typename T>
T nPr(T n, T r){
    T dp[n+1][r+1];
    for(T i=0; i<n+1; i++){
        for(T j=0; j<r+1; j++){
            if(j==0){
                dp[i][j] = 1;
            }
            if(j==1){
                dp[i][j] = i;
            }
            if(j>i){
                dp[i][j] = 0;
            }
        }
    }
    for(T i=1; i<n+1; i++){
        for(T j=1; j<r+1; j++){
            dp[i][j] = dp[i-1][j] + j*dp[i-1][j-1];
        }
    }
    return dp[n][r];
}

void solve(){
    ll n; cin>>n;
    vll arr(n);
    forf(ll, i, n){
        cin>>arr.at(i);
    }
    ll min_ele{LONG_LONG_MAX}, max_ele{LONG_LONG_MIN};
    for(const auto &n: arr){
        max_ele = max(max_ele, n);
        min_ele = min(min_ele, n);
    }
    cout<<min_ele<<" "<<max_ele<<endl;
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