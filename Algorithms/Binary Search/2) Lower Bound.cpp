/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> v, int e){
    int l = 0, r = v.size()-1;
    int ans = -1;
    while(l <= r){
        int m = l+(r-l)/2;
        if(v[m] < e){
            l = m+1;
        }
        else{
            ans = v[m];
            r = m-1;
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto &c: v){
        cin>>c;
    }
    int e; cin>>e;
    int i = binarySearch(v, e);
    if(i == n){
        cout<<-1<<endl;
    }
    else{
        cout<<i<<endl;
    }
    return 0;
}