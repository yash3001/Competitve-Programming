/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    string word; cin>>word;
    string para; getline(cin>>ws, para);
    string temp, ans;
    map<string, int> mp;
    for(int i=0; i<para.size(); i++){
        if(para[i] == ' '){
            if(temp == word){
                ans += word;
            }
            else{
                ans += to_string(mp[temp]);
                mp[temp]++;
            }
            ans += " ";
            temp = "";
        }
        else{
            temp.push_back(para[i]);
        }
    }
    if(temp == word){
        ans += word;
    }
    else{
        ans += to_string(mp[temp]);
    }
    cout<<ans<<endl;
    return 0;
}