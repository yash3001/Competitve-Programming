/* @author -> IUseArchBTW */
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin>>s;
    int n = s.size();
    vector<string> vec;
    string st; cin>>st;
    int j = 0;
    unordered_map<string, int> starrmp;
    while(j < st.size()){
        string t;
        while(j < st.size() && st[j] != ','){
            t.push_back(st[j++]);
        }
        j++;
        vec.push_back(t);
        starrmp[t]++;
    }

    unordered_map<char, vector<int>> smp;
    for(int i=0; i<n; i++){
        if(smp.find(s[i]) == smp.end()){
            smp[s[i]] = vector<int>();
        }
        smp[s[i]].push_back(i);
    }

    string ans;
    for(const auto &p: smp){
        char ch = p.first;
        vector<int> ind = p.second;
        string s = vec[ind[0]];
        bool flag = true;
        for(int i=1; i<ind.size(); i++){
            if(s != vec[ind[i]]){
                flag = false;
                break;
            }
        }
        if(flag){
            if(ind.size() != starrmp[s]){
                flag = false;
            }
        }
        if(flag){
            ans.push_back(ch);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<(ans.size() == 0 ? "NA":ans)<<endl;
    return 0;
}