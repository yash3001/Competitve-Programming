/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int boolean_parenthesization(string s, int i, int j, int isTrue);

int main(){
    cout<<"Enter the string: ";
    string s; cin>>s;
    cout<<"The number of ways of parenthesization such that the expression evaluates to true are "<<boolean_parenthesization(s, 0, s.size()-1, 1)<<endl;
    return 0;
}

int boolean_parenthesization(string s, int i, int j, int isTrue){
    if(i>j){
        return false;
    }
    if(i==j){
        if(isTrue){
            return s[i]=='T' || s[i]=='t';
        }
        else{
            return s[i]=='F' || s[i]=='f';
        }
    }
    int count{};
    for(int k=i+1; k<j; k=k+2){
        int left_t = boolean_parenthesization(s, i, k-1, 1);
        int left_f = boolean_parenthesization(s, i, k-1, 0);
        int right_t = boolean_parenthesization(s, k+1, j, 1);
        int right_f = boolean_parenthesization(s, k+1, j, 0);
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
    return count;
}