/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

string longest_common_subsequence(string &s1, string &s2, int m, int n);

int dp[1001][1001];

int main(){
    cout<<"Enter the first string: ";
    string s1; cin>>s1;
    cout<<"Enter the second string: ";
    string s2; cin>>s2;
    cout<<"The longest common subsequence is "<<longest_common_subsequence(s1, s2, s1.length(), s2.length())<<endl;
    return 0;
}

string longest_common_subsequence(string &s1, string &s2, int m, int n){
    for(int i=0; i<m+1; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<n+1; i++){
        dp[0][i] = 0;
    }
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i=m, j=n;
    string ans;
    while(i != 0 && j != 0){
        if(s1[i-1]==s2[j-1]){
            ans = s1[i-1]+ans;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    return ans;
}