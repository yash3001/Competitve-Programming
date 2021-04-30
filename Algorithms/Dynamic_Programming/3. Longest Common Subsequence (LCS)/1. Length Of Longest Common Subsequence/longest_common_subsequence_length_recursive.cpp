/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int longest_common_subsequence_length(string &s1, string &s2, int m, int n);

int main(){
    cout<<"Enter the first string: ";
    string s1; cin>>s1;
    cout<<"Enter the second string: ";
    string s2; cin>>s2;
    cout<<"The length of the longest common subsequence is "<<longest_common_subsequence_length(s1, s2, s1.length(), s2.length())<<endl;
    return 0;
}

int longest_common_subsequence_length(string &s1, string &s2, int m, int n){
    if(m==0 ||  n==0){
        return 0;
    }
    if(s1[m-1]==s2[n-1]){
        return 1+longest_common_subsequence_length(s1, s2, m-1, n-1);
    }
    else{
        return max(longest_common_subsequence_length(s1, s2, m-1, n), longest_common_subsequence_length(s1, s2, m, n-1));
    }
}