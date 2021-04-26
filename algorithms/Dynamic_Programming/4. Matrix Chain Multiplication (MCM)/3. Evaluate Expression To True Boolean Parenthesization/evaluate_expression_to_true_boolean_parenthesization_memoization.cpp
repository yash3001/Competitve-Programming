/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int boolean_parenthesization(string s, int i, int j, int isTrue);

int dp[1001][1001][2];

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<"Enter the string: ";
    string s; cin>>s;
    cout<<"The number of ways of parenthesization such that the expression evaluates to true are "<<boolean_parenthesization(s, 0, s.size()-1, 1)<<endl;
    return 0;
}

int boolean_parenthesization(string s, int i, int j, int isTrue){
    if(i>j){
        return dp[i][j][isTrue]=false;
    }
    if(i==j){
        if(isTrue){
            return dp[i][j][isTrue]=s[i]=='T' || s[i]=='t';
        }
        else{
            return dp[i][j][isTrue]=s[i]=='F' || s[i]=='f';
        }
    }

    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    int count{};
    for(int k=i+1; k<j; k=k+2){

        int left_t;
        if(dp[i][k-1][1] != -1){
            left_t = dp[i][k-1][1];
        }
        else{
            left_t = boolean_parenthesization(s, i, k-1, 1);
        }
        int left_f;
        if(dp[i][k-1][0] != -1){
            left_f = dp[i][k-1][0];
        }
        else{
            left_f = boolean_parenthesization(s, i, k-1, 0);
        }
        int right_t;
        if(dp[k+1][j][1] != -1){
            right_t = dp[k+1][j][1];
        }
        else{
            right_t = boolean_parenthesization(s, k+1, j, 1);
        }
        int right_f;
        if(dp[k+1][j][0] != -1){
            right_f = dp[k+1][j][0];
        }
        else{
            right_f = boolean_parenthesization(s, k+1, j, 0);
        }

        if(s[k]=='|'){
            if(isTrue)
                count += left_t*right_t + left_t*right_f + left_f*right_t;
            else
                count += left_f*right_f;
        }
        else if(s[k]=='&'){
            if(isTrue)
                count += left_t*right_t;
            else
                count += left_f*right_t + left_t*right_f + left_f*right_f;
        }
        else if(s[k]=='^'){
            if(isTrue)
                count += left_t*right_f + left_f*right_t;
            else
                count += left_t*right_t + left_f*right_f;
        }
    }
    return dp[i][j][isTrue]=count;
}