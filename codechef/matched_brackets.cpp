#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    ll dcount{}, d{}, dp{}, mcount{}, m{}, mp{};
    for(ll i=0; i<n; i++){
        ll num; cin>>num;
        if(num==1){
            dcount++;
            mcount++;
            if(dcount>d){
                d=dcount;
                dp=i+1;
            }
        }
        else{
            dcount--;
            mcount++;
            if(mcount>m){
                m=mcount;
                mp=i+2-mcount;
            }
            if(dcount==0){
                mcount=0;
            }
        }
    }
    cout << d << " " << dp << " " << m << " " << mp << endl;
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