/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    cout<<"Enter a and b: ";
    int a, b; cin>>a>>b;
    cout<<"GCD: "<<gcd(a, b)<<endl;
    return 0;
}