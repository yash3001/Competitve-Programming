// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void dfs(int n, vector<vector<int>> &adj, vector<int> &visited){
        visited.at(n) = 1;
        for(const auto &c: adj.at(n)){
            if(!visited.at(c)){
                dfs(c, adj, visited);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<vector<int>> adj(27);
        unordered_map<int, int> mp;
        vector<int> v;
        vector<int> indeg(27, 0), outdeg(27, 0);
        for(const auto &s: A){
            int a = s.at(0)-'a';
            int b = s.at(s.size()-1)-'a';
            adj.at(a).push_back(b);
            indeg.at(a)++;
            outdeg.at(b)++;
            if(!mp[a]){
                mp[a]++;
                v.push_back(a);
            }
            if(!mp[b]){
                mp[b]++;
                v.push_back(b);
            }
        }
        int count{};
        vector<int> visited(27, 0);
        for(const auto &n: v){
            if(!visited.at(n)){
                dfs(n, adj, visited);
                count++;    
            }
        }
        if(count > 1){
            return 0;
        }
        for(const auto &n: v){
            if(indeg.at(n) != outdeg.at(n)){
                return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends