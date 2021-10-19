/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int count = 0;
    for(int i=0; i<5; i++){
        count = (count<<3) + arr[i];
    }
    cout<<count;
    return 0;
}