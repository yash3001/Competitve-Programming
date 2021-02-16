/* @author -> gamma30 */
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forf(t,i,n) for(t i=0;i<n;i++)
#define forr(t,i,n) for(t i=n-1;i>=0;i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

void solve(){
    int n, m; cin>>n>>m;
    vector<bool> vec(n, true);
    vec.shrink_to_fit();
    forf(int, i, m){
        int t; cin>>t;
        vec.at(t-1) = false;
    }
    bool chef=true;
    vi c, a;
    forf(int, i, n){
        if(vec.at(i)){
            if(chef){
                c.push_back(i+1);
                chef = false;
            }
            else{
                a.push_back(i+1);
                chef = true;
            }

        }
    }
    forf(int, i, c.size()){
        cout<<c.at(i)<<" ";
    }
    cout<<endl;
    forf(int, i, a.size()){
        cout<<a.at(i)<<" ";
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

    int t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}