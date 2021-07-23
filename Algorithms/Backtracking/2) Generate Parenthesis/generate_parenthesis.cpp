// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int open, int close, string str, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(str);
        }
        else{
            if(open != 0){
                string str1 = str;
                str1.push_back('(');
                solve(open-1, close, str1, ans);
            }
            if(close > open){
                string str1 = str;
                str1.push_back(')');
                solve(open, close-1, str1, ans);
            }
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> ans;
        string str;
        int open=n, close=n;
        solve(open, close, str, ans);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends