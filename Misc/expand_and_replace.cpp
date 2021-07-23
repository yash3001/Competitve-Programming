/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, ans;
    stack<int> st;
    stack<string> sstr;
    cin>>s;
    int i=0;
    while(i<s.size()){
        // if(s.at(i)>='0' && s.at(i)<='9' || s.at(i)=='['){
        if(s.at(i)!=']'){
            st.push(s.at(i));
            i++;
        }
        // while(s.at(i)>='a' && s.at(i)<='z'){
        //     ans+=s.at(i);
        //     i++;
        // }
        if(s.at(i)==']'){
            string z;
            while(st.top()!='['){
                if(st.top()>='a' && st.top()<='z'){
                    z = (char)st.top()+z;
                }
                st.pop();
            }
            st.pop();
            int n=st.top()-'0';
            st.pop();
            string t = z;
            for(int i=1; i<n; i++){
                z+=t;
            }
            sstr.push(z);
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}