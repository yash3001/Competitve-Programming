/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int count(string s1, string s2, int n, int m);

int main(){
    cout<<"Enter the first string: ";
    string s1; cin>>s1;
    cout<<"Enter the second string: ";
    string s2; cin>>s2;
    cout<<"The number of times string 2 occurs in string 1 is: "<<count(s1, s2, s1.size(), s2.size())<<endl;
    return 0;
}

int count(string s1, string s2, int n, int m){
    if(m == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }

    if(s1[n-1] == s2[m-1]){
        return count(s1, s2, n-1, m-1)+count(s1, s2, n-1, m);
    }
    else{
        return count(s1, s2, n-1, m);
    }
}