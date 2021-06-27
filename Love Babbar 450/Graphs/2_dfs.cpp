// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(vector<int> adj[], vector<int> &visited, vector<int> &ans, int n){
	    visited.at(n) = 1;
	    ans.push_back(n);
	    for(const auto &c: adj[n]){
	        if(!visited.at(c)){
	            dfs(adj, visited, ans, c);
	        }
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> visited(V, 0), ans;
	    dfs(adj, visited, ans, 0);
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends