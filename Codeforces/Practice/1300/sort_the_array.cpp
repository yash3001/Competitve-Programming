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
    ll n; cin>>n;
    vll a, b;
    forf(ll, i, n){
        ll t; cin>>t;
        a.push_back(t);
        b.push_back(t);
    }
    sort(all(b));
    umll mp;
    forf(ll, i, n){
        mp[b[i]] = i;
    }
    ll l=-1, r=-1;
    for(ll i=0; i<n; i++){
        if(mp[a[i]] != i){
            l = i;
            break;
        }
    }
    for(ll i=n-1; i>=0; i--){
        if(mp[a[i]] != i){
            r = i;
            break;
        }
    }

    if(l == -1 && r == -1){
        cout<<"yes"<<endl<<"1 1";
        return;
    }

    reverse(a.begin()+l, a.begin()+r+1);
    for(ll i=0; i<n; i++){
        if(mp[a[i]] != i){
            cout<<"no";
            return;
        }
    }

    cout<<"yes"<<endl<<l+1<<" "<<r+1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t{1};
    while(t--){
        solve();
    }
    
    return 0;
}