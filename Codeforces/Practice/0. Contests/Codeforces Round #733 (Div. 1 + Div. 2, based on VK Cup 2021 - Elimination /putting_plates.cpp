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
    ll m, n; cin>>m>>n;

    vvll mat(m, vll(n, 0));
    int xadd[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int yadd[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for(ll j=0; j<n; j++){
        if(mat[0][j] == 0){
            mat[0][j] = 1;
            for(int k=0; k<8; k++){
                int new_x = 0+xadd[k];
                int new_y = j+yadd[k];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                    mat[new_x][new_y] = -1;
                }
            }
        }
        if(mat[m-1][j] == 0){
            mat[m-1][j] = 1;
            for(int k=0; k<8; k++){
                int new_x = m-1+xadd[k];
                int new_y = j+yadd[k];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                    mat[new_x][new_y] = -1;
                }
            }
        }
    }
    for(ll i=0; i<m; i++){
        if(mat[i][0] == 0){
            mat[i][0] = 1;
            for(int k=0; k<8; k++){
                int new_x = i+xadd[k];
                int new_y = 0+yadd[k];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                    mat[new_x][new_y] = -1;
                }
            }
        }
        if(mat[i][n-1] == 0){
            mat[i][n-1] = 1;
            for(int k=0; k<8; k++){
                int new_x = i+xadd[k];
                int new_y = n-1+yadd[k];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n){
                    mat[new_x][new_y] = -1;
                }
            }
        }
    }

    for(const auto &v: mat){
        for(const auto &n: v){
            if(n == -1){
                cout<<0;
            }
            else{
                cout<<n;
            }
        }
        cout<<endl;
    }
    cout<<endl;
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