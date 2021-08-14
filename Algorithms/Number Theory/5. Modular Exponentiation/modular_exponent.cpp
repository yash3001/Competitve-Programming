/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int modpow(int x, int n, int m){
    if(n == 0){
        return 1;
    }
    int y = modpow(x, n/2, m);
    y = (y*y)%m;
    if(n%2 == 1){
        y = (y*x)%m;
    }
    return y;
}

int main(){
    cout<<"(A^B)%M. Enter a and b and m: ";
    int a, b, m; cin>>a>>b>>m;
    cout<<"("<<a<<"^"<<b<<")%"<<m<<" = "<<modpow(a, b, m)<<endl;
    return 0;
}