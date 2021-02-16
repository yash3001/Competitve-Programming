/* @author -> gamma30 */
#include <bits/stdc++.h>
#include <string>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define endl "\n"
#define EPS 1e-9
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
    string p, p_12; cin>>p>>p_12;
    string p_24{};
    if(p_12=="AM"){
        if(p.substr(0,2)=="12"){
            p_24="00"+p.substr(3,2);
        }
        else{
            p_24=p.substr(0,2)+p.substr(3,2);
        }
    }
    else{
        if(p.substr(0,2)=="12"){
            p_24="12"+p.substr(3,2);
        }
        else{
            p_24=to_string(stoi(p.substr(0,2))+12)+p.substr(3,2);
        }
    }
    ll n; cin>>n;
    forf(ll, i, n){
        string r, r_12, r_24, l, l_12, l_24; cin>>l>>l_12>>r>>r_12;
        if(r_12=="AM"){
            if(r.substr(0,2)=="12"){
                r_24="00"+r.substr(3,2);
            }
            else{
                r_24=r.substr(0,2)+r.substr(3,2);
            }
        }
        else{
            if(r.substr(0,2)=="12"){
                r_24="12"+r.substr(3,2);
            }
            else{
                r_24=to_string(stoi(r.substr(0,2))+12)+r.substr(3,2);
            }
        }
        if(l_12=="AM"){
            if(l.substr(0,2)=="12"){
                l_24="00"+l.substr(3,2);
            }
            else{
                l_24=l.substr(0,2)+l.substr(3,2);
            }
        }
        else{
            if(l.substr(0,2)=="12"){
                l_24="12"+l.substr(3,2);
            }
            else{
                l_24=to_string(stoi(l.substr(0,2))+12)+l.substr(3,2);
            }
        }
        // cout<<"l_24 = "<<l_24<<" "<<"p_24 ="<<p_24<<" r_24 = "<<r_24<<" ";
        if(l_24<=p_24 && r_24>=p_24){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    cout<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}