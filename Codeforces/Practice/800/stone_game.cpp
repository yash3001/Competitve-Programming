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
    vll nums(n);
    forf(ll, i, n){
        cin>>nums[i];
    }
    
    ll l=LONG_LONG_MIN, s=LONG_LONG_MAX, li, si;
    forf(ll, i, n){
        if(nums[i] < s){
            s = nums[i];
            si = i;
        }
        if(nums[i] > l){
            l = nums[i];
            li = i;
        }
    }

    // cout<<"max - "<<l<<" max-i - "<<li<<" min - "<<s<<" min-i - "<<si<<" ";
    // li = min(li+1, n-li);
    // si = min(si+1, n-si);

    // if(si+1 == n-si){
    //     cout<<si+1<<endl;
    //     return;
    // }
    // if(li+1 == n-li){
    //     cout<<li+1<<endl;
    //     return;
    // }

    // if(si+1 < n-si){
    //     if(li+1 < n-li){
    //         cout<<max(si+1, li+1)<<endl;
    //     }
    //     else{
    //         cout<<(si+1+n-li)<<endl;
    //     }
    // }
    // else{
    //     if(n-li < li+1){
    //         cout<<max(n - li, n - si)<<endl;
    //     }
    //     else{
    //         cout<<(n-si, li+1)<<endl;
    //     }
    // }

    if(li < si){
        swap(li, si);
    }
    
    ll n1 = max(li+1, si+1);
    ll n2 = max(n-li, n-si);
    ll n3 = si+1 + n-li;

    cout<<min(n1, min(n2, n3))<<endl;
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