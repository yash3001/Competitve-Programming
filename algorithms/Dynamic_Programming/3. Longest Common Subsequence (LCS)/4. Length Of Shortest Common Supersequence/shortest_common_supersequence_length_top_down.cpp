/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int shortest_common_supersequence_length(string &s1, string &s2, int m, int n);

int dp[1001][1001];

int main(){
    cout<<"Enter the first string: ";
    string s1; cin>>s1;
    cout<<"Enter the second string: ";
    string s2; cin>>s2;
    cout<<"The length of the longest common supersequence is "<<s1.length()+s2.length()-shortest_common_supersequence_length(s1, s2, s1.length(), s2.length())<<endl;
    return 0;
}

int shortest_common_supersequence_length(string &s1, string &s2, int m, int n){

    for(int i=0; i<m+1; i++){
        dp[i][0] = 0;
    }
    for(int i=1; i<n+1; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[m][n];
}