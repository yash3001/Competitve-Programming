#include<iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> bits;
    while(n>0){
        bits.push_back(n&1);
        n>>=1;
    }
    for(auto it=bits.rbegin(); it!=bits.rend(); it++){
        cout<<*it;
    }
    cout<<endl;
    return 0;
}