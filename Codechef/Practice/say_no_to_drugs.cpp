/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, k, l; cin>>n>>k>>l;
        int high = 0, dost = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int s; cin>>s;
            if(i == n-1){
                dost = s;
            }
            mp[s]++;
            high = max(high, s);
        }
        if(dost == high && mp[high] == 1){
            cout<<"Yes"<<endl;
        }
        else if(k <= 0 && ((high != dost) || (high == dost && mp[high] > 1))){
            cout<<"No"<<endl;
        }
        else{
            if(dost+(k*(l-1)) > high){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}