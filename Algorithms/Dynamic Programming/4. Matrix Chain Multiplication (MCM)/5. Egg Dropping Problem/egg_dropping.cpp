// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e, int f, vector<vector<int>> &dp){
        if(f == 0 || f == 1){
            return dp[e][f] = f;
        }
        if(e == 1){
            return dp[e][f] = f;
        }
        
        if(dp[e][f] != -1){
            return dp[e][f];
        }
        
        int ans = INT_MAX;
        
        for(int k=1; k<=f; k++){
            
            int left, right;
            
            if(dp[e-1][k-1] != -1){
                left = dp[e-1][k-1];
            }
            else{
                left = solve(e-1, k-1, dp);
            }
            
            if(dp[e][f-k] != -1){
                right = dp[e][f-k];
            }
            else{
                right = solve(e, f-k, dp);
            }
            
            int t = 1+max(left, right);
            ans = min(ans, t);
        }
        
        return dp[e][f] = ans;
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(n, k, dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends