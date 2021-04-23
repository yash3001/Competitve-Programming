/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int longest_common_substring_length(string &s1, string &s2, int m, int n, int count);

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the first string: ";
    string s1; cin>>s1;
    cout<<"Enter the second string: ";
    string s2; cin>>s2;
    cout<<"The length of the longest common substring is "<<longest_common_substring_length(s1, s2, s1.length(), s2.length(), 0)<<endl;
    return 0;
}

int longest_common_substring_length(string &s1, string &s2, int m, int n, int count){
    if(m==0 ||  n==0){
        return dp[m][n]=count;
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    if(s1[m-1]==s2[n-1]){
        return dp[m][n] = longest_common_substring_length(s1, s2, m-1, n-1, 1+count);
    }
    else{
        return dp[m][n] = max(count, max(longest_common_substring_length(s1, s2, m-1, n, 0), longest_common_substring_length(s1, s2, m, n-1, 0)));
    }
}