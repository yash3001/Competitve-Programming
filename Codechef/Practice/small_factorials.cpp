#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    unsigned long long fact{1};
    for(int i=1; i<=n; i++){
        fact*=i;
    }
    cout << fact << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}