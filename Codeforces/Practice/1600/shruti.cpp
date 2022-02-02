#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int i = 0;
        int ans = 1;
        while(i < n){
            int cnt = 0;
            char ch = s[i];
            while(i < n && s[i] == ch){
                i++;
                cnt++;
            }
            ans *= cnt;
            ans %= 10000007;
        }
        cout<<ans<<endl;
    }
    return 0;
}