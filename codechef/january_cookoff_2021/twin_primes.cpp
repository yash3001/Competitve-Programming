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

void solve(int *ans){
    ll n; cin>>n;
    cout<<ans[n]<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    const int N = 1000001;
    bool sieve[N];
    memset(sieve, true, sizeof(sieve));
    for(int i=2; i<=sqrt(N-1); i++){
        if(sieve[i]){
            for(int j=i*i; j<N; j=j+i){
                sieve[j]=false;
            }
        }
    }

    int ans[N]={};
    int count{};
    for(int i=5; i<N; i++){
        if(sieve[i]&&sieve[i-2])
            count++;
        ans[i] = count;
    }
    ll t; cin >> t;
    while(t--){
        solve(ans);
    }
    
    return 0;
}