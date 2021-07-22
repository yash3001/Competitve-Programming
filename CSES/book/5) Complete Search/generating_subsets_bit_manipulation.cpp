/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

void generateSubsets(int n){
    for(int i=0; i<(1<<n); i++){
        vector<int> subs;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                subs.push_back(j);
            }
        }
        for(int i=0; i<subs.size(); i++){
            cout<<subs.at(i)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n; cin>>n;
    generateSubsets(n);
    return 0;
}