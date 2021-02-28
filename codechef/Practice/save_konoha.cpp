#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

void solve(){
    ll n, z, count{}; cin>>n>>z;
    multiset<ll> powers;
    for(ll i=0; i<n; i++){
        ll temp;cin>>temp;
        powers.insert(temp);
    }

    auto it = powers.rbegin();
    while((*it) !=0 && z > 0){
        z -= *it;
        ll num = *it;
        powers.erase(num);
        powers.insert(num/2);
        it = powers.rbegin();
        count++;
    }
    if(*it == 0){
        cout<<"Evacuate"<<endl;
    }
    else{
        cout<<count<<endl;
    }
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