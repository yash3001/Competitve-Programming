/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n; cin>>n;

    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            cout<<"The number is not a prime number"<<endl;
            return 0;
        }
    }

    cout<<"The number is a prime number"<<endl;

    return 0;
}