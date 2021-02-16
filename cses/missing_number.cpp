/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <limits>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
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
    ull n{}; cin>>n;
    vi nums(n, 0);
    forf(int, i, n-1){
        ll t;cin>>t;
        nums[t-1] = 1;
    }
    auto ans = find(nums.begin(), nums.end(), 0);
    cout << ans-nums.begin()+1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t{1};
    while(t--){
        solve();
    }
    
    return 0;
}