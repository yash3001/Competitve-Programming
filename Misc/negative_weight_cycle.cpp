// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(int n, vector<vector<int>> &adj, vector<int> &visited){
        visited.at(n) = 1;
        for(const auto &c: adj.at(n)){
            if(!visited.at(c))
                dfs(c, adj, visited);
        }
    }
    
    void bellman_ford(int s, vector<vector<int>> edges, vector<int> &dist1, vector<int> &dist2, int n){
        dist1.at(s) = dist2.at(s) = 0;
        for(int k=0; k<n; k++){
            for(const auto &v: edges){
                int a = v.at(0);
                int b = v.at(1);
                int w = v.at(2);
                
                if(dist1.at(a) != INT_MAX){
                    if(dist1.at(a) + w < dist1.at(b)){
                        dist1.at(b) = dist1.at(a) + w;
                        dist2.at(b) = dist2.at(a) + w;
                    }
                }
            }
        }
        for(const auto &v: edges){
            int a = v.at(0);
            int b = v.at(1);
            int w = v.at(2);
            
            if(dist2.at(a) != INT_MAX){
                if(dist2.at(a) + w < dist2.at(b)){
                    dist2.at(b) = dist2.at(a) + w;
                }
            }
        }
    }
    
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>  visited(n, 0);
	    vector<vector<int>> adj(n);
	    for(const auto &v: edges){
	        adj.at(v.at(0)).push_back(v.at(1));
	    }
	    for(int i=0; i<n; i++){
	        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
	        if(!visited.at(i)){
	            dfs(i, adj, visited);
	            bellman_ford(i, edges, dist1, dist2, n);
	            for(int i=0; i<n; i++){
	                if(dist1.at(i) != dist2.at(i)){
	                    return 1;
	                }
	            }
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends