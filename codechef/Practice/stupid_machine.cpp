#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n{};cin>>n;
    ll ans{}, smallest {1'000'000'001};
    for(ll i=0; i<n; i++){
        ll num; cin>>num;
        if(num<smallest)
            smallest=num;
        ans+=smallest;
    }
    cout<<ans<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    //code goes here
    int t; cin>>t;
    while(t--){
        solve();
    } 
    return 0;
}