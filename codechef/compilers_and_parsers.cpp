#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s; cin >> s;
    ll check{}, ans {}, i{};
    for(i=0; i<s.length(); i++){
        if(s.at(i)=='<'){
            check+=1;
        }
        else{
            check-=1;
            if(check<0)
                break;
        }
        if(check == 0){
            ans = i+1;
        }
    }
    cout << ans << endl;
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