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

// dp[n]
// ll dp[61][61][2];

ll helper(vll &g, vll &u, vll &v, vll &d, ll n, ll last_pos, ll val){
    if(n==0){
        return 0;
    }
    // if(dp[n][last_pos][val]!=-1){
    //     return dp[n][last_pos][val];
    // }
    ll sum = g.at(n-1);
    if(val == 1){
        if(last_pos==-1){
            last_pos = n;
        }
    }
    if(val == 1){
        for(int i=0; i<u.size(); i++){
            if(u.at(i)==n){
                if(last_pos>=v.at(i)){
                    sum+=d.at(i);
                }
            }
        }
    }
    else{
        last_pos = -1;
    }
    // return dp[n][last_pos][val]=(max(sum+helper(g, u, v, d, n-1, last_pos, 1), helper(g, u, v, d, n-1, -1, 0)));
    // return (max(sum+helper(g, u, v, d, n-1, last_pos, 1), helper(g, u, v, d, n-1, -1, 0)));
    ll max_ = (max(sum+helper(g, u, v, d, n-1, last_pos, 1), helper(g, u, v, d, n-1, -1, 0)));
    cout<<max_<<endl;
    return max_;
}

void solve(){
    // memset(dp, -1, sizeof(dp));
    ll n, m, k; cin>>n>>m>>k;
    vll g;
    forf(ll, i, n){
        ll t; cin>>t;
        g.pb(t);
    }
    // vll nums(n, 1);
    vll u, v, d;
    forf(ll, i, m){
        ll ui, vi, di; cin>>ui>>vi>>di;
        u.pb(ui); v.pb(vi); d.pb(di);
    }
    cout<<helper(g, u, v, d, n, -1, 0)<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         for(int k=0; k<2; k++){
    //             cout<<dp[i][j][k]<<endl;
    //         }
    //     }
    // }
    // cout<<helper(nums, g, d, u, v, n, 0)<<endl;
    // vll ans;
    // for(ll i=0; i<pow(2,n); i++){
    //     ll count{};
    //     string b;
    //     ll pos{n-1};
    //     // cout<<"Inside loop 1"<<endl;
    //     ll curnum = i;
    //     while(pos>=0){
    //         if(curnum&1){
    //             count+=g.at(pos);
    //         }
    //         b=((curnum&1)==1?'1':'0')+b;
    //         curnum>>=1;
    //         pos--;
    //     // cout<<"Inside loop 2"<<endl;
    //     }
    //     // cout<<b<<" "<<count<<endl;
    //     for(int j=0; j<m; j++){
    //         // cout<<b.at(u.at(j)-1)<<endl;
    //         if(b.at(u.at(j)-1)=='1'){
    //             // cout<<"yes"<<endl;
    //             bool check=1;
    //             for(int k=u.at(j)-1; k<v.at(j); k++){
    //                 if(b.at(k)!='1'){
    //                     check=0;
    //                     break;
    //                 }
    //             }
    //             if(check){
    //                 // cout<<"yes"<<endl;
    //                 count+=d.at(j);
    //             }
    //         }
    //     }
    //     ans.pb(count);
    //     // cout<<"Inside loop 3"<<endl;
    // }
    // // print(ans);
    // sort(all(ans));
    // for(ll i=0; i<k; i++){
    //     cout<<ans.at(ans.size()-i-1)<<" ";
    // }
    // cout<<endl;
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