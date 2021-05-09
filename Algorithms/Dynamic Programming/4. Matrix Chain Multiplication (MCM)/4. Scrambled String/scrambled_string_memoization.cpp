/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool scrambled_string(string s1, string s2);

unordered_map<string, int> mp;

int main(){
    cout<<"Enter the first string: ";
    string s1; cin>>s1;
    cout<<"Enter the second string: ";
    string s2; cin>>s2;
    if(scrambled_string(s1, s2)){
        cout<<"Second string is scrambled"<<endl;
    }
    else{
        cout<<"Second string is not scrambled"<<endl;
    }
    return 0;
}

bool scrambled_string(string s1, string s2){

    string key = s1 + " " + s2;

    if(s1==s2){
        return mp[key]=true;
    }
    if(s1.size() != s2.size()){
        return mp[key]=false;
    }
    if(s1.length() <= 1){
        return mp[key]=false;
    }

    if(mp[key]){
        return mp[key];
    }

    int n = s1.length();
    bool check = false;
    for(int k=1; k<n; k++){
        check = ( scrambled_string(s1.substr(0, k), s2.substr(0, k)) && scrambled_string(s1.substr(k, n-k), s2.substr(k, n-k)) ) || ( scrambled_string(s1.substr(0, k), s2.substr(n-k, k)) && scrambled_string(s1.substr(k, n-k), s2.substr(0, n-k)) );
        if(check == true){
            break;
        }
    }
    return mp[key]=check;
}