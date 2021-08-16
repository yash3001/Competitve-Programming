/* @author -> gamma30 */

//This program if there are x set bits in n, then the while loop only runs x times
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n; cin>>n;
    int cnt{};
    while(n>0){
        cnt++;
        n = n & (n-1);
    }
    cout<<cnt<<endl;
    return 0;
}