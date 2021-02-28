/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <sys/types.h>

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
    int n; cin>>n;
    string b; cin>>b;
    int count{};
    for(const auto &c: b){
        if(c=='1')
        count++;
    }
    count += 120-n;
    if((count/120.0)*100 >= 75){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}