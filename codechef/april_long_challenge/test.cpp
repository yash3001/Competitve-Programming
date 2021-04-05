/* @author -> gamma30 */
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define endl "\n"
#define EPS 1e-9
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forf(t,i,n) for(t i=0;i<n;i++)
#define forr(t,i,n) for(t i=n-1;i>=0;i--)
#define print(x) for(const auto &e: (x)) { cout<<e<<" "; } cout<<endl

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
typedef unordered_map<long long, long long> umll;

template<typename T>
T gcd(T a, T b){
    if(b == 0)
        return a;
    return(gcd<T>(b, a%b));
}

template<typename T>
T lcm(T a, T b){
    return (a / gcd<T>(a, b)) * b;
}

void solve(){
    // string s, t;
    // while(cin>>t){
    //     s.append(t+" ");
    // }
    // s.pop_back();
    // cout<<s;
    vll nums {1,2,4,5,6, 7};
    // vector<long long>::iterator it = lower_bound(all(nums), 5);
    // cout<<it-nums.begin();
    ll l=0, u=nums.size()-1, mid=(u+l)/2;
    while(l<=u){
        mid = l+(u-l)/2;
        if(nums.at(mid) == 9){
            break;
        }
        if(nums.at(mid)>9){
            u = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(l>u)
        cout<<"no"<<endl;
    else{
        cout<<mid<<endl;

        }
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}