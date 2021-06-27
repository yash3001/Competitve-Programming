// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph
    bool dfs(int n, int p, vector<int> &visited, vector<int> adj[]){
        visited.at(n) = 1;
        for(int i=0; i<adj[n].size(); i++){
            if( !visited.at(adj[n].at(i)) ){
                if(dfs(adj[n].at(i), n, visited, adj)){
                    return true;
                }
            }
            else{
                if(adj[n].at(i) != p){
                    return true;
                }
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> visited(V, 0);
        bool ans = false;
	    for(int i=0; i<V; i++){
	        if(!visited.at(i)){
	            ans = ans || dfs(i, i, visited, adj);
	        }
	    }
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
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends