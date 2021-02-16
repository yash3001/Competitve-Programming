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
    string s; cin>>s;
    if(s.length()<10){
        cout<<"NO"<<endl;
        return;
    }
    bool upper=0, lower=0, num=0, special=0;
    for(int i=0; i<s.length(); i++){
        char c=s[i];
        if(!lower&&(c>='a'&&c<='z')){
            lower=1;
        }
        if(!upper&&(c>='A'&&c<='Z')&&(i!=0 && i!=s.length()-1)){
            upper=1;
        }
        if(!num&&(c>='0'&&c<='9')&&(i!=0 && i!=s.length()-1)){
            num=1;
        }
        if(!special&&(c=='@'||c=='#'||c=='%'||c=='&'||c=='?')&&(i!=0 && i!=s.length()-1)){
            special=1;
        }
        if(upper&&lower&&num&&special)
            break;
    }
    if(upper&&lower&&num&&special){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}