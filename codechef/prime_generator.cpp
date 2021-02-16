/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <new>

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

}

int main(){
    // #ifndef ONLINE_JUDGE
	//     freopen("input.txt", "r", stdin);
	//     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll N{1'000'000'001};
    vector<bool> sieve(N, 1);
    sieve[0] = sieve[1] = 0;
    for(ll i=2; i<=sqrt(N-1); i++){
        if(sieve[i]){
            for(ll j=i*i; j<N; j=j+i){
                sieve[j] = 0;
                cout<<"Inside loop 1"<<endl;
            }
        }
        cout<<"Inside loop 2"<<endl;
    }

    ll t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}