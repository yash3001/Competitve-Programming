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
    ull x,y; cin>>x>>y;
    if(y>=x){
        if(y%2==1){
            cout<<(y*y-x+1)<<endl;
        }
        else{
            cout<<((y-1)*(y-1)+x)<<endl;
        }
    }
    else{
        if(x%2==0){
            cout<<(x*x-y+1)<<endl;
        }
        else{
            cout<<((x-1)*(x-1)+y)<<endl;
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

    ll t; cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}