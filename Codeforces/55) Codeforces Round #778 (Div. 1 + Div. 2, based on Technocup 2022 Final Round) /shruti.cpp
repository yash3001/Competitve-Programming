/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<string> solve(string s, string t){
    vector<string> l1, l2, ans;
    string tt;
    for(int i=0; i<t.size(); i++){
        if(t[i] == ' '){
            l2.push_back(tt);
            tt = "";
        }
        else{
            tt.push_back(t[i]); 
        }
    }
    if(tt != ""){
        l2.push_back(tt);
    }
    tt = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            l1.push_back(tt);
            tt = "";
        }
        else{
            tt.push_back(s[i]); 
        }
    }
    if(tt != ""){
        l1.push_back(tt);
    }
    int j = 0;
    int i = 0;
    for(i=0; i<l1.size() && j<l2.size(); i++){
        if(l1[i] != l2[j]){
            ans.push_back(l1[i]);
            j++;
        }
    }
    while(i < l1.size()){
        ans.push_back(l1[i]);
        i++;
    }
    return ans;
}

int main(){
    return 0;
}