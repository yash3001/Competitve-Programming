// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    int n, m;
    
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    n = grid.size();
	    m = grid.at(0).size();
	    
	    queue<pair<int, int>> q1;
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	    
	    int xadd[4]={-1, 0, 1, 0};
	    int yadd[4]={0, 1, 0, -1};
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid.at(i).at(j) == 0){
	                q1.push({i, j});    
	            }
	        }
	    }
	    
	    while(!q1.empty()){
	        int x = q1.front().first;
	        int y = q1.front().second;
	        q1.pop();
	        
	        int d = 0;
	        vector<vector<int>> dist(n, vector<int>(m, 0));
	        
	        queue<pair<int, int>> q2;
	        q2.push({x, y});
	        
	        while(!q2.empty()){
	            int a = q2.front().first;
	            int b = q2.front().second;
	            q2.pop();
	            
	            for(int k=0; k<4; k++){
	                int new_x = a+xadd[k];
	                int new_y = b+yadd[k];
	                
	                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m){
	                    if(grid.at(new_x).at(new_y) == 0){
	                        dist.at(new_x).at(new_y) = dist.at(a).at(b)+1;
	                    }
	                    else{
	                        ans.at(x).at(y) = dist.at(a).at(b)+1;
	                        break;
	                    }   
	                }
	            }
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends