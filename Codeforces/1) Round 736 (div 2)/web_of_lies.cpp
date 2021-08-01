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
    ll n, m; cin>>n>>m;

    vll outdeg1(n+1, 0), outdeg2;
    ll count1{}, count2{};

    while(m--){
        ll a, b; cin>>a>>b;
        ll x = min(a, b);
        ll y = max(a, b);

        if(outdeg1[x]++ == 0){
            count1++;
        }
    }

    ll q; cin>>q;

    outdeg2 = outdeg1;
    count1 = n-count1;
    count2 = count1;
    while(q--){
        ll a, b, c;
        cin>>a;
        if(a == 3){
            cout<<count2<<endl;
            count2 = count1;
            outdeg2 = outdeg1; 
        }
        else{
            cin>>b>>c;
            if(a == 1){
                ll x, y;
                x = min(b, c);
                y = max(b, c);

                if(outdeg2[x]++ == 0){
                    count2--;
                }
            }
            if(a == 2){
                ll x, y;
                x = min(b, c);
                y = max(b, c);

                if(--outdeg2[x] == 0){
                    count2++;
                }
            }
        }
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