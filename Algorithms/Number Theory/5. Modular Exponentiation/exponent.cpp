/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int aToB(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b%2 == 0){
        int x = aToB(a, b/2);
        return x*x;
    }
    else{
        return aToB(a, b-1)*a;
    }
}

int main(){
    cout<<"A^B. Enter a and b: ";
    int a, b; cin>>a>>b;
    cout<<a<<"^"<<b<<" = "<<aToB(a, b)<<endl;
    return 0;
}