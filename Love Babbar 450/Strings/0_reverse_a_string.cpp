/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin>>s;
    for(int i=0; i<s.size()/2; i++){
        swap(s.at(i), s.at(s.size()-i-1));
    }
    cout<<s<<endl;
    return 0;
}