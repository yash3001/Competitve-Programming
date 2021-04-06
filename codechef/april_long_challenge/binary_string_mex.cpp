/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <math.h>

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

string getBinaryRep(int num){
    string t;
    stack<char> st;
    if(num==0){
        t.pb('0');
        return t;
    }
    while(num>0){
        char ch = ((num&1) == 1)?'1':'0';
        t = ch+t;
        num>>=1;
    }
    return t;
}

void solve(){
    string s; cin>>s;
    string ans;
    for(ll i=0; i<pow(2, s.size()); i++){
        string num = getBinaryRep(i);
        ll m=0;
        for(int j=0; j<s.size(); j++){
            if(num.at(m)==s.at(j)){
                m++;
            }
            if(m>=num.size()){
                break;
            }
        }
        if(m<num.size()){
            ans = num;
            break;
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