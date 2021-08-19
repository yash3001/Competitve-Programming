/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = -1;
    int count=0;
    while(n != 1){
        if(n&1){
            count++;
        }
        n >>= 1;
    }
    cout<<count<<endl;
    return 0;
}