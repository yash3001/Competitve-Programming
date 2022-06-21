// @author ↓

//  ██ ██     ██                     ██                    ██      ██████   ██████████ ██       ██
// ░██░██    ░██                    ████                  ░██     ░█░░░░██ ░░░░░██░░░ ░██      ░██
// ░██░██    ░██  ██████  █████    ██░░██   ██████  █████ ░██     ░█   ░██     ░██    ░██   █  ░██
// ░██░██    ░██ ██░░░░  ██░░░██  ██  ░░██ ░░██░░█ ██░░░██░██████ ░██████      ░██    ░██  ███ ░██
// ░██░██    ░██░░█████ ░███████ ██████████ ░██ ░ ░██  ░░ ░██░░░██░█░░░░ ██    ░██    ░██ ██░██░██
// ░██░██    ░██ ░░░░░██░██░░░░ ░██░░░░░░██ ░██   ░██   ██░██  ░██░█    ░██    ░██    ░████ ░░████
// ░██░░███████  ██████ ░░██████░██     ░██░███   ░░█████ ░██  ░██░███████     ░██    ░██░   ░░░██
// ░░  ░░░░░░░  ░░░░░░   ░░░░░░ ░░      ░░ ░░░     ░░░░░  ░░   ░░ ░░░░░░░      ░░     ░░       ░░ 

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define endl "\n"
#define EPS 1e-9
#define MOD 1000000007
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (x).size()
// #define forf(t,i,n) for(t i=0;i<n;i++)
// #define forr(t,i,n) for(t i=n-1;i>=0;i--)
#define forf(i,a,b) for(ll i=a;i<b;i++)
#define forr(i,a,b) for(ll i=a;i>=b;i--)
#define F0(i, n) for(ll i=0; i<n; i++)
#define F1(i, n) for(ll i=1; i<=n; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define ceach(a,x) for(const auto &a: x)
#define each(a,x) for(auto &a: x)
#define print(x) for(const auto &e: (x)) { cout<<e<<" "; } cout<<endl
#define daalo(a) each(x, a) { cin>>x; }

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
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

#ifndef ONLINE_JUDGE
    #define deb(x ...) cerr << #x << ": "; _print(x); cerr << endl;
    #define pt(x) cerr << "\n---------Testcase " << x << "---------\n" << endl;
    // #define deb(x ...) ;
    // #define pt(x) ;
#else
    #define deb(x ...) ;
    #define pt(x) ;
#endif

void _print(unsigned short t){ cerr << t; }
void _print(short t){ cerr << t; }
void _print(unsigned int t){ cerr << t; }
void _print(int t){ cerr << t; }
void _print(unsigned long t){ cerr << t; }
void _print(long t){ cerr << t; }
void _print(unsigned long long t){ cerr << t; }
void _print(long long t){ cerr << t; }
void _print(float t){ cerr << t; }
void _print(double t){ cerr << t; }
void _print(long double t){ cerr << t; }
void _print(unsigned char t){ cerr << t; }
void _print(char t){ cerr << t; }
void _print(string t){ cerr << t; }

template<typename A> void _print(vector<A> v);
template<typename A, typename B> void _print(pair<A, B> p);
template<typename A> void _print(set<A> s);
template<typename A, typename B> void _print(map<A, B> mp);
template<typename A> void _print(multiset<A> s);
template<typename A, typename B> void _print(multimap<A, B> mp);
template<typename A> void _print(unordered_set<A> s);
template<typename A, typename B> void _print(unordered_map<A, B> mp);
template<typename A> void _print(unordered_multiset<A> s);
template<typename A, typename B> void _print(unordered_multimap<A, B> mp);
template<typename A> void _print(stack<A> s);
template<typename A> void _print(queue<A> q);
template<typename A> void _print(priority_queue<A> pq);
template<typename A> void _print(priority_queue<A, vector<A>, greater<A>> pq);

