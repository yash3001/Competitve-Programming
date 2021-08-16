/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n; cin>>n;
    cout<<"Enter the ith location from the right (indexing starts at 0): ";
    int i; cin>>i;
    if( (n>>i)&1 ){
        cout<<"The bit is set";
    }
    else{
        cout<<"The bit is unset";
    }
    cout<<endl;
    return 0;
}