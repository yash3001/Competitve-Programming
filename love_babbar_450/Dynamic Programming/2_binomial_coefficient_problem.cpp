// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        long long int dp[1001][1001];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<r+1; j++){
                if(j==0 || j==i){
                    dp[i][j] = 1;
                }
                if(j==1){
                    dp[i][j] = i;
                }
                if(j>i){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<r+1; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000007;
            }
        }
        
        return dp[n][r]%1000000007;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends