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

void solve(){
    ll x1,x2, y1, y2; cin>>x1>>y1>>x2>>y2;
    x1--; x2--; y1--; y2--;
    // vector<vector<int>> matrix(x2+y2+1, vector<int>(x2+y2+1, 0));
    // ll count = 2;
    // matrix[0][0] = 1;
    // for(ll i=1; i<x2+y2+1; i++){
    //     int x = 0, y=i;
    //     while(y >= 0){
    //         matrix[x][y] = count++;
    //         x++; y--;
    //     }
    // }
    // for(int i=0; i<x2+y2-1; i++){
    //     for(int j=0; j<x2+y2-1; j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vll sumarr(2001);
    sumarr[0] = 1;
    ll sum=0;

    for(ll i=1; i<2001; i++){
        sum += i;
        sumarr[i] = sum+1;
    }

    int a = x1,b = y1;
    int x = x2, y = y2;

    ll ans=sumarr[x+y]+x;

    while(a != x || b != y){
        ans += sumarr[a+b]+a;
        if(a != x){
            a++;
        }
        else{
            b++;
        }
    }
    cout<<ans<<endl;
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