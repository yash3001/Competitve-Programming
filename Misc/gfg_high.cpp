// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	
	int count(vector<int> coins, int sum, int n, vector<vector<int>> &dp){
	   // if(sum == 0){
	   //     return dp[n][sum] = 0; 
	   // }
	   // else if(n == 0){
	   //     return dp[n][sum] = INT_MAX-1;
	   // }
	    
	   // if(dp[n][sum] != -1){
	   //     return dp[n][sum];
	   // }
	    
	   // if(n == 1){
	   //     if(sum%nums[0] == 0){
	   //         return dp[n][sum] = sum/nums[0];
	   //     }
	   //     else{
	   //         return dp[n][sum] = INT_MAX-1;
	   //     }
	   // }
	    
	   // if(nums[n-1]<=sum){
	   //     return min(1+count(nums, sum-nums[n-1], n, dp), count(nums, sum, n-1, dp));
	   // }
	   // else{
	   //     return count(nums, sum, n-1, dp);
	   // }
	    
        for(int i=0; i<sum+1; i++){
            dp[0][i] = INT_MAX-1;
        }
        for(int i=1; i<n+1; i++){
            dp[i][0] = 0;
        }
        for(int i=1; i<sum+1; i++){
            if(i%coins[0]==0)
                dp[1][i] = i/coins[0];
            else{
                dp[1][i] = INT_MAX-1;
            }
        }
        for(int i=2; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1]<=sum){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
	}
	
	
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    vector<vector<int>> dp(nums.size()+1, vector<int>(amount+1, -1));
	    int ans = count(nums, amount, nums.size(), dp);
	    return (ans == INT_MAX || ans == INT_MAX-1) ? -1: ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends