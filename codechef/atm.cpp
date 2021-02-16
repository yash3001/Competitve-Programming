#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int x; cin>>x;
    float y; cin>>y;
    if(x%5==0 && x+0.50>=y)
        y-=x+0.50;
    cout << setprecision(2) << fixed << y << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    solve();
    return 0;
}