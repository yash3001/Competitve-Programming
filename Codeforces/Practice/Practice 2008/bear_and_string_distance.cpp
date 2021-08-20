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
    unordered_map<char, int> mp;

    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    mp['d'] = 4;
    mp['e'] = 5;
    mp['f'] = 6;
    mp['g'] = 7;
    mp['h'] = 8;
    mp['i'] = 9;
    mp['j'] = 10;
    mp['k'] = 11;
    mp['l'] = 12;
    mp['m'] = 13;
    mp['n'] = 14;
    mp['o'] = 15;
    mp['p'] = 16;
    mp['q'] = 17;
    mp['r'] = 18;
    mp['s'] = 19;
    mp['t'] = 20;
    mp['u'] = 21;
    mp['v'] = 22;
    mp['w'] = 23;
    mp['x'] = 24;
    mp['y'] = 25;
    mp['z'] = 26;

    unordered_map<int, char> rev_map;

    rev_map[1] = 'a';
    rev_map[2] = 'b';
    rev_map[3] = 'c';
    rev_map[4] = 'd';
    rev_map[5] = 'e';
    rev_map[6] = 'f';
    rev_map[7] = 'g';
    rev_map[8] = 'h';
    rev_map[9] = 'i';
    rev_map[10] = 'j';
    rev_map[11] = 'k';
    rev_map[12] = 'l';
    rev_map[13] = 'm';
    rev_map[14] = 'n';
    rev_map[15] = 'o';
    rev_map[16] = 'p';
    rev_map[17] = 'q';
    rev_map[18] = 'r';
    rev_map[19] = 's';
    rev_map[20] = 't';
    rev_map[21] = 'u';
    rev_map[22] = 'v';
    rev_map[23] = 'w';
    rev_map[24] = 'x';
    rev_map[25] = 'y';
    rev_map[26] = 'z';
    
    ll n, k; scanf("%lld %lld", &n, &k);
    string s; scanf("%s", &s);
    
    string ans;
    for(const auto &c: s){
        if(k == 0){
            ans.pb(c);
        }
        else if(k > 26-mp[c] && k > mp[c] - 1){
            if(mp[c]-1 > 26-mp[c]){
                ans.pb('a');
                k -= mp[c]-1;
            }
            else{
                ans.pb('z');
                k -= 26-mp[c];
            }
        }
        else{
            if(k > 26-mp[c]){
                ans.pb(rev_map[mp[c]-k]);
            }
            else{
                ans.pb(rev_map[k-mp[c]]);
            }
            k = 0;
        }
    }
    cout<<ans;;
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