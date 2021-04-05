/* @author -> gamma30 */
#include <algorithm>
#include <bits/stdc++.h>
#include <exception>

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

void solve(){
    ll n, m, k; cin>>n>>m>>k;
    vvll mat, aux;
    ll ans{};
    forf(ll, i, n){
        mat.pb(vector<long long>());
        aux.pb(vector<long long>());
        forf(ll, j, m){
            ll t; cin>>t;
            mat.at(i).pb(t);
            if(i==0){
                aux.at(0).pb(mat.at(0).at(j));
            }
            if(t>=k){
               ans++;
            }
        }
    }
    for(ll j=0; j<m; j++){
        for(ll i=1; i<n; i++){
            aux.at(i).pb(mat.at(i).at(j) + aux.at(i-1).at(j));
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=1; j<m; j++){
            aux.at(i).at(j) = aux.at(i).at(j) + aux.at(i).at(j-1);
        }
    }

    // forf(ll, i, n){
    //     forf(ll, j, m){
    //         cout<<mat.at(i).at(j)<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl;
    // forf(ll, i, n){
    //     forf(ll, j, m){
    //         cout<<aux.at(i).at(j)<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    ll max_l = min(n, m);
    for(ll l=2; l<=max_l; l++){
        for(ll i=l-1; i<n; i++){
            ll j=l-1;
            for(; j<m; j++){
                ll sum{};
                if(i-l < 0 && j-l < 0){
                    sum = aux.at(i).at(j);
                }
                else if(i-l<0){
                    sum = aux.at(i).at(j) - aux.at(i).at(j-l);
                }
                else if(j-l<0){
                    sum = aux.at(i).at(j) - aux.at(i-l).at(j);
                }
                else{
                    sum = aux.at(i).at(j) - aux.at(i-l).at(j) - aux.at(i).at(j-l) + aux.at(i-l).at(j-l);
                }
                // cout<<"sum: "<<sum<<" x: "<<i<<" y: "<<j<<endl;
                if(sum/(l*l)>=k){
                    break;
                }
            }
            ans += m - j;
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