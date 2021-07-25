// Problem link :- https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&problemStatus=unsolved&difficulty[]=2&page=1&query=category[]Dynamic%20ProgrammingproblemStatusunsolveddifficulty[]2page1category[]Dynamic%20Programming#


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isPalindrome(string str, int i, int j){
        while(i<j){
            if(str[i] != str[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
  
    void pp(string str, vector<string> &part, vector<vector<string>> &ans, int start, int n){
        if(start >= n){
            ans.push_back(part);
            return;
        }
        
        for(int i=start; i<n; i++){
            if(isPalindrome(str, start, i)){
                part.push_back(str.substr(start, i-start+1));
                pp(str, part, ans, i+1, n);
                part.pop_back();
            }
        }
    }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> part;
        pp(S, part, ans, 0, S.size());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends