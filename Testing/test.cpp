#include<iostream>

using namespace std;

int main(){
    int i = 1, j=2;
    i=j++<=1;
    cout<<i<<" "<<j<<endl;
    return 0;
}