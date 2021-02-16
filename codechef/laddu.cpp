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
    int act; cin>>act;
    string origin; cin>>origin;
    ll total{};
    forf(int, i, act){
        string s; cin>>s;
        if(s=="CONTEST_WON"){
            int rank; cin>>rank;
            total += 300;
            if(rank<20){
                total += 20-rank;
            }
        }
        else if(s=="TOP_CONTRIBUTOR"){
            total += 300;
        }
        else if(s=="BUG_FOUND"){
            int sev; cin>>sev;
            total += sev;
        }
        else{
            total += 50;
        }
    }
    cout << (origin == "INDIAN" ? total/200 : total/400) << endl;
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