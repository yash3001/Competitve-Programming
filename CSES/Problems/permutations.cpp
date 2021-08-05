/* @author -> gamma30 */
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define x first
#define y second
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
    ll n; cin>>n;
    if(n>3){
        string odd{}, even{};
        forf(ll, i, n){
            if((i+1)%2==0){
                even+=to_string(i+1)+" ";
            }
            else{
                odd+=to_string(i+1)+" ";
            }
        }
        cout<<even<<odd;
    }
    else if(n==1){
        cout<<n;
    }
    else{
        cout<<"NO SOLUTION";
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t{1}; 
    while(t--){
        solve();
    }
    
    return 0;
}
