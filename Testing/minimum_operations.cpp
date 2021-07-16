// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int lcs(int a[], int b[], int n, int m, vector<vector<int>> &dp){
        // if(n == 0 || m == 0){
        //     return dp[n][m]=0;
        // }
        // if(dp[n][m] != -1){
        //     return dp[n][m];
        // }
        // if(a[n-1] == b[m-1]){
        //     return dp[n][m] = 1+lcs(a, b, n-1, m-1, dp);
        // }
        // else{
        //     return dp[n][m] = max(lcs(a, b, n-1, m, dp), lcs(a, b, n, m-1, dp));
        // }
        for(int i=0; i<n+1; i++){
            dp.at(i).at(0) = 0;
        }
        for(int j=0; j<m+1; j++){
            dp.at(0).at(j) = 0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(a[i-1] == b[j-1]){
                    dp.at(i).at(j) = 1+dp.at(i-1).at(j-1);
                }
                else{
                    dp.at(i).at(j) = max(dp.at(i).at(j-1), dp.at(i-1).at(j));
                }
            }
        }
        return dp.at(n).at(m);
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<vector<int>> dp(N+1, vector<int>(M+1, -1));
        int n = lcs(A, B, N, M, dp);
        return (N+M-2*n);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends