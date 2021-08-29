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
    ll n; cin>>n;
    vll even, odd;
    vll arr;
    forf(ll, i, n){
        ll t; cin>>t;
        arr.pb(t);
        if(t%2 == 0){
            odd.pb(i);
        }
        else{
            even.pb(i);
        }
    }

    if(abs((ll)odd.size()-(ll)even.size()) >= 2){
        cout<<-1<<endl;
        return;
    }
    
    ll odd_c = odd.size(), even_c = even.size();
    ll ans = 0;
    if(odd_c == even_c){
        //even first
        vll even_order;
        ll flag = 0;
        for(ll i=0; i<n; i++){
            if(flag == 0){
                even_order.pb(i);
            }
            flag = !flag;
        }
        ll t1 = 0;
        for(ll i=0; i<even.size(); i++){
            t1 += abs(even[i]-even_order[i]);
        }

        vll odd_order;
        flag = 0;
        for(ll i=0; i<n; i++){
            if(flag == 0){
                odd_order.pb(i);
            }
            flag = !flag;
        }
        ll t2 = 0;
        for(ll i=0; i<odd.size(); i++){
            t2 += abs(odd[i]-odd_order[i]);
        }

        ans = min(t1, t2);
    }
    else{
        if(odd_c > even_c){
            vll odd_order;
            ll flag = 0;
            for(ll i=0; i<n; i++){
                if(flag == 0){
                    odd_order.pb(i);
                }
                flag = !flag;
            }
            ll t1 = 0;
            for(ll i=0; i<odd.size(); i++){
                t1 += abs(odd[i]-odd_order[i]);
            }
            ans = t1;
        }
        else{
            vll even_order;
            ll flag = 0;
            for(ll i=0; i<n; i++){
                if(flag == 0){
                    even_order.pb(i);
                }
                flag = !flag;
            }
            ll t1 = 0;
            for(ll i=0; i<even.size(); i++){
                t1 += abs(even[i]-even_order[i]);
            }
            ans = t1;
        }
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