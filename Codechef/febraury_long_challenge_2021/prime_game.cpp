/* @author -> gamma30 */
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define endl "\n"
#define EPS 1e-9
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

void solve(vll &ans){
    ll x,y;
    cin>>x>>y;
    if(ans[x]<=y){
        cout<<"Chef"<<endl;
    }
    else{
        cout<<"Divyam"<<endl;
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
    const ll N = 1000001;
    vector<bool> sieve(N, true);
    for(ll i=2; i<=sqrt(N-1); i++){
        if(sieve.at(i)){
            for(int j=i*i; j<N; j=j+i){
                sieve.at(j)=false;
            }
        }
    }

    vll ans(N, 0);
    ll count{};
    for(ll i=2; i<N; i++){
        if(sieve.at(i)){
            count++;
        }
        ans.at(i) = count;
    }

    ll t; cin >> t;
    while(t--){
        solve(ans);
    }
    
    return 0;
}