/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n; cin>>n;
    int cnt{};
    while(n>0){
        if(n&1){
            cnt++;
        }
        n>>1;
    }
    cout<<cnt<<endl;
    return 0;
}