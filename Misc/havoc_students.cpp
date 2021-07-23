/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    unordered_map<int, int> mp[5000];
    string s1[10], s2[10];
    for(int i=0; i<n; i++){
        cin>>s1[i];
        cin>>s2[i];
    }
    // for(int i=0; i<n; i++){
    //     for(const auto &n: mp[i]){
    //         cout<<n.first<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0; i<n; i++){
        cout<<s1[i]<<endl;
        cout<<s2[i]<<endl;
    }
    return 0;
}