template<typename A> void _print(vector<A> v){ if(!v.empty()){ cerr << "["; for(auto it=v.begin(); it!=(v.end()-1); it++){ _print(*it); cerr <<","; } _print(*(v.end()-1)); cerr << "]"; } else{ cerr << "[]"; } }
template<typename A, typename B> void _print(pair<A, B> p){ cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<typename A> void _print(set<A> s){ if(!s.empty()){ cerr << "{"; for(auto it=s.begin(), lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<","; } _print(*(s.rbegin())); cerr << "}"; } else{ cerr << "{}"; } }
template<typename A, typename B> void _print(map<A, B> mp){ if(!mp.empty()){ cerr << "["; for(auto it=mp.begin(), lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<","; } _print(*(mp.rbegin())); cerr << "]"; } else{ cerr << "[]"; } }
template<typename A> void _print(multiset<A> s){ if(!s.empty()){ cerr << "{"; for(auto it=s.begin(), lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<","; } _print(*(s.rbegin())); cerr << "}"; } else{ cerr << "{}"; } }
template<typename A, typename B> void _print(multimap<A, B> mp){ if(!mp.empty()){ cerr << "["; for(auto it=mp.begin(), lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<","; } _print(*(mp.rbegin())); cerr << "]"; } else{ cerr << "[]"; } }
template<typename A> void _print(unordered_set<A> s){ if(!s.empty()){ cerr << "{"; auto it = s.begin(); for(auto lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<","; } _print(*it); cerr << "}"; } else{ cerr << "{}"; } }
template<typename A, typename B> void _print(unordered_map<A, B> mp){ if(!mp.empty()){ cerr << "["; auto it = mp.begin(); for(auto lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<","; } _print(*it); cerr << "]"; } else{ cerr << "[]"; } }
template<typename A> void _print(unordered_multiset<A> s){ if(!s.empty()){ cerr << "{"; auto it=s.begin(); for(auto lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<","; } _print(*it); cerr << "}"; } else{ cerr << "{}"; } }
template<typename A, typename B> void _print(unordered_multimap<A, B> mp){ if(!mp.empty()){ cerr << "["; auto it=mp.begin(); for(auto lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<","; } _print(*it); cerr << "]"; } else{ cerr << "[]"; } }
template<typename A> void _print(stack<A> s){ if(!s.empty()){ stack<A> t; cerr << "T["; while(s.size() != 1){ _print(s.top()); cerr << ","; t.push(s.top()); s.pop(); } _print(s.top()); cerr << "]B"; t.push(s.top()); s.pop(); while(!t.empty()){ s.push(t.top()); t.pop(); } } else{ cerr << "T[]B"; } }
template<typename A> void _print(queue<A> q){ if(!q.empty()){ queue<A> t; cerr << "F["; while(q.size() != 1){ _print(q.front()); cerr << ","; t.push(q.front()); q.pop(); } _print(q.front()); cerr << "]B"; t.push(q.front()); q.pop(); while(!t.empty()){ q.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
template<typename A> void _print(priority_queue<A> pq){ if(!pq.empty()){ queue<A> t; cerr << "T["; while(pq.size() != 1){ _print(pq.top()); cerr << ","; t.push(pq.top()); pq.pop(); } _print(pq.top()); cerr << "]B"; t.push(pq.top()); pq.pop(); while(!t.empty()){ pq.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
template<typename A> void _print(priority_queue<A, vector<A>, greater<A>> pq){ if(!pq.empty()){ queue<A> t; cerr << "T["; while(pq.size() != 1){ _print(pq.top()); cerr << ","; t.push(pq.top()); pq.pop(); } _print(pq.top()); cerr << "]B"; t.push(pq.top()); pq.pop(); while(!t.empty()){ pq.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
template<typename T, typename... V> void _print(T t, V... v) {_print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_set_dec = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset_dec = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = mod_mul(res , a, mod); a = mod_mul(a , a ,mod); b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

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

template<typename T>
vector<T> makeUnique(vector<T> &vec){
    vector<T> temp;
    unordered_map<T, long long> mp;
    for(const auto &e: vec){
        if(mp[e]++ == 0){
            temp.push_back(e);
        }
    }
    return temp;
}

vector<long long> primeFactorization(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

vector<long long> divisors(long long n) {
    vector<long long> divisors;
    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(n/i != i){
                divisors.push_back(n/i);
            }
        }
    }
    return divisors; 
}

vector<bool> seive(long long n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

/* ----------STRING AND INTEGER CONVERSIONS---------- */
// 1) number to string -> to_string(num)
// 2) string to int -> stoi(str)
// 3) string to long long -> stoll(str)
// 4) string to decimal -> stod(str)
// 5) string to long decimal -> stold(str)

/* ----------Decimal Precision---------- */
// cout<<fixed<<setprecision(n) -> to fix precision to n decimal places.
// cout<<setprecision(n) -> without fixing

/* ----------Policy Bases Data Structures---------- */
// pbds<ll> s; (almost same as set)
// s.find_by_order(i)    0<=i<n     returns iterator to ith element (0 if i>=n)
// s.order_of_key(e)     returns elements strictly less than the given element e (need not be present)

/* ------------------Binary Search------------------ */
// 1) Lower Bound -> returns iterator to the first element greater than or equal to the given element or returns end() if no such element exists
// 2) Upper Bound -> returns iterator to the first element greater than the given element or returns end() if no such element exists

/* --------------Builtin Bit Functions-------------- */
// 1) __builtin_clz(x) -> returns the number of zeros at the beginning in the bit representaton of x.
// 2) __builtin_ctz(x) -> returns the number of zeros at the end in the bit representaton of x.
// 3) __builtin_popcount(x) -> returns the number of ones in the bit representaton of x.
// 4) __builtin_parity(x) -> returns the parity of the number of ones in the bit representaton of x.

void solve(){
    ll n, a, b; cin>>n>>a>>b;
    ll t = a/(b+1);
    ll r = a%(b+1);
    ll cnt = 0;
    for(ll i=0; i<n; i++){
        cout<<'R';
        cnt++;
        if(cnt == t){
            cnt = 0;
            if(r > 0){
                cout<<'R';
                i++;
                r--;
            }
            if(b > 0){
                cout<<'B';
                i++;
                b--;
            }
        }
    }
    cout<<endl;
}

int main(){

    // cfh - ctrl+alt+b
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("error.txt", "w", stderr);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin >> t;
    for(ll i=1; i<=t; i++){
        pt(i);
        solve();
    }

    return 0;
}