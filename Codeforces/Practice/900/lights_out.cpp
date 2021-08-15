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
    bool matrix[3][3];
    memset(matrix, 1, sizeof(matrix));
    int input[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>input[i][j];
        }
    }

    int xadd[]{-1, 0, 1, 0};
    int yadd[]{0, 1, 0, -1};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int count = 0;
            for(int k=0; k<4; k++){
                int newx = i+xadd[k];
                int newy = j+yadd[k];
                if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                    count += input[newx][newy];
                }
            }
            count += input[i][j];
            if(count&1){
                matrix[i][j] = 0;
            }
            else{
                matrix[i][j] = 1;
            }
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
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