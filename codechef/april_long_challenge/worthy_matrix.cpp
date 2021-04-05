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
T swap(T a, T b){
    a = a^b;
    b = b^a;
    a = a^b;
}

void solve(){
    ll n, m, k; cin>>n>>m>>k;
    vvll mat;
    ll ans{};
    forf(ll, i, n){
        mat.pb(vector<long long>());
        forf(ll, j, m){
            ll t; cin>>t;
            mat.at(i).pb(t);
            if(t>=k){
                ans++;
            }
        }
    }
    // forf(ll, i, n){
    //     forf(ll, j, m){
    //         cout<<mat.at(i).at(j)<<" ";
    //     }
    //     cout<<endl;
    // }
    ll max_l = min(n, m);
    forf(ll, i, n-1){
        bool worthy = false;
        forf(ll, j, m-1){
            ll l=2;
            // bool worthy = false;
            if(!worthy){
                for(l=2; l<=max_l && l<=n-i && l<=m-j; l++){
                    // cout<<"loop: x: "<<i<<" y: "<<j<<endl;
                    ll sum{};
                    for(ll x=i; x<i+l; x++){
                        for(ll y=j; y<j+l; y++){
                            sum+=mat.at(x).at(y);
                            // cout<<"x: "<<x<<" y: "<<y<<" value: "<<mat.at(x).at(y)<<"   ";
                        }
                    }
                    // cout<<"\nsum: "<<sum<<" for i: "<<i<<" j: "<<j<<" l: "<<l<<endl;
                    if(sum/(l*l) >= k){
                        // cout<<"avg: "<<sum/(l*l)<<" for i: "<<i<<" j: "<<j<<" l: "<<l<<endl;
                        worthy = true;
                        ans++;
                    }
                    if(worthy){
                        break;
                    }
                }
                if(worthy){
                    // cout<<"else"<<endl;
                    // cout<<"loop: x: "<<i<<" y: "<<j<<" max: "<<max(min(min(max_l-l, n-i-l), m-j-l), zero)<<endl;
                    ans += min(min(max_l-l, n-i-l), m-j-l);
                }
            }
            else{
                // cout<<"else"<<endl;
                ans += min(min(max_l-l, n-i-l), m-j-l)+1;
                // cout<<"loop: x: "<<i<<" y: "<<j<<" max: "<<min(min(max_l-l, n-i-l), m-j-l)+1<<endl;
                // ans += min(min(max_l-l, n-i-l), m-j-l);
                // cout<<"value: "<<min(min(max_l-l, n-i-l), m-j-l)<<" l: "<<l<<" m: "<<m<<" n: "<<n<<" i: "<<i<<" j: "<<j<<endl;
            }
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