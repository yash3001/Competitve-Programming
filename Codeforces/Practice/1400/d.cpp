// @author ↓

//   ████████ ██                       ██   ██        ██           ██         
//  ██░░░░░░ ░██                      ░██  ░░        ░██          ░░          
// ░██       ░██      ██████ ██   ██ ██████ ██       ░██  ██████   ██ ███████ 
// ░█████████░██████ ░░██░░█░██  ░██░░░██░ ░██       ░██ ░░░░░░██ ░██░░██░░░██
// ░░░░░░░░██░██░░░██ ░██ ░ ░██  ░██  ░██  ░██       ░██  ███████ ░██ ░██  ░██
//        ░██░██  ░██ ░██   ░██  ░██  ░██  ░██   ██  ░██ ██░░░░██ ░██ ░██  ░██
//  ████████ ░██  ░██░███   ░░██████  ░░██ ░██  ░░█████ ░░████████░██ ███  ░██
// ░░░░░░░░  ░░   ░░ ░░░     ░░░░░░    ░░  ░░    ░░░░░   ░░░░░░░░ ░░ ░░░   ░░ 



    #include<bits/stdc++.h>
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    #pragma GCC optimize("O3")
    #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
    #pragma GCC optimize("unroll-loops")

    using namespace std;
    using namespace chrono;
    using namespace __gnu_pbds;

    #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
    // order_of_key(k) - no. of elements strictly smaller than k
    // find_by_order(k) - - k-th element in a set(counting from zero)
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
    #define each(a,x) for(auto &a: x)
    #define read(a) each(x, a) { cin>>x; }
    #define print(x) for(const auto &e: (x)) { cout<<e<<" "; } cout<<endl


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
     
    template<typename A> void _print(vector<A> v){ if(!v.empty()){ cerr << "[ "; for(auto it=v.begin(); it!=(v.end()-1); it++){ _print(*it); cerr <<", "; } _print(*(v.end()-1)); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A, typename B> void _print(pair<A, B> p){ cerr << "{ "; _print(p.first); cerr << ", "; _print(p.second); cerr << " }"; }
    template<typename A> void _print(set<A> s){ if(!s.empty()){ cerr << "{ "; for(auto it=s.begin(), lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*(s.rbegin())); cerr << " }"; } else{ cerr << "{}"; } }
    template<typename A, typename B> void _print(map<A, B> mp){ if(!mp.empty()){ cerr << "[ "; for(auto it=mp.begin(), lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*(mp.rbegin())); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A> void _print(multiset<A> s){ if(!s.empty()){ cerr << "{ "; for(auto it=s.begin(), lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*(s.rbegin())); cerr << " }"; } else{ cerr << "{}"; } }
    template<typename A, typename B> void _print(multimap<A, B> mp){ if(!mp.empty()){ cerr << "[ "; for(auto it=mp.begin(), lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*(mp.rbegin())); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A> void _print(unordered_set<A> s){ if(!s.empty()){ cerr << "{ "; auto it = s.begin(); for(auto lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*it); cerr << " }"; } else{ cerr << "{}"; } }
    template<typename A, typename B> void _print(unordered_map<A, B> mp){ if(!mp.empty()){ cerr << "[ "; auto it = mp.begin(); for(auto lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*it); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A> void _print(unordered_multiset<A> s){ if(!s.empty()){ cerr << "{ "; auto it=s.begin(); for(auto lit=next(it); lit!=(s.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*it); cerr << " }"; } else{ cerr << "{}"; } }
    template<typename A, typename B> void _print(unordered_multimap<A, B> mp){ if(!mp.empty()){ cerr << "[ "; auto it=mp.begin(); for(auto lit=next(it); lit!=(mp.end()); it++, lit++){ _print(*it); cerr <<", "; } _print(*it); cerr << " ]"; } else{ cerr << "[]"; } }
    template<typename A> void _print(stack<A> s){ if(!s.empty()){ stack<A> t; cerr << "T[ "; while(s.size() != 1){ _print(s.top()); cerr << ", "; t.push(s.top()); s.pop(); } _print(s.top()); cerr << " ]B"; t.push(s.top()); s.pop(); while(!t.empty()){ s.push(t.top()); t.pop(); } } else{ cerr << "T[]B"; } }
    template<typename A> void _print(queue<A> q){ if(!q.empty()){ queue<A> t; cerr << "F[ "; while(q.size() != 1){ _print(q.front()); cerr << ", "; t.push(q.front()); q.pop(); } _print(q.front()); cerr << " ]B"; t.push(q.front()); q.pop(); while(!t.empty()){ q.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
    template<typename A> void _print(priority_queue<A> pq){ if(!pq.empty()){ queue<A> t; cerr << "T[ "; while(pq.size() != 1){ _print(pq.top()); cerr << ", "; t.push(pq.top()); pq.pop(); } _print(pq.top()); cerr << " ]B"; t.push(pq.top()); pq.pop(); while(!t.empty()){ pq.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
    template<typename A> void _print(priority_queue<A, vector<A>, greater<A>> pq){ if(!pq.empty()){ queue<A> t; cerr << "T[ "; while(pq.size() != 1){ _print(pq.top()); cerr << ", "; t.push(pq.top()); pq.pop(); } _print(pq.top()); cerr << " ]B"; t.push(pq.top()); pq.pop(); while(!t.empty()){ pq.push(t.front()); t.pop(); } } else{ cerr << "F[]B"; } }
     
   
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
    vector<ll> divisors(ll n) { vector<ll> divisors; for(ll i = 1; i * i <= n; i++){ if(n % i == 0){ divisors.push_back(i); if(n/i!=i)divisors.push_back(n/i); } } return divisors; }

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


    /*--------------------------------------------------------------------------------------------------------------------------*/


    ll expo1(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a) ; b = b >> 1;} return res;}

    string binary(ll n){
      string s = bitset<64> (n).to_string();
      auto loc = s.find('1');
      if(loc!=string::npos){
       return s.substr(loc);
      }
      return "0";
      //return s;
    }

    
    ll fill(vector<string> &v, int row,int col, int r,int c,char ch,char check){
      // lower left

      int i=row,j=col;
      //v[i][j]=ch;
      while(i<r && j>=0){
        if(v[i][j]!=check){
          break;
        }
        v[i][j]=ch;
        i++;j--;
      }
      //cout<<" i "<<i<<" j "<<j<<endl;

       // lower right
      i=row,j=col;
      while(i<r && j<c){
         if(v[i][j]!=check){
          break;
        }
        v[i][j]=ch;
        i++;j++;
      }

      //upper left
       i=row,j=col;
      while(i>=0 && j>=0){
         if(v[i][j]!=check){
          break;
        }
        v[i][j]=ch;
        i--;j--;
      }

      // upper right
      i=row,j=col;
      while(i>=0 && j<c){
         if(v[i][j]!=check){
          break;
        }
        v[i][j]=ch;
        i--;j++;
      }



    }

    bool notValid(vector<string> &v, int r,int c){
      for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
          if(v[i][j]=='X'){
            return false;
          }
        }
      }
      return true;
    }

    ll ans =0;
    ll rec(vector<string> &v, ll r, ll c, ll pl){
       if(notValid(v,r,c)){
         if(pl==0){
           ans++;
         }
       }

       for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            if(v[i][j]=='X'){
              fill(v,i,j,r,c,'I','X');
              rec(v,r,c,!pl);
              fill(v,i,j,r,c,'X','I');
            }
         }
       }

    }


  void solve(){
     
    ll r,c;
    cin>>r>>c;
    ans =0;
    vector<string> v(r);
    for(int i=0;i<r;i++){
      cin>>v[i];
    }

    rec(v,r,c,0);

    cout<<ans<<endl;

  }


    int main()
    {
        fastio();

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr);
    #endif
       
       //  ll Mx = 1e12;
       //   fact[0]=1;
       // for(ll i=1;i<=N;i++){
       //    if(i*fact[i-1]>Mx){
       //      break;
       //    }
       //    fact[i]=i*fact[i-1];
       // }

        
       
       
        int t;
        cin >> t;
        //t = 1;
        int tc = 1;
        while (t--) {
            cout << "Case #" << tc << ": ";
            solve();
            tc++;
          
        }


        return 0;
    }