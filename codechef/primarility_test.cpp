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
typedef vector<string> vs;

void solve(vll &primes){
    ll n; cin>>n;
    if(primes.at(n)){
        cout<<"yes"<<endl;
        return;
    }
    cout<<"no"<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll N=100000;
    vll primes(N+1, 1);
    primes.at(0) = primes.at(1) = 0;
    for(ll i=2; i<=sqrt(N); i++){
        if(primes.at(i))
            for(ll j=i*i; j<=N; j=j+i){
                primes.at(j) = 0;
            }
    }



    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve(primes);
    }
    
    return 0;
}