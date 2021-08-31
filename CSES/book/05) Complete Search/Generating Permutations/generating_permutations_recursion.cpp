/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

vector<int> perms;
vector<int> chosen(1001, 0);
int n;

void generatePermuations(){
    if(perms.size() == n){
        for(int i=0; i<perms.size(); i++){
            cout<<perms.at(i)<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=0; i<n; i++){
            if(chosen.at(i)){
                continue;
            }
            chosen.at(i) = 1;
            perms.push_back(i);
            generatePermuations();
            chosen.at(i) = 0;
            perms.pop_back();
        }
    }
}

int main(){
    cin>>n;
    generatePermuations();
    return 0;
}