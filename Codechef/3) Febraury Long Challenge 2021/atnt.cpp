/* @author -> gamma30 */
#include <bits/stdc++.h>

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

struct node{
    ll data;
    struct node *left;
    struct node *right;
    node(ll data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
};

void add(ll &parent, ll num, struct node* &pos){
    if(pos->data==parent){
        pos->children.pb(new node(num));
    }
}

void solve(){
    struct node *root = new node(1);
    ll n; cin>>n;
    for(ll i=1; i<n; i++){
        ll t; cin>>t;
        add(t, i+1, root);
    }
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t{1};
    while(t--){
        solve();
    }
    
    return 0;
}