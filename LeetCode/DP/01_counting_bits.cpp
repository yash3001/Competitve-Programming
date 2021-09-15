/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> ans(n+1, 0);
    for(int i=1; i<=n; i++){
        ans[i] = ans[i>>1] + i&1;
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}