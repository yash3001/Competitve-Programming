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

    vector<vector<char>> mat(n, vector<char>(n));

    forf(ll, i, n){
        forf(ll, j, n){
            cin>>mat[i][j];
        }
    }
    umll mp_x, mp_y;
    unordered_map<ll, pair<ll, ll>> mp_x_p, mp_y_p;
    vll pos;
    ll max_x = -1;
    for(ll i=0; i<n; i++){
        ll temp = 0;
        for(ll j=0; j<n; j++){
            if(mat[i][j] == 'O'){
                temp = -1;
                break;
            }
            if(mat[i][j] == 'X')
                temp++;
        }
        if(temp > max_x){
            max_x = temp;
            pos.clear();
            pos.pb(i);
        }
        else if(temp == max_x){
            pos.pb(i);
        }
    }
    for(ll j=0; j<n; j++){
        ll temp = 0;
        ll dotPos = 0;
        for(ll i=0; i<n; i++){
            if(mat[i][j] == 'O'){
                temp = -1;
                break;
            }
            if(mat[i][j] == 'X'){
                temp++;
            }
            if(mat[i][j] == '.'){
                dotPos = i;
            }
        }
        if(temp == n-1){
            bool flag = true;
            ll xDotPos, xTemp=0;
            for(int y = 0; y<n; y++){
                if(mat[dotPos][y] == 'O'){
                    flag = 0;
                    break;
                }
                if(mat[dotPos][y] == 'X'){
                    xTemp++;
                }
                if(mat[dotPos][y] == '.'){
                    xDotPos = y;
                }
            }
            if(flag && xTemp == n-1 && xDotPos == j){
                temp = -1;
            }
        }
        if(temp > max_x){
            max_x = temp;
            pos.clear();
            pos.pb(j);
        }
        else if(temp == max_x){
            pos.pb(j);
        }
    }
    if(max_x == -1){
        cout<<"Impossible"<<endl;
        return;
    }

    cout<<(n-max_x)<<" "<<(pos.size())<<endl;

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
    ll i=1;
    while(t--){
        cout<<"Case #"<<(i++)<<": ";
        solve();
    }
    
    return 0;
}