#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll a{}, b{};
    ll i{};
    for(i=0; i<2*n; i++){
        if(i%2==0){
            if(s[i]=='1')
                a++;
            if(a>b+((2*n-(i+1))/2)+1 || b>a+(2*n-(i+1))/2)
                break;
        }
        else{
            if(s[i]=='1')
                b++;
            if(a>b+((2*n-(i+1))/2)|| b>a+(2*n-(i+1))/2)
                break;
        }
    }
    cout << min(i+1, 2*n) << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	    freopen("output.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
       solve(); 
    }
	return 0;
}