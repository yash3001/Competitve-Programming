#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    string infix{}, postfix{}; cin>>infix;
    vector<char> st{'('};
    for(int i=0; i<n; i++){
        if( infix.at(i)=='^' || infix.at(i)=='('){
            st.push_back(infix.at(i));
        }
        else if(infix.at(i)=='+' || infix.at(i)=='-'){
            if(st.back()=='*' || st.back()=='/' || st.back()=='^'){
                while(st.back() != '('){
                    postfix += st.back();
                    st.pop_back();
                }
                st.pop_back();
            }
            st.push_back(infix.at(i));
        }
        else if(infix.at(i)=='*' || infix.at(i)=='/'){
            if(st.back()=='^'){
                while(st.back() != '('){
                    postfix += st.back();
                    st.pop_back();
                }
                st.pop_back();
            }
            st.push_back(infix.at(i));
        }
        else if(infix.at(i)==')'){
            while(st.back() != '('){
                postfix += st.back();
                st.pop_back();
            }
            st.pop_back();
        }
        else{
            postfix += infix.at(i);
        }
    }
    while(st.size() != 0){
        if(st.back()=='('){
            st.pop_back();
            continue;
        }
        postfix += st.back();
        st.pop_back();
    }
    cout << postfix << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}