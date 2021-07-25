/* @author -> gamma30 */
#include <bits/stdc++.h>

using namespace std;

int palindrome_partitioning(string &s, int i, int j);

int main(){
    cout<<"Enter the string: ";
    string s; cin>>s;
    cout<<"The minimum number of partitioning that needs to be done is "<<palindrome_partitioning(s, 0, s.size()-1)<<endl;
    return 0;
}

int palindrome_partitioning(string &s, int i, int j){
    if(i>=j){
        return 0;
    }

    string t=s.substr(i, j-i+1);
    reverse(t.begin(), t.end());
    if(t==s.substr(i, j-i+1)){
        return 0;
    }

    int min=INT_MAX;
    for(int k=i; k<j; k++){
        int temp = palindrome_partitioning(s, i, k) + palindrome_partitioning(s, k+1, j) + 1;
        if(temp < min){
            min = temp;
        }
    }
    return min;
}