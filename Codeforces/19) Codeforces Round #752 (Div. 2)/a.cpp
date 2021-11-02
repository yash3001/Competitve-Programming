/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

bool isE164(string s){
    int n = s.size();
    int i = 0;
    if(s[0] == '+'){
        if(s.size() == 1){
            return false;
        }
        n--;
        i++;
    }
    if(n > 15){
        return false;
    }
    if(s[i] == '0'){
        return false;
    }
    for(; i<n; i++){
        if(s[i]<'0' || s[i]>'9'){
            return false;
        }
    }
    return true;
}

bool isWhatsapp(string s){
    if(s.size()<10){
        return false;
    }
    string w1 = "whatsapp";
    string w2 = "WHATSAPP";
    for(int i=0; i<8; i++){
        if(s[i] != w1[i] && s[i] != w2[i]){
            return false;
        }
    }
    if(s[8] != ':'){
        return false;
    }
    string temp = s.substr(9, s.size()-9);
    return isE164(temp);
}

bool isMessenger(string s){
    if(s.size()<11){
        return false;
    }
    string w1 = "messenger";
    string w2 = "MESSENGER";
    for(int i=0; i<9; i++){
        if(s[i] != w1[i] && s[i] != w2[i]){
            return false;
        }
    }
    if(s[9] != ':'){
        return false;
    }
    string temp = s.substr(10, s.size()-10);
    return isE164(temp);
}

bool isWechat(string s){
    if(s.size()<8){
        return false;
    }
    string w1 = "wechat";
    string w2 = "WECHAT";
    for(int i=0; i<6; i++){
        if(s[i] != w1[i] && s[i] != w2[i]){
            return false;
        }
    }
    if(s[6] != ':'){
        return false;
    }
    string temp = s.substr(7, s.size()-7);
    if(temp.size()>248){
        return false;
    }
    for(int i=0; i<temp.size(); i++){
        if(temp[i]<'0' || temp[i]>'9'){
            if(temp[i]<'a' || temp[i]>'z'){
                if(temp[i]<'A' || temp[i]>'Z'){
                    if(temp[i] != '+' && temp[i] != '-' && temp[i] != '_' && temp[i] != '@' && temp[i] != '.'){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    string s; cin>>s;
    if(s.size() < 1 || s.size() > 258){
        cout<<"INVALID_ADDRESS";
    }
    else if(isE164(s)){
        cout<<"SMS";
    }
    else if(isWhatsapp(s)){
        cout<<"WHATSAPP";
    }
    else if(isMessenger(s)){
        cout<<"MESSENGER";
    }
    else if(isWechat(s)){
        cout<<"WECHAT";
    }
    else{
        cout<<"INVALID_ADDRESS";
    }
    return 0;
}