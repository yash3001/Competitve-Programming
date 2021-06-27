// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(int n, vector<int> &visited, vector<int> adj[]){
        cout<<n<<endl;
	    visited.at(n) = 1;
	    for(const auto &c: adj[n]){
	        if(visited.at(c)){
	            return true;
	        }
	        if(dfs(c, visited, adj)){
                return true;
            };
	    }
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	    vector<int> visited(V, 0);
	    return dfs(0, visited, adj);
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends