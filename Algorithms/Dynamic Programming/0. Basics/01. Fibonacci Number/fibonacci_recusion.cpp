/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n){
    if(n == 1 ){
        return 0;
    }
    if(n == 2 ){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    // cout<<"Enter the n for nth fibonacci number: ";
    int n; cin>>n;
    cout<<fibonacci(n);
    return 0;
}