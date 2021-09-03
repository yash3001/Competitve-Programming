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
    for(auto &t: nums){
        cin>>t;
    }
    vll temp(n, 0);
    ll prev = nums[0];
    for(ll i = 1; i<n; i++){
        if(nums[i]>nums[i-1])
            if(nums[i] > prev){
                temp[i] = 1;
                prev = nums[i];
            }
            else{
                prev = nums[i];
            }
        else{
            prev = nums[i];
        }
    }
    print(temp);
    ll j = 0;
    ll ans = 0;
    while(j < n){
        if(temp[j] == 1){
            ll count = 1;
            while(j < n && temp[j] == 1){
                count++;
                j++;
            }
            if(j+1 < n && temp[j+1] == 1){
                j++;
                while(j < n && temp[j] == 1){
                    count++;
                    j++;
                }
            }
            ans = max(ans, count);
            continue;
        }
        j++;
    }
    cout<<ans;
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

    ll t{1};
    while(t--){
        solve();
    }
    
    return 0;
}