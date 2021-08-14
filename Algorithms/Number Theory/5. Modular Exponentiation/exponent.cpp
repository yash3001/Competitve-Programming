/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int pow_(int x, int n){
    if(n == 0){
        return 1;
    }
    int y = pow_(x, n/2);
    y = y*y;
    if(n%2 == 1){
        y = y*x;
    }
    return y;
}

int main(){
    cout<<"A^B. Enter a and b: ";
    int a, b; cin>>a>>b;
    cout<<a<<"^"<<b<<" = "<<pow_(a, b)<<endl;
    return 0;
}