/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin>>s;
    stack<string> st;
    int i=0;
    while(i<s.size()){
        if(s.at(i) == '['){
            st.push("[");
            i++;
            continue;
        }
        if(isdigit(s.at(i))){
            string n;
            while(isdigit(s.at(i)) && i<s.size()){
                n += s.at(i);
                i++;
            }
            st.push(n);
            continue;
        }
        if(isalpha(s.at(i))){
            string a;
            while(isalpha(s.at(i)) && i<s.size()){
                a += s.at(i);
                i++;
            }
            st.push(a);
            continue;
        }

        if(s.at(i) == ']'){
            string str;
            while(st.top() != "["){
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());

            st.pop();
            string n = st.top();
            st.pop();

            int num = stoi(n);

            string temp;
            while(num){
                temp += str;
                num--;
            }
            st.push(temp);
            i++;
            continue;
        }
    }
    string ans = st.top();

    for(auto &c: ans){
        if(c != 'z'){
            c += 1;
        }
        else{
            c = 'a';
        }
    }
    cout<<ans<<endl;
    return 0;
}