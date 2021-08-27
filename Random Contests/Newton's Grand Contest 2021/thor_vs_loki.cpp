#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        long long a, b, z; cin>>a>>b>>z;
        cout<<max(z-a, z-b)<<endl;
    }

    return 0;
}