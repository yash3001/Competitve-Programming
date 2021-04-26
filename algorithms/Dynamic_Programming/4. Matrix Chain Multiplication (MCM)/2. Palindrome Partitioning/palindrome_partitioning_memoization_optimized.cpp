/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int palindrome_partitioning(string &s, int i, int j);

int dp[1001][1001];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the string: ";
    string s; cin>>s;
    cout<<"The minimum number of partitioning can needs to be done is "<<palindrome_partitioning(s, 0, s.size()-1)<<endl;
    return 0;
}

int palindrome_partitioning(string &s, int i, int j){
    if(i>=j){
        return dp[i][j]=0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    string t=s.substr(i, j-i+1);
    reverse(t.begin(), t.end());
    if(t==s.substr(i, j-i+1)){
        return dp[i][j]=0;
    }

    int min=INT_MAX;
    for(int k=i; k<j; k++){
        int left, right;
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else{
            left = palindrome_partitioning(s, i, k);
        }

        if(dp[k+1][j] != -1){
            right = dp[k+1][j];
        }
        else{
            right = palindrome_partitioning(s, k+1, j);
        }

        int temp = left + right + 1; 
        if(temp < min){
            min = temp;
        }
    }
    return dp[i][j]=min;
}