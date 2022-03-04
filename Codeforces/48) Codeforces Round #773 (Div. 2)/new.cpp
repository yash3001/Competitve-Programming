#include<bits/stdc++.h>
    // #include<ext/pb_ds/assoc_container.hpp>
    // #include<ext/pb_ds/tree_policy.hpp>
    #pragma GCC optimize("O3")
    #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
    #pragma GCC optimize("unroll-loops")

    using namespace std;
    using namespace chrono;
    // using namespace __gnu_pbds;

    #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define MOD 1000000007
    #define MOD1 998244353
    #define INF 1e18
    #define endl "\n"
    #define pb push_back
    #define ppb pop_back
    //#define mp make_pair
    #define ff first
    #define ss second
    #define PI 3.141592653589793238462
    #define set_bits __builtin_popcountll
    #define sz(x) ((int)(x).size())
    #define all(x) (x).begin(), (x).end()
    #define mset(a , b) memset(a , b , sizeof(a))
    #define ll long long int
    #define read(FDFDFDF)  for(auto &FFFF:FDFDFDF){cin>>FFFF;}
    #define show(FDFDFDF)  for(auto &FFFF:FDFDFDF){cout<<FFFF<<" ";}

    #ifndef ONLINE_JUDGE
        #define dbg(x) cerr << #x << " : "; _print(x); cerr << endl;
        //#define pt(x) cerr << "\n---------Testcase " << x << "---------\n" << endl;
    #else
        #define dbg(x) ;
        //#define pt(x) ;
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
     
    template<typename A> void _print(vector<A> v){ if(!v.empty()){ cerr << "[ "; for(auto it=v.begin(); it!=(v.end()-1); it++){ _print(it); cerr <<", "; } _print((v.end()-1)); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A, typename B> void _print(pair<A, B> p){ cerr << "{ "; _print(p.first); cerr << ", "; _print(p.second); cerr << " }"; }
    template<typename A> void _print(set<A> s){ if(!s.empty()){ cerr << "{ "; for(auto it=s.begin(), lit=next(it); lit!=(s.end()); it++, lit++){ _print(it); cerr <<", "; } _print((s.rbegin())); cerr << " }"; } else{ cerr << "{}"; } }
    template<typename A, typename B> void _print(map<A, B> mp){ if(!mp.empty()){ cerr << "[ "; for(auto it=mp.begin(), lit=next(it); lit!=(mp.end()); it++, lit++){ _print(it); cerr <<", "; } _print((mp.rbegin())); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A> void _print(multiset<A> s){ if(!s.empty()){ cerr << "{ "; for(auto it=s.begin(), lit=next(it); lit!=(s.end()); it++, lit++){ _print(it); cerr <<", "; } _print((s.rbegin())); cerr << " }"; } else{ cerr << "{}"; } }
    template<typename A, typename B> void _print(multimap<A, B> mp){ if(!mp.empty()){ cerr << "[ "; for(auto it=mp.begin(), lit=next(it); lit!=(mp.end()); it++, lit++){ _print(it); cerr <<", "; } _print((mp.rbegin())); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A> void _print(unordered_set<A> s){ if(!s.empty()){ cerr << "{ "; auto it = s.begin(); for(auto lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*it); cerr << " }"; } else{ cerr << "{}"; } }
    template<typename A, typename B> void _print(unordered_map<A, B> mp){ if(!mp.empty()){ cerr << "[ "; auto it = mp.begin(); for(auto lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*it); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A> void _print(unordered_multiset<A> s){ if(!s.empty()){ cerr << "{ "; auto it=s.begin(); for(auto lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*it); cerr << " }"; } else{ cerr << "{}"; } }
    template<typename A, typename B> void _print(unordered_multimap<A, B> mp){ if(!mp.empty()){ cerr << "[ "; auto it=mp.begin(); for(auto lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*it); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A> void _print(stack<A> s){ if(!s.empty()){ stack<A> t; cerr << "T[ "; while(s.size() != 1){ _print(s.top()); cerr << ", "; t.push(s.top()); s.pop(); } _print(s.top()); cerr << " ]B"; t.push(s.top()); s.pop(); while(!t.empty()){ s.push(t.top()); t.pop(); } } else{ cerr << "T[]B"; } }
    template<typename A> void _print(queue<A> q){ if(!q.empty()){ queue<A> t; cerr << "F[ "; while(q.size() != 1){ _print(q.front()); cerr << ", "; t.push(q.front()); q.pop(); } _print(q.front()); cerr << " ]B"; t.push(q.front()); q.pop(); while(!t.empty()){ q.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
    template<typename A> void _print(priority_queue<A> pq){ if(!pq.empty()){ queue<A> t; cerr << "T[ "; while(pq.size() != 1){ _print(pq.top()); cerr << ", "; t.push(pq.top()); pq.pop(); } _print(pq.top()); cerr << " ]B"; t.push(pq.top()); pq.pop(); while(!t.empty()){ pq.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
    template<typename A> void _print(priority_queue<A, vector<A>, greater<A>> pq){ if(!pq.empty()){ queue<A> t; cerr << "T[ "; while(pq.size() != 1){ _print(pq.top()); cerr << ", "; t.push(pq.top()); pq.pop(); } _print(pq.top()); cerr << " ]B"; t.push(pq.top()); pq.pop(); while(!t.empty()){ pq.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
     


    ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
    ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
    void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
    ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
    ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
    bool revsort(ll a, ll b) {return a > b;}
    void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
    ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
    void google(int t) {cout << "Case #" << t << ": ";}
    vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
    ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
    /*--------------------------------------------------------------------------------------------------------------------------*/


    ll expo1(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a) ; b = b >> 1;} return res;}

    string binary(ll n){
      string s = bitset<64> (n).to_string();
      auto loc = s.find('1');
      if(loc!=string::npos){
        return s.substr(loc);
      }
      return s;
    }

   
    void solve(){
      
      ll n;
      cin>>n;

      vector<vector<ll>> a(n,vector<ll>(n));

      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          cin>>a[i][j];
        }
      }
      
      priority_queue<pair<ll,pair<ll,ll>>> pq;
      pq.push({a[0][0],{0,0}});

      vector<vector<ll>> dis(n,vector<ll>(n)), vis(n,vector<ll>(n));

      while(!pq.empty()){
        ll dist = pq.top().ff;
        ll i = pq.top().ss.ff;
        ll j = pq.top().ss.ss;
       
        pq.pop();
        vis[i][j]=1;
        if(i!=n-1 && a[i+1][j]!=-1 ){
           dis[i+1][j]=max(dis[i+1][j],dist+a[i+1][j]);
          pq.push({dist+a[i+1][j],{i+1,j}});    
        }
        if(j!=n-1 && a[i][j+1]!=-1){
          dis[i][j+1]=max(dis[i][j+1],dist+a[i][j+1]);
          pq.push({dist+a[i][j+1],{i,j+1}});    
        }
      }
      dbg(dis);
      cout<<dis[n-1][n-1]<<endl;
    }

    int main()
    {
        fastio();

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
        // fact[0]=1;
       
        // for(ll i=1;i<200005;i++){
        //  fact[i]=mod_mul(i,fact[i-1],MOD);
        // }
        

       
        int t;
        //cin >> t;
        t = 1;
        int tc = 1;
        while (t--) {
            //cout << "Case #" << tc << ": ";
            solve();
        //     if(t!=1){
        //     string s;
        //     cin>>s;
        // }
            tc++;
            //cout << endl;
        }


        return 0;
    }   