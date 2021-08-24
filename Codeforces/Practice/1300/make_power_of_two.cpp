/* @author -> gamma30 */
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

void solve(){
    vector<string> power = {"1", "2", "4", "8", "16", "32", "64", "128", "256", "512", "1024", "2048", "4096", "8192", "16384", "32768", "65536", "131072", "262144", "524288", "1048576", "2097152", "4194304", "8388608", "16777216", "33554432", "67108864", "134217728", "268435456", "536870912", "1073741824", "2147483648", "4294967296", "8589934592", "17179869184", "34359738368", "68719476736", "137438953472", "274877906944", "549755813888", "1099511627776", "2199023255552", "4398046511104", "8796093022208", "17592186044416", "35184372088832", "70368744177664", "140737488355328", "281474976710656", "562949953421312", "1125899906842624", "2251799813685248", "4503599627370496", "9007199254740992", "18014398509481984", "36028797018963968", "72057594037927936", "144115188075855872", "288230376151711744", "576460752303423488", "1152921504606846976", "2305843009213693952", "4611686018427387904", "9223372036854775808", "18446744073709551616"};
    string s; cin>>s;
    int ans = INT_MAX;

    for(int k=0; k<power.size(); k++){
        string test = power[k];
        int count = 0;
        int i=0, j=0;
        while(i<s.size() && j<test.size()){
            if(s[i] == test[j]){
                i++; j++;
            }
            else{
                i++;
                count++;
            }
        }
        if(i == s.size()){
            count += test.size()-j;
        }
        if(j == test.size()){
            count += s.size()-i;
        }
        ans = min(ans, count);
    }

    cout<<ans<<endl;
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

    ll t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}