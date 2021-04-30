/* @author -> gamma30 */
#include <bits/stdc++.h>

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

template<typename T>
void swap(T &a, T &b){
    a = a^b;
    b = b^a;
    a = a^b;
}

vll zeros(1'000'001), ones(1'000'001);
vll dp0(1'000'002), dp1(1'000'002);

void solve(){
    string s, ans="1"; cin>>s;
    ll pos0=-1, pos1=-1;
    for(int i=0; i<s.size(); i++){
        if(s.at(i)=='1'){
            for(int j=pos1+1; j<i+1; j++){
                ones.at(j)=i;
            }
            pos1 = i;
        }
        if(s.at(i)=='0'){
            for(int j=pos0+1; j<i+1; j++){
                zeros.at(j)=i;
            }
            pos0 = i;
        }
    }

    // for(int i=0; i<s.size(); i++){
    //     cout<<zeros.at(i)<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<s.size(); i++){
    //     cout<<ones.at(i)<<" ";
    // }
    // cout<<endl;

    for(int i=pos0+1, j=pos1+1; i<s.size() || j<s.size(); i++, j++){
        if(i<s.size()){
            zeros.at(i)=s.size();
        }
        if(j<s.size()){
            ones.at(j)=s.size();
        }
    }
    // for(int i=0; i<s.size(); i++){
    //     cout<<zeros.at(i)<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<s.size(); i++){
    //     cout<<ones.at(i)<<" ";
    // }
    // cout<<endl;

    dp1.at(s.size())=dp1.at(s.size()+1) = 0;
    dp0.at(s.size())=dp0.at(s.size()+1) = 0;

    for(ll i=s.size()-1; i>=0; i--){
        dp0.at(i) = dp0.at(i+1);
        dp1.at(i) = dp1.at(i+1);
        if(s.at(i)=='1' && zeros.at(i)<s.size()){
            dp0.at(i) = max(dp0.at(i), dp0.at(zeros.at(i)+1)+1);
        }
        if(s.at(i)=='0' && ones.at(i)<s.size()){
            dp0.at(i) = max(dp0.at(i), dp0.at(ones.at(i)+1)+1);
        }
        if(ones.at(i)<s.size()){
            dp1.at(i) = max(dp1.at(i), dp0.at(ones.at(i)+1)+1);
        }
    }
    // cout<<"dp0: ";
    // for(int i=0; i<s.size()+2; i++){
    //     cout<<dp0.at(i)<<" ";
    // }
    // cout<<endl;
    // cout<<"dp1: ";
    // for(int i=0; i<s.size()+2; i++){
    //     cout<<dp1.at(i)<<" ";
    // }
    // cout<<endl;

    ll var = ones.at(0)+1;
    for(ll i=1; i<dp1.at(0)+1; i++){
        // cout<<"answer starting: "<<ans<<endl;
        if(var >= s.size()){
            ans.pb('0');
            continue;
        }
        if(zeros.at(var)>=s.size()){
            ans.pb('0');
            var = zeros.at(var)+1;
            continue;
        }
        if(dp0.at(zeros.at(var)+1) < dp1.at(0)-i){
            ans.pb('0');
            var = zeros.at(var)+1;
            // cout<<"answer: "<<ans<<endl;
        }
        else{
            ans.pb('1');
            var = ones.at(var)+1;
        }
        // cout<<"answer ending: "<<ans<<endl;
    }

    if(zeros.at(0)==s.size()){
        cout<<"0"<<endl;
        return;
    }
    cout<<ans<<endl;
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