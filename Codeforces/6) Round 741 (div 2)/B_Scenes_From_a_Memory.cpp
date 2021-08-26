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
    ll k; cin>>k;
    string s; cin>>s;
    umll mp;
    mp['2']++;
    mp['3']++;
    mp['5']++;
    mp['7']++;

    umll ind;
    ind['2'] = -1;
    ind['3'] = -1;
    ind['5'] = -1;
    ind['7'] = -1;

    int found = 0;
    char ch;

    for(ll i=0; i<s.size(); i++){
        char c = s[i];
        if(!mp[c]){
            ch = c;
            found = 1;
            break;
        }
        mp[c]++;
        if(ind[c] == -1){
            ind[c] = i;
        }
    }

    if(found){
        cout<<1<<endl<<ch<<endl;
        return;
    }

    if(mp['2']>2){
        cout<<"2\n22\n";
        return;
    }
    if(mp['3']>2){
        cout<<"2\n33\n";
        return;
    }
    if(mp['5']>2){
        cout<<"2\n55\n";
        return;
    }
    if(mp['7']>2){
        cout<<"2\n77\n";
        return;
    }

    if(mp['2'] > 1 && mp['5'] > 1 && ind['2'] < ind['5']){
        cout<<2<<endl<<25<<endl;
        return;
    }
    if(mp['2'] > 1 && mp['7'] > 1 && ind['2'] < ind['7']){
        cout<<2<<endl<<27<<endl;
        return;
    }
    if(mp['3'] > 1 && mp['5'] > 1 && ind['3'] < ind['5']){
        cout<<2<<endl<<35<<endl;
        return;
    }
    if(mp['5'] > 1 && mp['7'] > 1 && ind['5'] < ind['7']){
        cout<<2<<endl<<57<<endl;
        return;
    }
    if(mp['3'] > 1 && mp['2'] > 1 && ind['3'] < ind['2']){
        cout<<2<<endl<<32<<endl;
        return;
    }
    if(mp['5'] > 1 && mp['2'] > 1 && ind['5'] < ind['2']){
        cout<<2<<endl<<52<<endl;
        return;
    }
    if(mp['7'] > 1 && mp['2'] > 1 && ind['7'] < ind['2']){
        cout<<2<<endl<<72<<endl;
        return;
    }
    if(mp['7'] > 1 && mp['5'] > 1 && ind['7'] < ind['5']){
        cout<<2<<endl<<75<<endl;
        return;
    }
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